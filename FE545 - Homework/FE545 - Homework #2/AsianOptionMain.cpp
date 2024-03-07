// AsianOptionMain.cpp

#include "SimpleMC.h"
#include "PayOff.h"
#include <iostream>

int main() {
    // Define parameters for the option pricing.

    double Expiry = 1.0; // Option expiry time in years
    double Strike = 50;  // Strike price of the option
    double Spot = 50;    // Initial spot price of the underlying asset
    double Vol = 0.30;   // Volatility of the underlying asset
    double r = 0.05;     // Risk-free interest rate

    unsigned long NumberOfPaths = 1000; // Number of paths for Monte Carlo simulation
    unsigned long NumberOfSteps = 250;  // Number of steps in each path

    // Create PayOff objects for call and put options.
    PayOffCall callPayOff(Strike);
    PayOffPut putPayOff(Strike);

    // Create AsianOptionGeometric objects for the call and put options.
    AsianOptionGeometric callOption(&callPayOff);
    AsianOptionGeometric putOption(&putPayOff);

    // Perform Monte Carlo simulations to estimate the prices of the call and put options.
    double callPrice = SimpleMonteCarlo3(callOption, Spot, Vol, r, NumberOfPaths, NumberOfSteps);
    double putPrice = SimpleMonteCarlo3(putOption, Spot, Vol, r, NumberOfPaths, NumberOfSteps);

    // Output the results.
    std::cout << "The price of the Asian geometric call option is " << callPrice << std::endl;
    std::cout << "The price of the Asian geometric put option is " << putPrice << std::endl;

    return 0;
}