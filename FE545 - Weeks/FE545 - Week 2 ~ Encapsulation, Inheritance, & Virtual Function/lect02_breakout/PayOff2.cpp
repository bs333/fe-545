//
//  PayOff2.cpp
//  Payoff_class_with_inheritance
//
//  Copyright (c) 2022 Steve Yang. All rights reserved.
//

#include "PayOff2.h"
#include <algorithm> // for max() function

PayOffCall::PayOffCall(BasePayOffParameters& Param_)
{
    Strike = 0;// Need to change
}

double PayOffCall::operator()(double Spot) const
{
    return std::max(Spot - Strike,0.0);

}

PayOffPut::PayOffPut(BasePayOffParameters& Param_)
{
    Strike = 0;// Need to change
}

double PayOffPut::operator()(double Spot) const
{
    return std::max(Strike - Spot,0.0);
}




