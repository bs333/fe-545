//
//  TreeEuropean.cpp
//
//  Created by Steve Yang on 10/12/23.
//
//

#include "TreeEuropean.h"
#include <algorithm>

TreeEuropean::TreeEuropean(double FinalTime,
                           const PayOffBridge& ThePayOff_)
                 : TreeProducts(FinalTime),
                   ThePayOff(ThePayOff_)
{
}

double TreeEuropean::FinalPayOff(double Spot) const
{
    return ThePayOff(Spot);
}

double TreeEuropean::PreFinalValue(double, //Spot, Borland compiler
                                 double, //Time,   doesnt like unused named variables
                                 double DiscountedFutureValue) const
{
    return DiscountedFutureValue;
}

TreeProducts* TreeEuropean::clone() const
{
    return new TreeEuropean(*this);
}
