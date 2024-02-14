// SimpleMC.h
#ifndef __Option_Class__SimpleMonteCarlo__
#define __Option_Class__SimpleMonteCarlo__

#include "PayOff.h"

double SimpleMonteCarlo(const PayOff& ThePayOff,
                        double Expiry,
                        double Spot,
                        double Vol,
                        double r,
                        unsigned long NumberOfPaths);

#endif /* defined(__Option_Class__SimpleMonteCarlo__) */