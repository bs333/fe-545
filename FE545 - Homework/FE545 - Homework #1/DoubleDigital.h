// DoubleDigital.h
#ifndef __PayOffDoubleDigital__
#define __PayOffDoubleDigital__
#include "PayOff.h"

class DoubleDigitalPayOffParameters : public BasePayOffParameters {
public:
    DoubleDigitalPayOffParameters(const double& K1, const double& K2);
    virtual ~DoubleDigitalPayOffParameters() {};
    double GetLowerStrike() const;
    double GetUpperStrike() const;

private:
    double K1, K2;
};
