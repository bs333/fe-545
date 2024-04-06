//
//  PayOffForward.cpp
//  ch8_trees
//
//  Created by Steve Yang on 10/12/21.
//

#include "PayOffForward.h"

double PayOffForward::operator () (double Spot) const
{
    return Spot-Strike;
}

PayOffForward::PayOffForward(double Strike_) : Strike(Strike_)
{
}

PayOff* PayOffForward::clone() const
{
    return new PayOffForward(*this);
}
