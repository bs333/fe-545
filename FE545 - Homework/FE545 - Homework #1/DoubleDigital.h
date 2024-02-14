// DoubleDigital.h
#ifndef DOUBLE_DIGITAL_H // Include guard start
#define DOUBLE_DIGITAL_H

#include "PayOff.h"

class DoubleDigitalPayOffParameters : public BasePayOffParameters {
public:
    DoubleDigitalPayOffParameters(double K1, double K2);
    virtual ~DoubleDigitalPayOffParameters() {};
    double GetLowerStrike() const;
    double GetUpperStrike() const;

private:
    double K1, K2;
};

class PayOffDoubleDigital : public PayOff {
public:
    PayOffDoubleDigital(const DoubleDigitalPayOffParameters& Params);
    virtual ~PayOffDoubleDigital() {};
    virtual double operator()(double Spot) const override;

private:
    double K1, K2;
};

#endif