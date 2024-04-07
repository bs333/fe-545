// TreeMain1.cpp

/*
requires
    Arrays.cpp
    BinomialTree.cpp
    BlackScholesFormulas.cpp
    Normals.cpp
    Parameters.cpp
    PayOff3.cpp
    PayOffBridge.cpp
    TreeAmerican.cpp
    TreeEuropean.cpp
    TreeMain.cpp
    TreeProducts.cpp
  */
#include "BinomialTree.h"
#include "TreeAmerican.h"
#include "TreeEuropean.h"
#include "BlackScholesFormulas.h"
#include "TrinomialTree.h"

#include <iostream>
#include <cmath>

int main()
{
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    double d;
    unsigned long Steps;

    cout << "\nEnter expiry\n";
    cin >> Expiry;

    cout << "\nStrike\n";
    cin >> Strike;

    cout << "\nEnter spot\n";
    cin >> Spot;

    cout << "\nEnter vol\n";
    cin >> Vol;

    cout << "\nr\n";
    cin >> r;

    cout << "\nd\n";
    cin >> d;

    cout << "\nNumber of steps\n";
    cin >> Steps;

    // Create a PayOffCall object.
    PayOffCall callPayOff(Strike);

    // Create a PayOffPut object.
    PayOffPut putPayOff(Strike);

    // Create a risk free rate ParametersConstant.
    ParametersConstant rParam(r);

    // Create a dividend ParametersConstant
    ParametersConstant dParam(d);

    // Create a TreeEuropean objects.
    TreeEuropean europeanCallOption(Expiry, callPayOff);
    TreeEuropean europeanPutOption(Expiry, putPayOff);
    
    // Create a TreeAmerican objects.
    TreeAmerican americanCallOption(Expiry, callPayOff);
    TreeAmerican americanPutOption(Expiry, putPayOff);

    // Create TrinomialTree object.
    SimpleTrinomialTree theTree(Spot, rParam, dParam, Vol, Steps, Expiry);

    // Retrieve prices.
    double euroCallPrice = theTree.GetThePrice(europeanCallOption);
    double euroPutPrice = theTree.GetThePrice(europeanPutOption);
    double amerCallPrice = theTree.GetThePrice(americanCallOption);
    double amerPutPrice = theTree.GetThePrice(americanPutOption);

    // Print out prices.
    std::cout << "European Call Price: " << euroCallPrice << std::endl;
    std::cout << "European Put Price: " << euroPutPrice << std::endl;
    std::cout << "American Call Price: " << amerCallPrice << std::endl;
    std::cout << "American Put Price: " << amerPutPrice << std::endl;

    double tmp;
    std::cin >> tmp;

    return 0;
}