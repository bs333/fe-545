#include "SimpleMC.h"
#include "Random.h"
#include <vector>

/* SimpleMonteCarlo3 function implementation.

   Performs a Monte Carlo simulation to estimate the price of an Asian option.

   Parameters:
   - TheOption: A reference to an AsianOption object, which specifies the type of option and how its payoff is calculated.
   - Spot: The initial spot price of the underlying asset.
   - Vol: The volatility of the underlying asset, indicating the standard deviation of its returns.
   - r: The risk-free interest rate, used for discounting the payoff to present value.
   - NumberOfPaths: The number of paths to simulate in the Monte Carlo method.
   - NumberOfSteps: The number of steps to use in each path for simulating the underlying asset's price.

   Returns:
   - The estimated price of the option as a double. */
double SimpleMonteCarlo3(const AsianOption& TheOption,
                         double Spot,
                         double Vol,
                         double r,
                         unsigned long NumberOfPaths,
                         unsigned long NumberOfSteps) 
{
    double expiry = 1.0; // Fixed expiry of 1 year for the option.

    double variance = Vol * Vol * expiry; // Total variance over the option's life.
    double rootVariance = sqrt(variance); // Standard deviation of returns.
    double itoCorrection = -0.5 * variance; // Correction term for drift due to Ito's lemma.

    double movedSpot = Spot * exp(r * expiry + itoCorrection); // Adjust initial spot price for drift.
    double runningSum = 0; // Accumulator for payoffs across all paths.

    for (unsigned long i = 0; i < NumberOfPaths; i++)
    {
        std::vector<double> spotPrices(NumberOfSteps); // Vector to store simulated spot prices for one path.
        spotPrices[0] = movedSpot; // Initialize the first spot price.

        // Generate the spot price path.
        GetGBMSpotPricePath(spotPrices, r, Vol, expiry, NumberOfSteps);

        // Calculate the payoff for this path and add it to the running sum.
        double thisPayoff = TheOption.OptionPayOff(spotPrices);
        runningSum += thisPayoff;
    }

    double mean = runningSum / NumberOfPaths; // Calculate the mean payoff.
    mean *= exp(-r * expiry); // Discount the mean payoff to present value.

    return mean; // Return the estimated option price.
}