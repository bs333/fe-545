#include "Random.h"
#include <cstdlib> // static casting
#include <cmath> // exp, log, sqrt

double GetOneGaussianByBoxMuller()
{
    double x, y;

    double sizeSquared, result;

    do
    {
        x = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
        y = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;

        sizeSquared = x * x + y * y;
    } while (sizeSquared >= 1.0 || sizeSquared == 0.0);
    
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