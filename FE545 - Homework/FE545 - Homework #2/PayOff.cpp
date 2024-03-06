#include "PayOff.h"
#include <cmath> // log, exp, sqrt

PayOffCall::PayOffCall(const double& K_) : K(K_) {}

double PayOffCall::operator()(const std::vector<double>& S) const
{
    double average = std::exp(std::accumulate(S.begin(), S.end(), 0.0, [](double a, double b) { return a + std::log(b); }) / S.size());
    return std::max(average - K, 0.0);
}

PayOffPut::PayOffPut(const double& K_) : K(K_) {}

double PayOffPut::operator()(const std::vector<double>& S) const {
    double average = std::exp(std::accumulate(S.begin(), S.end(), 0.0, [](double a, double b) { return a + std::log(b); }) / S.size());
    return std::max(K - average, 0.0);
}