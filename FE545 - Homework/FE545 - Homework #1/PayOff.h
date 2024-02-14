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

class BasePayOffParameters //base class
{
public:
    BasePayOffParameters(){};
    virtual ~BasePayOffParameters(){};

private:
    
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

#endif /* defined(__Payoff_class_with_inheritance__PayOff__) */


