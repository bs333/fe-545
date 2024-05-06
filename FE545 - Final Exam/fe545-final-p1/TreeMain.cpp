//
//  main.cpp
//
//  Created by Steve Yang on 04/22/24.
//
//

#include "TrinomialTree.h"
#include "BinomialTree.h"
#include "TreeAmerican.h"
#include "TreeEuropean.h"
#include "BlackScholesFormulas.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{

    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    double d;
    unsigned long Steps;

    Expiry = 1;
    Strike = 50;
    Spot = 50;
    Vol = 0.3;
    r = 0.05;
    d = 0.08;
    Steps = 100;
    
    // Create a PayOffCall and PayOffPut object
    PayOffCall callPayOff(Strike);
    PayOffPut putPayOff(Strike);

    // Create a risk-free rate ParametersConstant
    ParametersConstant rParam(r);

    // Create a dividend ParametersConstant
    ParametersConstant dParam(d);

    // Create a TreeEuropean Call Object
    TreeEuropean europeanCallOption(Expiry, PayOffBridge(callPayOff));

    // Create a TreeEuropean Call Object
    TreeEuropean europeanPutOption(Expiry, PayOffBridge(putPayOff));
    
    // Create a TreeAmerican Call Object
    TreeAmerican americanCallOption(Expiry, PayOffBridge(callPayOff));

    // Create a TreeAmerican Put Object
    TreeAmerican americanPutOption(Expiry, PayOffBridge(putPayOff));

    // Create one TrinomialTree Object
    SimpleTrinomialTree theTree(Spot,
                       rParam,
                       dParam,
                       Vol,
                       Steps,
                       Expiry);
    

    // Calculate European Option prices
    double bsCallOptionPrice = BlackScholesCall(Spot, Strike, r, d, Vol, Expiry);
    double bsPutOptionPrice = BlackScholesPut(Spot, Strike, r, d, Vol, Expiry);
    double euroCallPrice = theTree.GetThePrice(europeanCallOption);
    double euroPutPrice = theTree.GetThePrice(europeanPutOption);
    double amerCallPrice = theTree.GetThePrice(americanCallOption);
    double amerPutPrice = theTree.GetThePrice(americanPutOption);

    // Output results in a tabulated form
    std::cout << std::fixed << std::setprecision(2); // Set precision for decimal places
    std::cout << "Trinomial Tree Output \n";
    std::cout << "Option Type    | Price\n";
    std::cout << "---------------|-------\n";
    std::cout << "Black ShScholes Call   | $" << bsCallOptionPrice << '\n';
    std::cout << "Black ShScholes Put    | $" << bsPutOptionPrice << '\n';
    std::cout << "European Call          | $" << euroCallPrice << '\n';
    std::cout << "European Put           | $" << euroPutPrice << '\n';
    std::cout << "American Call          | $" << amerCallPrice << '\n';
    std::cout << "American Put           | $" << amerPutPrice << std::endl;

    return 0;
}
