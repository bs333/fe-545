//
//  DoubleDigital.h
//  Option_Class
//
//  Created by cheerzzh on 10/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#ifndef __Option_Class__DoubleDigital__
#define __Option_Class__DoubleDigital__

#include "PayOff3.h"
#include "ArgList.h"

class PayOffDoubleDigital : public PayOff
{
public:
    PayOffDoubleDigital(ArgumentList& args);
    virtual double operator()(double Spot) const;
    virtual ~PayOffDoubleDigital(){}
    virtual PayOff* clone() const;

private:
    double LowerLevel;
    double UpperLevel;
    
    
};

#endif /* defined(__Option_Class__DoubleDigital__) */
