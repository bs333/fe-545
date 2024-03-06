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
    
}