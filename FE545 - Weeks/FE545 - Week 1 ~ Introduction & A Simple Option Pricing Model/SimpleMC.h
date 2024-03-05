// SimpleMC.h

#ifndef SIMPLEMC_H // Include guard to prevent multiple inclusions
#define SIMPLEMC_H

#include "PayOff1.h" // Include the PayOff class definition

/* Function declaration for SimpleMonteCarlo2.
   This function calculates the price of an option using the Monte Carlo method.

   Parameters:
   - const PayOff& thePayOff: A reference to a PayOff object, which represents the option payoff.
   - double Expiry: The time to expiration of the option.
   - double Spot: The current spot price of the underlying asset.
   - double Vol: The volatility of the underlying asset.
   - double r: The risk-free interest rate.
   - unsigned long NumberOfPaths: The number of paths to simulate in the Monte Carlo method.

   Returns:
   - A double representing the estimated price of the option.
*/
double SimpleMonteCarlo2(const PayOff& thePayOff,
                         double Expiry,
                         double Spot,
                         double Vol,
                         double r,
                         unsigned long NumberOfPaths);

#endif // SIMPLEMC_H