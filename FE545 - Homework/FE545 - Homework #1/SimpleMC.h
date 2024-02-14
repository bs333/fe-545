// SimpleMC.h
#ifndef __Option_Class__SimpleMonteCarlo__
#define __Option_Class__SimpleMonteCarlo__

#include "PayOff.h"

double SimpleMonteCarlo(const PayOff& ThePayOff,
                        double Spot,
                        double Vol,
                        double r,
                        unsigned long NumberOfPath);

#endif /* defined(__Option_Class__SimpleMonteCarlo__) */