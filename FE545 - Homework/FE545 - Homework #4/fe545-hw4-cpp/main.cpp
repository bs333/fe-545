#include <iostream>
#include "BSCallClass.h"
#include "BlackScholesFormulas.h"
#include "NewtonRaphso.h"
#include "BSCallTwo.h"

using namespace std;

int main()
{
    double Expiry = 1.0;
    double Strike = 50.0;
    double Spot = 50.0;
    double r = 0.05;
    double d = 0.08; // This is the continuous dividend yield
    double Price = 4.23;
    
    double start; // This will be the starting guess for the implied volatility
    cout << "Enter start volatility guess: ";
    cin >> start;
    
    double tolerance;
    cout << "Enter Tolerance for Newton-Raphson: ";
    cin >> tolerance;
    
    // Create function object for a vanilla call with all given parameters
    BSCallTwo theCall(r, d, Expiry, Spot, Strike);
    
    // Use Newton-Raphson method to find the implied volatility
    double vol = NewtonRaphson<BSCallTwo, &BSCallTwo::Price, &BSCallTwo::Vega>(Price, start, tolerance, theCall);

    cout << "\nUsing Newton-Raphson method:\n";
    cout << "Implied vol is: " << vol << endl;
    
    // Check the price using BlackScholesCall with the implied vol
    double PriceTwo = BlackScholesCall(Spot, Strike, r, d, vol, Expiry);
    
    cout << "Option price by implied volatility is: " << PriceTwo << endl;
    
    return 0;
}