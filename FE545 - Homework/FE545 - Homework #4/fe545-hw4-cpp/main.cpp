//
//  main.cpp
//  ch9-solver-option-vol
//
//  Created by Steve Yang on 11/2/21.
//

/* Needs
 BlackScholesFormulas.cpp
 BSCallClass.cpp
 Normals.cpp
 BSCallTwo.cpp
 */

#include <iostream>
#include "Bisection.h"
#include "BSCallClass.h"
#include "BlackScholesFormulas.h"
#include "NewtonRaphso.h"
#include "BSCallTwo.h"
#include <cmath>

using namespace std;

int main()
{
    double Expiry = 1.0;
    double Strike = 50;
    double Spot = 50;
    double r = 0.05;
    double d = 0.08;
    double Price = 4.23;
        
    double low,high;
    
    cout << "\nlower volatility guess\n";
    cin >> low;
    cout << "\nhigh volatility guess\n";
    cin >> high;
    
    double start;
    cout << "\nstart volatility guess\n";
    cin >> start;
    
    double tolerance;
    
    cout << "\nTolerance for volatility\n";
    cin >> tolerance;
    
    // function object for a vanilla call with all given parameters
    BSCall theCall(r,d,Expiry,Spot,Strike);
    
    // find volatility using bisection method (Bisection object function)
    double vol = 0.0;

    cout << "\nUse bisection method:\n";
    cout << "\nimplied vol is:  " << vol << endl;

    // check the price using BlackSholesCall with the implied vol
    double PriceTwo = 0.0;
    
    cout << " \nOption price by implied volatility is: " << PriceTwo << "\n";

    double tmp;
    cin >> tmp;
    
    return 0;
}

