//
//  SimpleMC.h
//  Payoff_class_with_inheritance

#ifndef __Payoff_class_with_inheritance__SimpleMC__
#define __Payoff_class_with_inheritance__SimpleMC__

#include <iostream>
#include "PayOff.h"

double SimpleMonteCarlo(const PayOff& thePayOff, // use PayOff class, strike is hidden inside the Payoff object
                         double Expiry,
                         double Spot,
                         double Vol,
                         double r,
                         unsigned long NumberOfPath);

#endif /* defined(__Payoff_class_with_inheritance__SimpleMC2__) */
