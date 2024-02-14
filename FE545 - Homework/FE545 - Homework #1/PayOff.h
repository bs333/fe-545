#ifndef __Payoff_class_with_inheritance__PayOff__
#define __Payoff_class_with_inheritance__PayOff__

#include <iostream>
#include <algorithm> // Needed for std::max

class PayOff {
public:
    PayOff(){};
    virtual double operator()(double Spot) const = 0;
    virtual ~PayOff(){}
};

class BasePayOffParameters {
public:
    BasePayOffParameters(){};
    virtual ~BasePayOffParameters(){};
};

class PayOffCall : public PayOff {
public:
    PayOffCall(BasePayOffParameters& Param_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffCall(){}

private:
    double Strike;
};

class PayOffPut : public PayOff {
public:
    PayOffPut(BasePayOffParameters& Param_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffPut(){}

private:
    double Strike;
};

// New classes for Double Digital PayOff
class DoubleDigitalPayOffParameters : public BasePayOffParameters {
public:
    DoubleDigitalPayOffParameters(double K1, double K2);
    virtual ~DoubleDigitalPayOffParameters(){};
    double GetLowerStrike() const;
    double GetUpperStrike() const;

private:
    double K1, K2;
};

class PayOffDoubleDigital : public PayOff {
public:
    PayOffDoubleDigital(const DoubleDigitalPayOffParameters& Param_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffDoubleDigital(){}

private:
    double K1, K2;
};

#endif /* defined(__Payoff_class_with_inheritance__PayOff__) */