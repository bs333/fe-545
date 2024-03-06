#include "Random.h"
#include <cstdlib> // static casting
#include <cmath> // exp, log, sqrt

// Generate a random Gaussian number using the Box-Muller transform.
double GetOneGaussianByBoxMuller()
{
    double x, y;

    double sizeSquared, result;

    do
    {
        // Generate two uniform random numbers in the range (-1, 1).
        x = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
        y = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;

        sizeSquared = x * x + y * y;

    // Continue until a point within the unit circle is found.
    } while (sizeSquared >= 1.0 || sizeSquared == 0.0);
    
    // Apply Box-Muller formula to produce a normally distributed value.
    result = x * sqrt(-2 * log(sizeSquared) / sizeSquared);

    return result;
};

void GetGBMSpotPricePath(std::vector<double>& spotPrices,
                         const double& r,
                         const double& v,
                         const double& T,
                         unsigned long NumberOfSteps)
{
    double deltaT = T / NumberOfSteps;
    double drift = exp((r - 0.5 * v * v) * deltaT);
    double vol = sqrt(v * v * deltaT);

    for (unsigned long i = 1; i < NumberOfSteps; ++i)
    {
        double thisGaussian = GetOneGaussianByBoxMuller();
        spotPrices[i] = spotPrices[i - 1] * drift * exp(vol * thisGaussian);
    }
}