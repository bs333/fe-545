//
//  PayOff.h
//  Payoff_class_with_inheritance

#ifndef __Payoff_class_with_inheritance__PayOff__
#define __Payoff_class_with_inheritance__PayOff__

#include <iostream>

class PayOff //base class
{
public:
    PayOff(){};
    // pure virtual function -> need not to be defined in base class
    // must be defined in a inherited class
    // the base class in incomplete 
    virtual double operator()(double Spot) const = 0; //given spot,return payoff
    virtual ~PayOff(){}
    
private:
    
}; 

class BasePayOffParameters
{
public:
    BasePayOffParameters() {};
    BasePayOffParameters(double Strike) : m_Strike(Strike) {}
    virtual ~BasePayOffParameters() {};

    double GetStrike() const { return m_Strike; }

private:
    double m_Strike;
};


// class PayOffParameters //derived class

class PayOffCall: public PayOff
{
public:
    PayOffCall(BasePayOffParameters& Param_);
    virtual double operator()(double Spot) const; //overloading () to return payoff
    virtual ~PayOffCall(){}

private:
    double Strike;
};

class PayOffPut: public PayOff
{
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