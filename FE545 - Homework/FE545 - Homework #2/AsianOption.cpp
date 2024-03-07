#include "AsianOption.h"
#include <numeric> // For std::accumulate
#include <cmath>   // For std::exp and std::log

AsianOption::AsianOption(PayOff* _pay_off) : pay_off(_pay_off) {}