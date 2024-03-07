// SimpleMC.h

#ifndef __Option_Class__SimpleMonteCarlo__
#define __Option_Class__SimpleMonteCarlo__

#include "AsianOption.h"

/* SimpleMonteCarlo3:
   This function performs the Monte Carlo simulation to price an Asian option.

   Parameters:
   - TheOption: A reference to an AsianOption object. This object encapsulates the
     option type (call or put) and the payoff calculation method. The Monte Carlo
     simulation will use this information to compute the option price.
   - Spot: The initial spot price of the underlying asset.
   - Vol: The volatility of the underlying asset. This is a measure of the asset's
     price variation and is a crucial input for the simulation.
   - r: The risk-free interest rate. This rate is used to discount the option payoff
     back to the present value.
   - NumberOfPaths: The number of simulation paths. This parameter determines how many
     times the underlying asset price path will be simulated. A higher number of paths
     can increase the accuracy of the simulation but also increases computational time.
   - NumberOfSteps: The number of steps in each simulation path. This determines how many
     times the asset price will be sampled in each path, which is relevant for path-dependent
     options like Asian options.

   Returns:
   - The estimated price of the Asian option as a double.
*/
double SimpleMonteCarlo3(const AsianOption& TheOption,
                         double Spot,
                         double Vol,
                         double r,
                         unsigned long NumberOfPaths,
                         unsigned long NumberOfSteps);

#endif /* defined(__Option_Class__SimpleMonteCarlo__) */