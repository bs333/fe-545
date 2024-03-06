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

class PayOffCall : public PayOff
{
    public:
        PayOffCall(const double& K_);
        virtual ~PayOffCall() {}
        virtual double operator()(const std::vector<double>& S) const override;

    private:
        double K; // Strike price
};

class PayOffPut : public PayOff
{
    public:
        PayOffPut(const double& K_);
        virtual ~PayOffPut() {}
        virtual double operator()(const std::vector<double>& S) const override;

    private:
        double K;
}

#endif