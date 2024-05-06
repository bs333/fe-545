//
//  PayOff3.h
//  ch10_factory_pattern
//
//  Created by cheerzzh on 24/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//
#include "ArgList.h";

#ifndef __ch10_factory_pattern__PayOff3__
#define __ch10_factory_pattern__PayOff3__
class PayOff
{
public:
    
    PayOff(){};
    
    virtual double operator()(double Spot) const=0;
    virtual ~PayOff(){}
    virtual PayOff* clone() const=0;
    
private:
    
};

class PayOffCall : public PayOff
{
public:
    
    PayOffCall(ArgumentList& args);
    
    virtual double operator()(double Spot) const;
    virtual ~PayOffCall(){}
    virtual PayOff* clone() const;
    
private:
    
    double Strike;
    
};


class PayOffPut : public PayOff
{
public:
    
    PayOffPut(ArgumentList& args);
    
    virtual double operator()(double Spot) const;
    virtual ~PayOffPut(){}
    virtual PayOff* clone() const;
    
private:
    
    double Strike;
    
};

#endif /* defined(__ch10_factory_pattern__PayOff3__) */
