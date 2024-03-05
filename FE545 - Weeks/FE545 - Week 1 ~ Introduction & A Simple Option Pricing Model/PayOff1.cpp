// PayOff1.cpp

#include "PayOff1.h" // Corrected the include syntax
#include "MinMax.h" // Include for max function

// Constructor implementation for the PayOff class.
// Initializes a PayOff object with a strike price and an option type.
PayOff::PayOff(double Strike_, OptionType TheOptionsType_) :
    Strike(Strike_), TheOptionsType(TheOptionsType_) {}

// Implementation of the overloaded function call operator.
// Calculates and returns the payoff for a given spot price.
// The function is const as it does not modify any class members.
double PayOff::operator()(double Spot) const
{
    switch (TheOptionsType)
    {
        case call:
            // For a call option, the payoff is max(Spot - Strike, 0).
            return max(Spot - Strike, 0.0);
        
        case put:
            // For a put option, the payoff is max(Strike - Spot, 0).
            return max(Strike - Spot, 0.0);
        
        default:
            // Throws an error if the option type is unknown.
            throw("Unknown option type found.");
    }
}