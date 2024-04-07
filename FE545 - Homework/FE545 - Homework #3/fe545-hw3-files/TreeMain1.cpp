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

    std::cout << "\nEnter expiry\n";
    std::cin >> Expiry;

    std::cout << "\nStrike\n";
    std::cin >> Strike;

    std::cout << "\nEnter spot\n";
    std::cin >> Spot;

    std::cout << "\nEnter vol\n";
    std::cin >> Vol;

    std::cout << "\nr\n";
    std::cin >> r;

    std::cout << "\nd\n";
    std::cin >> d;

    std::cout << "\nNumber of steps\n";
    std::cin >> Steps;

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