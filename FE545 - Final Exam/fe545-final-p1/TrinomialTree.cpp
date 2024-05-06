//
//  BinomialTree.cpp
//
//  Created by Steve Yang on 10/12/23.
//
//

#include "TrinomialTree.h"
#include "Arrays.h"
#include <iostream>
#include <cmath>

// the basic math functions should be in namespace std but aren't in VCPP6
#if !defined(_MSC_VER)
using namespace std;
#endif

SimpleTrinomialTree::SimpleTrinomialTree(double Spot_,
                                       const Parameters& r_,
                                       const Parameters& d_,
                                       double Volatility_,
                                       unsigned long Steps_,
                                       double Time_)
                                       : Spot(Spot_),
                                         r(r_),
                                         d(d_),
                                         Volatility(Volatility_),
                                         Steps(Steps_),
                                         Time(Time_),
                                         Discounts(Steps)
{
    TreeBuilt=false;
}

void SimpleTrinomialTree::BuildTree()
{
    TreeBuilt = true;
    TheTree.resize(Steps+1);

    double dt = Time/Steps;
    double u = exp(Volatility * sqrt(2 * dt));
    double u_inverse = 1/u;

    for (unsigned long i=0; i <=Steps; i++)
    {

        TheTree[i].resize(2*i+1); // no. of nodes at each step

        //double thisTime = (i*Time)/Steps;

        for (long j = -static_cast<long>(i), k=0; j <= static_cast<long>(i); j=j+1,k++)
        {
            // TODO:
            TheTree[i][k].first = Spot * pow(u,k) * pow(u_inverse,i);
        }
    }

   
    for (unsigned long l=0; l <Steps; l++)
    {
        Discounts[l] = exp(- r.Integral(l*Time/Steps,(l+1)*Time/Steps));
    }
}

double SimpleTrinomialTree::GetThePrice(const TreeProducts& TheProduct)
{
    if (!TreeBuilt)
        BuildTree();

    if (TheProduct.GetFinalTime() != Time)
        throw("mismatched product in Simple Trinomial Tree");

    for (long j = -static_cast<long>(Steps), k=0; j <=static_cast<long>( Steps); j++,k++){
        TheTree[Steps][k].second = TheProduct.FinalPayOff(TheTree[Steps][k].first);
    }

    // Risk Neutral Probability Calculations
    double delta_t = Time/Steps;

    double p_exp = Volatility * sqrt(0.5 * delta_t);
    double p_den = exp(p_exp) - exp(-p_exp);

    double p_num_d = exp(p_exp) - exp(0.5*(r.Integral(0,delta_t) - d.Integral(0,delta_t)));
    double p_num_u = exp(0.5*(r.Integral(0,delta_t)-d.Integral(0,delta_t))) - exp(-p_exp);

    double p_u = p_num_u/p_den;
    double p_d = p_num_d/p_den;
    p_u *= p_u;
    p_d *= p_d;
    double p_m = 1 - p_u - p_d;

    for (unsigned long i=1; i <= Steps; i++)
    {
        unsigned long index = Steps-i;
        double ThisTime = index*Time/Steps;

   
        for (long j = -static_cast<long>(index), k=0; j <= static_cast<long>(index); j++,k++)
        {
            double Spot = TheTree[index][k].first;
            double futureDiscountedValue =
                    Discounts[index]*(TheTree[index+1][k].second * p_d
                            +TheTree[index+1][k+1].second * p_m
                            +TheTree[index+1][k+2].second * p_u);
            TheTree[index][k].second = TheProduct.PreFinalValue(Spot,ThisTime,futureDiscountedValue);
        }
    }


    return TheTree[0][0].second;
}
