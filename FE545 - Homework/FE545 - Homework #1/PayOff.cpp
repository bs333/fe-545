//  PayOff.cpp

#include "PayOff.h"
#include "DoubleDigital.h"
#include <algorithm> // for max() function

PayOffCall::PayOffCall(BasePayOffParameters& Param_) : Strike(Param_.GetStrike()) {}

double PayOffCall::operator()(double Spot) const
{
    return std::max(Spot - Strike,0.0);

}

PayOffPut::PayOffPut(BasePayOffParameters& Param_) : Strike(Param_.GetStrike()) {}

double PayOffPut::operator()(double Spot) const
{
    return std::max(Strike - Spot,0.0);
}

// // DoubleDigitalPayOffParameters implementation
// DoubleDigitalPayOffParameters::DoubleDigitalPayOffParameters(double K1, double K2)
// : BasePayOffParameters(), K1(K1), K2(K2) {}

// double DoubleDigitalPayOffParameters::GetLowerStrike() const { return K1; }
// double DoubleDigitalPayOffParameters::GetUpperStrike() const { return K2; }

// // PayOffDoubleDigital implementation
// PayOffDoubleDigital::PayOffDoubleDigital(const DoubleDigitalPayOffParameters& Param_)
// : K1(Param_.GetLowerStrike()), K2(Param_.GetUpperStrike()) {}

double PayOffDoubleDigital::operator()(double Spot) const {
    if (Spot <= K1 || Spot >= K2) return 0;
    else return 1;
}