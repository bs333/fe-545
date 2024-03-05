// PayOff1.h

#ifndef PAYOFF_H // Include guard to prevent multiple inclusions
#define PAYOFF_H

// The PayOff class models the payoff of financial options (calls and puts).
class PayOff
{
public:
    // Enumeration to represent the type of option: call or put.
    enum OptionType { call, put };

    // Constructor that initializes a PayOff object with a strike price and option type.
    PayOff(double Strike_, OptionType TheOptionsType_);

    // Overloaded function call operator to calculate the payoff given a spot price.
    // It is marked as 'const' because it does not modify any member variables.
    double operator()(double Spot) const;
    
private:
    double Strike; // Strike price of the option.
    OptionType TheOptionsType; // The type of the option (call or put).
};

#endif // PAYOFF_H