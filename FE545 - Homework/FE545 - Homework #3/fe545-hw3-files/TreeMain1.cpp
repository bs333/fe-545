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
#include "BinomialTree.h"
#include "TreeAmerican.h"
#include "TreeEuropean.h"
#include "BlackScholesFormulas.h"
//#include "PayOffForward.h"
#include <iostream>
using namespace std;
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

    // Create a PayOffCall object
    PayOffCall thePayOff(Strike);

    // Create a risk free rate ParametersConstant
    ParametersConstant rParam(r);

    // Create a dividend ParametersConstant
    ParametersConstant dParam(d);

    // Create a TreeEuropean object
    
    // Create a TreeAmerican object

    // Create one BinomialTree object
    
    double euroPrice = 0.0;
    // Calculate European Option price
    
    double americanPrice = 0.0;
    // Calculate American Option price

    cout << "euro price " << euroPrice << " amer price " << americanPrice << "\n";

    double tmp;
    cin >> tmp;

    return 0;
}
