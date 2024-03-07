#include "AsianOption.h"
#include <numeric> // For std::accumulate
#include <cmath>   // For std::exp and std::log

AsianOption::AsianOption(PayOff* _pay_off) : pay_off(_pay_off) {}

AsianOptionGeometric::AsianOptionGeometric(PayOff* _pay_off) : AsianOption(_pay_off) {}

double AsianOptionGeometric::OptionPayOff(const std::vector<double>& spot_prices) const 
{
    return (*pay_off)(spot_prices);
}