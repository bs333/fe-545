#ifndef __PAY_OFF__
#define __PAY_OFF__

#include <algorithm> // For std::max, used in payoff calculations.

/* PayOff: Abstract base class for option payoff calculations.

   Implements the Function Object design pattern to calculate
   the payoff for given spot price(s) of the underlying asset. */
class PayOff
{
    public:
        PayOff() {} // Default constructor
        virtual ~PayOff() {} // Virtual destructor for proper cleanup of derived classes
        
        /* Overloaded operator() to make this class a callable object (function object).

        Must be overridden in derived classes to compute the option payoff.

        Param S: The spot price(s) of the underlying asset.
        Returns: The calculated payoff. */
        virtual double operator()(const std::vector<double>& S) const = 0;
};

/* PayOffCall: Derived class to calculate the payoff of a call option. */
class PayOffCall : public PayOff
{
    public:
        /* Constructor to initialize the strike price of the call option.
        
        Param K_: The strike price. */
        PayOffCall(const double& K_);

        /* Destructor. */
        virtual ~PayOffCall() {}
        
        /* Calculates the payoff of the call option based on spot price(s).

        Overrides the pure virtual function of the base class.

        Param S: The spot price(s) of the underlying asset.
        Returns: The calculated call option payoff. */
        virtual double operator()(const std::vector<double>& S) const override;

    private:
        double K; // Strike price of the option
};

/* PayOffPut: Derived class to calculate the payoff of a put option. */
class PayOffPut : public PayOff
{
    public:
        /* Constructor to initialize the strike price of the put option.
        
        Param K_: The strike price. */
        PayOffPut(const double& K_);

        /* Destructor. */
        virtual ~PayOffPut() {}

        /* Calculates the payoff of the put option based on spot price(s).

        Overrides the pure virtual function of the base class.

        Param S: The spot price(s) of the underlying asset.
        Returns: The calculated call option payoff. */        
        virtual double operator()(const std::vector<double>& S) const override;

    private:
        double K; // Strike price of the option
}

#endif