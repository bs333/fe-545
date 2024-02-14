// DoubleDigital.cpp

#include "DoubleDigital.h"

// Constructor for DoubleDigitalPayOffParameters
DoubleDigitalPayOffParameters::DoubleDigitalPayOffParameters(double K1, double K2)
: BasePayOffParameters(), K1(K1), K2(K2) {}

// Getter for Lower Strike
double DoubleDigitalPayOffParameters::GetLowerStrike() const { return K1; }

// Getter for Upper Strike
double DoubleDigitalPayOffParameters::GetUpperStrike() const { return K2; }

// Constructor for PayOffDoubleDigital
PayOffDoubleDigital::PayOffDoubleDigital(const DoubleDigitalPayOffParameters& Param_)
: K1(Param_.GetLowerStrike()), K2(Param_.GetUpperStrike()) {}

// Implementation of the PayOff operation
double PayOffDoubleDigital::operator()(double S) const {
    if (S <= K1 || S >= K2) return 0;
    else return 1;
}
