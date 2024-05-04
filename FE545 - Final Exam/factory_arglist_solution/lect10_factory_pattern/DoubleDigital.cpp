//
//  DoubleDigital.cpp
//  Option_Class
//
//  Created by cheerzzh on 10/6/14.
//  Copyright (c) 2014年 Jared Zhou. All rights reserved.
//

#include "DoubleDigital.h"

PayOffDoubleDigital::PayOffDoubleDigital(ArgumentList& args)
{
    LowerLevel = args.GetDoubleArgumentValue("strike1");
    UpperLevel = args.GetDoubleArgumentValue("strike2");
}

double PayOffDoubleDigital::operator()(double Spot) const
{
    if (Spot <= LowerLevel)
        return 0;
    if (Spot >= UpperLevel)
        return 0;
    
    return 1;
}

PayOff* PayOffDoubleDigital::clone() const
{
    return new PayOffDoubleDigital(* this);
}
