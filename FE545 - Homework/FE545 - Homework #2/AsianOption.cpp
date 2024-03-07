#include "AsianOption.h"
#include <numeric> // For std::accumulate
#include <cmath>   // For std::exp and std::log

/* Constructor for the AsianOption class. Initializes the pay_off object.

   Param _pay_off: Pointer to a PayOff object which will be used to calculate payoffs. */
AsianOption::AsianOption(PayOff* _pay_off) : pay_off(_pay_off) {}

/* Constructor for the AsianOptionGeometric class. Calls the base class constructor to initialize pay_off.

   Param _pay_off: Pointer to a PayOff object for payoff calculation logic. */
AsianOptionGeometric::AsianOptionGeometric(PayOff* _pay_off) : AsianOption(_pay_off) {}

/* Calculates the option payoff for a geometric Asian option.

   This method overrides the pure virtual function in the base class.

   It computes the payoff using the geometric mean of spot prices.
   
   Param spot_prices: A vector of double values representing the sampled spot prices of the underlying asset.
   Returns: The calculated option payoff as a double value. */
double AsianOptionGeometric::OptionPayOff(const std::vector<double>& spot_prices) const 
{
    return (*pay_off)(spot_prices);
}