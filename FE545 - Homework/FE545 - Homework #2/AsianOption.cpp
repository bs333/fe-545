#include "AsianOption.h"
#include <numeric> // For std::accumulate
#include <cmath>   // For std::exp and std::log

/* Constructor for the AsianOption class. Initializes the pay_off object.

   Param _pay_off: Pointer to a PayOff object which will be used to calculate payoffs. */
AsianOption::AsianOption(PayOff* _pay_off) : pay_off(_pay_off) {}

/* Constructor for the AsianOptionGeometric class. Calls the base class constructor to initialize pay_off.

   Param _pay_off: Pointer to a PayOff object for payoff calculation logic. */
AsianOptionGeometric::AsianOptionGeometric(PayOff* _pay_off) : AsianOption(_pay_off) {}

double AsianOptionGeometric::OptionPayOff(const std::vector<double>& spot_prices) const 
{
    return (*pay_off)(spot_prices);
}