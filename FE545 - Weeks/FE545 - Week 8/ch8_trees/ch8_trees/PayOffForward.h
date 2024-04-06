//
//  PayOffForward.hpp
//  ch8_trees
//
//  Created by Steve Yang on 10/12/21.
//

#ifndef PayOffForward_hpp
#define PayOffForward_hpp

#include "PayOff3.h"
class PayOffForward : public PayOff
{
public:

    PayOffForward(double Strike_);

    virtual double operator()(double Spot) const;
    virtual ~PayOffForward(){}
    virtual PayOff* clone() const;

private:

    double Strike;

};


#endif /* PayOffForward_hpp */
