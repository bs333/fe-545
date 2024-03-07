// Random.h

#ifndef __Option_Class__Random__
#define __Option_Class__Random__

#include <vector>

// Generates a random Gaussian number.
double GetOneGaussianByBoxMuller();

// Generates a Geometric Brownian Motion spot price path.
void GetGBMSpotPricePath(std::vector<double>& spotPrices, 
                        const double& r, 
                        const double& v, 
                        const double& T, 
                        unsigned long NumberOfSteps);

#endif /* defined(__Option_Class__Random__) */