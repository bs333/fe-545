// SimpleMC.h

#ifndef __Option_Class__SimpleMonteCarlo__
#define __Option_Class__SimpleMonteCarlo__

#include "AsianOption.h"

double SimpleMonteCarlo3(const AsianOption& TheOption,
                         double Spot,
                         double Vol,
                         double r,
                         unsigned long NumberOfPaths,
                         unsigned long NumberOfSteps);

#endif /* defined(__Option_Class__SimpleMonteCarlo__) */