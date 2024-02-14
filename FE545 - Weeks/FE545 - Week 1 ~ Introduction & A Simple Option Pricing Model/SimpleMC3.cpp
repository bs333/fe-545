#include <SimpleMC3.h> // Include interface for Monte Carlo simulation
#include <Random1.h> // Include for random number generation (Box-Muller)
#include <cmath> // Include for mathematical functions like exp() and sqrt()

// Compatibility handling for math functions in the std namespace with older Visual C++ compilers
#if !defined(_MSC_VER)
using namespace std;
#endif

// Function to perform Monte Carlo simulation for option pricing
double SimpleMonteCarlo3(const VanillaOption& TheOption,
                        double Spot, // Current spot price of the underlying asset
                        double Vol, // Volatility of the underlying asset
                        double r, // Risk-free interest rate
                        unsigned long NumberOfPaths) // Number of paths for the simulation
{
    double Expiry = TheOption.GetExpiry(); // Retrieve the option's expiry time
    
    // Calculate the variance of the asset's returns
    double variance = Vol * Vol * Expiry;
    double rootVariance = sqrt(variance); // Standard deviation of returns
    double itoCorrection = -0.5 * variance; // Ito's lemma correction
    
    // Adjust the initial spot price for the drift over the option's life
    double movedSpot = Spot * exp(r * Expiry + itoCorrection);
    double thisSpot; // Variable to hold the simulated spot price at expiry
    double runningSum = 0; // Sum of payoffs from all simulated paths

    // Simulate a number of paths for the underlying asset price
    for (unsigned long i = 0; i < NumberOfPaths; i++)
    {
        double thisGaussian = GetOneGaussianByBoxMuller(); // Generate a random Gaussian value
        thisSpot = movedSpot * exp(rootVariance * thisGaussian); // Simulate the spot price at expiry
        double thisPayOff = TheOption.OptionPayOff(thisSpot); // Calculate the option's payoff for the simulated expiry price
        runningSum += thisPayOff; // Accumulate the payoffs
    }
    
    // Calculate the mean of the accumulated payoffs
    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r * Expiry); // Discount the mean payoff back to the present value
    
    return mean; // Return the estimated option price
}
