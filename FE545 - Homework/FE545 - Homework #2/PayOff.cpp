#include "PayOff.h"
#include <cmath> // For std::exp
#include <numeric> // For std::accumulate

/* Constructor for PayOffCall, initializing the strike price (K). */
PayOffCall::PayOffCall(const double& K_) : K(K_) {}

/* Calculates the payoff for a call option.

   The payoff is the maximum of zero or the difference between the
   average spot price and the strike price.

   Param S: Vector of spot prices.
   Returns: Calculated payoff for the call option. */
double PayOffCall::operator()(const std::vector<double>& S) const
{
    double average = std::exp(std::accumulate(S.begin(), S.end(), 0.0,
                            [](double a, double b) { return a + std::log(b); }) / S.size());
    return std::max(average - K, 0.0); // Max between 0 and (average spot price - K)
}

PayOffPut::PayOffPut(const double& K_) : K(K_) {}

double PayOffPut::operator()(const std::vector<double>& S) const {
    double average = std::exp(std::accumulate(S.begin(), S.end(), 0.0, [](double a, double b) { return a + std::log(b); }) / S.size());
    return std::max(K - average, 0.0);
}