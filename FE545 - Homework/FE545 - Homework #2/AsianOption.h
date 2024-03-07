#ifndef __Asian_Option__
#define __Asian_Option__

#include <vector>
#include "PayOff.h"

class AsianOption
{
    public:
        AsianOption(PayOff* _pay_off);
        virtual ~AsianOption() {}
        virtual double OptionPayOff(const std::vector<double>& spot_prices) const = 0;

    protected:
        PayOff* pay_off; // Pay-off class (in this instance call or put)
};

class AsianOptionGeometric : public AsianOption 
{
    public:
        AsianOptionGeometric(PayOff* _pay_off);
        virtual ~AsianOptionGeometric() {}
        virtual double OptionPayOff(const std::vector<double>& spot_prices) const override;
};

#endif