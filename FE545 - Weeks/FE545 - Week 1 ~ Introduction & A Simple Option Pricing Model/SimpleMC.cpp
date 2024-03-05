// SimpleMC.cpp

#include "SimpleMC.h" // Include the declaration of the SimpleMonteCarlo2 function and PayOff class.
#include "Random1.h" // Include the function for generating Gaussian random numbers.

/* This function calculates the price of a financial derivative using the Monte Carlo method.
Parameters:
- thePayOff: The payoff function of the derivative, which determines how the payout varies with the underlying asset price.
- Expiry: The time to expiration of the derivative in years.
- Spot: The current spot price of the underlying asset.
- Vol: The volatility of the underlying asset, expressed as a decimal.
- r: The risk-free interest rate, expressed as a decimal.
- NumberOfPaths: The number of simulated paths used in the Monte Carlo simulation.

Returns: The estimated price of the derivative. 

*/
double SimpleMonteCarlo2(const PayOff& thePayOff,
                          double Expiry,
                          double Spot,
                          double Vol,
                          double r,
                          unsigned long NumberOfPaths)
{
    double variance = Vol * Vol * Expiry; // Calculate variance of the asset's return.
    double rootVariance = sqrt(variance); // Calculate the standard deviation (square root of variance).
    double itoCorrection = -0.5 * variance; // Apply Ito's correction to adjust for the continuous compounding.
    
    double movedSpot = Spot * exp(r * Expiry + itoCorrection); // Calculate the adjusted spot price.
    double thisSpot; // Variable to store the current spot price in each simulation.
    double runningSum = 0.0; // Initialize sum of payoffs.
    
    // Loop over the number of paths to simulate different scenarios.
    for (unsigned long i = 0; i < NumberOfPaths; i++)
    {
        double thisGaussian = GetOneGaussianByBoxMuller(); // Generate a random Gaussian value.
        thisSpot = movedSpot * exp(rootVariance * thisGaussian); // Calculate the spot price for this path.
        double thisPayOff = thePayOff(thisSpot); // Calculate the payoff for this path.
        runningSum += thisPayOff; // Add the payoff to the running sum.
    }
    
    double mean = runningSum / NumberOfPaths; // Calculate the average payoff.
    mean *= exp(-r * Expiry); // Discount the average payoff back to the present value.
    
    return mean; // Return the estimated price of the derivative.
}
