// TrinomialTree.cpp

#include "TrinomialTree.h"
#include <cmath>
#include <algorithm>

SimpleTrinomialTree::SimpleTrinomialTree(double Spot_, const Parameters& r_, double Volatility_, unsigned long Steps_, double Time_)
: Spot(Spot_), r(r_), Volatility(Volatility_), Steps(Steps_), Time(Time_), TreeBuilt(false) {
}

void SimpleTrinomialTree::BuildTree() {
    TreeBuilt = true;
    double dt = Time / Steps;
    double u = exp(Volatility * sqrt(2 * dt));
    double d = 1 / u;
    double pu = 1.0 / 6.0 + (r.Integral(0, dt) / (Volatility * sqrt(dt))) / 6.0;
    double pd = 1.0 / 6.0 - (r.Integral(0, dt) / (Volatility * sqrt(dt))) / 6.0;
    double pm = 2.0 / 3.0;
    
    TheTree.resize(Steps + 1);
    double initialLogSpot = log(Spot);

    for (unsigned long i = 0; i <= Steps; ++i) {
        TheTree[i].resize(i + 1);
        for (long j = -static_cast<long>(i); j <= static_cast<long>(i); j+=2) {
            double thisSpot = exp(initialLogSpot + j * Volatility * sqrt(dt));
            TheTree[i][(j + i)/2].resize(3);
            TheTree[i][(j + i)/2][0] = thisSpot * d; // Down
            TheTree[i][(j + i)/2][1] = thisSpot;     // Middle
            TheTree[i][(j + i)/2][2] = thisSpot * u; // Up
        }
    }

    Discounts.resize(Steps);
    for (unsigned long i = 0; i < Steps; ++i) {
        Discounts[i] = exp(-r.Integral(i * dt, (i + 1) * dt));
    }
}

double SimpleTrinomialTree::GetThePrice(const TreeProduct& TheProduct) {
    if (!TreeBuilt) BuildTree();
    std::vector<double> Prices(Steps + 1), Values(Steps + 1);

    for (unsigned int i = 0; i <= Steps; ++i) {
        Prices[i] = TheTree[Steps][i][1];
        Values[i] = TheProduct.FinalPayOff(Prices[i]);
    }

    for (long i = Steps - 1; i >= 0; --i) {
        for (unsigned long j = 0; j <= i; ++j) {
            double Spot = TheTree[i][j][1];
            Values[j] = (pu * Values[j + 1] + pm * Values[j] + pd * Values[j - 1]) * Discounts[i];
            Values[j] = TheProduct.PreFinalValue(Spot, i, Values[j]);
        }
    }
    return Values[0];
}