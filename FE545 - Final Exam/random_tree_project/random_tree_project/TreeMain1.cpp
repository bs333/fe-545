//
//  main.cpp
//  ch8_trees
//
//  Created by Steve Yang on 10/12/21.
//

/*
requires
    Arrays.cpp
    BinomialTree.cpp
    BlackScholesFormulas.cpp
    Normals.cpp
    Parameters.cpp
    PayOff3.cpp
    PayOffBridge.cpp
    PayOffForward.cpp
    TreeAmerican.cpp
    TreeEuropean.cpp
    TreeMain.cpp
    TreeProducts.cpp
  */
#include <iostream>
#include "BinomialTree.h"
#include "TrinomialTree.h"
#include "TreeAmerican.h"
#include "TreeEuropean.h"
#include "BlackScholesFormulas.h"

using namespace std;
#include <cmath>
int main()
{

    double Expiry = 1;
    double Strike = 50;
    double Spot = 50;
    double Vol = 0.3;
    double r = 0.05;
    double d = 0.08;
    double b = 3;
    double n = 100;
    unsigned long Steps;

    cout << "\nNumber of steps\n";
    cin >> Steps;

    // Create a PayOff objects for Call and Put Options
    PayOffCall thePayOffCall(Strike);
	PayOffPut thePayOffPut(Strike);

    // Create a risk free rate ParametersConstant
    ParametersConstant rParam(r);

    // Create a dividend ParametersConstant
    ParametersConstant dParam(d);

    // Create a TreeEuropean object
	TreeEuropean TreeEuroCall(Expiry,thePayOffCall);
	TreeEuropean TreeEuroPut(Expiry, thePayOffPut);

    // Create a TreeAmerican object
	TreeAmerican TreeAmerCall(Expiry, thePayOffCall);
	TreeAmerican TreeAmerPut(Expiry, thePayOffPut);

    // Create one BinomialTree object
	SimpleBinomialTree BinomTree(Spot,rParam,dParam,Vol,Steps, Expiry);

	// Create one TrinomialTree object
	SimpleTrinomialTree TrinomTree(Spot,rParam,dParam,Vol,Steps,Expiry);

	double americanCallPriceBi = 0.0;
	double americanPutPriceBi = 0.0;
	double americanCallPriceTri = 0.0;
	double americanPutPriceTri = 0.0;
    
	// Calculate American Option price
	americanCallPriceBi = BinomTree.GetThePrice(TreeAmerCall);
	americanPutPriceBi = BinomTree.GetThePrice(TreeAmerPut);
	americanCallPriceTri = TrinomTree.GetThePrice(TreeAmerCall);
	americanPutPriceTri = TrinomTree.GetThePrice(TreeAmerPut);


    std::cout << "Binomial Tree: "<< "American Call Option Price =" << to_string(americanCallPriceBi) << endl;
    std::cout << "Binomial Tree: "<< "American Put Option Price =" <<to_string(americanPutPriceBi) << endl;

    std::cout << "Trinomial Tree: "<< "American Call Option Price =" <<to_string(americanCallPriceTri) << endl;
    std::cout << "Trinomial Tree: "<< "American Put Option Price ="<< to_string(americanPutPriceTri) << endl;
}
