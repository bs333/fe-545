#ifndef __PAY_OFF__
#define __PAY_OFF__

#include <algorithm> // For std::max

class PayOff
{
    public:
        PayOff() {}
        virtual ~PayOff() {}
        virtual double operator()(const std::vector<double>& S) const = 0;
};

#endif