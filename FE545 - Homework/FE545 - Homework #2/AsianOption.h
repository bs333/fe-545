// AsianOption.h

#ifndef __Asian_Option__
#define __Asian_Option__

#include <vector>
#include "PayOff.h"

/* AsianOption: Abstract base class for Asian options.

   It provides a common interface for different types of Asian options,
   encapsulating the behavior through the PayOff class for calculating payoffs. */
class AsianOption
{
    public:
        /* Constructor that initializes the PayOff object for the option.

        Param _pay_off: Pointer to a PayOff object, which encapsulates the payoff calculation logic. */
        AsianOption(PayOff* _pay_off);

        /* Virtual destructor ensures derived class destructors are called correctly. */
        virtual ~AsianOption() {}

        /* Pure virtual function for calculating the option payoff.

        This function must be implemented by derived classes to specify how the payoff is calculated.

        Param spot_prices: A vector of double values representing spot prices of the underlying asset.
        Returns: The calculated option payoff as a double. */
        virtual double OptionPayOff(const std::vector<double>& spot_prices) const = 0;

    protected:
        PayOff* pay_off; // Pay-off class (in this instance call or put), used to calculate the option payoff.
};

/* AsianOptionGeometric: Derived class from AsianOption to implement payoff calculation
   for geometric Asian options. */
class AsianOptionGeometric : public AsianOption 
{
    public:
        /* Constructor that initializes the PayOff object for the geometric Asian option.
        
        Param _pay_off: Pointer to a PayOff object, encapsulating the payoff calculation logic. */
        AsianOptionGeometric(PayOff* _pay_off);

        /* Destructor. */
        virtual ~AsianOptionGeometric() {}

        /* Overridden function to calculate the payoff for a geometric Asian option.
        
        Utilizes the geometric mean of spot prices for calculation.

        Param spot_prices: A vector of double values representing spot prices of the underlying asset.
        Returns: The calculated option payoff as a double. */
        virtual double OptionPayOff(const std::vector<double>& spot_prices) const override;
};

#endif