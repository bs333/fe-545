// Simple Monte Carlo simulation for pricing European call options
// Requires 'Random1.cpp' for random number generation using Box-Muller transform

#include "Random1.h"
#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate the price of a European call option using Monte Carlo simulation
double SimpleMonteCarlo1(double Expiry,
                        double Strike,
                        double Spot,
                        double Vol,
                        double r,
                        unsigned long NumberOfPaths)
{
    // Calculate parameters for the simulation
    double variance = Vol * Vol * Expiry; // Total variance over the option's life
    double rootVariance = sqrt(variance); // Standard deviation of the return
    double itoCorrection = -0.5 * variance; // Correction for the drift of the stock price

    // Adjust initial spot price for the drift over the option's life
    double movedSpot = Spot * exp(r * Expiry + itoCorrection);
    double thisSpot;
    double runningSum = 0;

    // Perform the Monte Carlo simulation across the specified number of paths
    for (unsigned long i = 0; i < NumberOfPaths; i++)
    {
        double thisGaussian = GetOneGaussianByBoxMuller(); // Generate a random Gaussian value
        thisSpot = movedSpot * exp(rootVariance * thisGaussian); // Calculate the spot price at expiry
        double thisPayOff = thisSpot - Strike; // Calculate the payoff for this path
        thisPayOff = thisPayOff > 0 ? thisPayOff : 0; // Payoff is max(S - K, 0) for a call option
        runningSum += thisPayOff; // Accumulate the payoffs
    }

    // Calculate the average payoff from all paths
    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r * Expiry); // Discount the average payoff back to present value

    return mean;
}

int main()
{
    // Declare variables for input
    double Expiry, Strike, Spot, Vol, r;
    unsigned long NumberOfPaths;

    // Prompt user for input
    cout << "\nEnter expiry:\n"; cin >> Expiry;
    cout << "\nEnter strike:\n"; cin >> Strike;
    cout << "\nEnter spot price:\n"; cin >> Spot;
    cout << "\nEnter volatility (standard deviation):\n"; cin >> Vol;
    cout << "\nEnter risk-free interest rate:\n"; cin >> r;
    cout << "\nEnter number of paths:\n"; cin >> NumberOfPaths;

    // Validate input
    if (expiry <= 0 || strike <= 0 || spot <= 0 || vol <= 0 || r < 0 || numberofpaths <= 0) {
		cout << "invalid input values.\n";
		return 1;
	}

    // Calculate the option price using the Monte Carlo simulation
    double result = SimpleMonteCarlo1(Expiry, Strike, Spot, Vol, r, NumberOfPaths);

    // Display the result
    cout << "The price is: " << result << "\n";

    // Wait for user input before closing (consider removing for non-Windows platforms)
    double tmp;
    cin >> tmp;

    return 0;
}
