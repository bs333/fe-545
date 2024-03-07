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

    double movedSpot = Spot * exp(r * expiry + itoCorrection);
    double thisSpot;
    double runningSum = 0;

    for (unsigned long i = 0; i < NumberOfPaths; i++)
    {
        std::vector<double> spotPrices(NumberOfSteps);
        spotPrices[0] = movedSpot;
        GetGBMSpotPricePath(spotPrices, r, Vol, expiry, NumberOfSteps);
        double thisPayoff = TheOption.OptionPayOff(spotPrices);
        runningSum += thisPayoff;
    }

    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r * expiry);

    return mean;
}