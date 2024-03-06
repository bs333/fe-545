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
    
}

#endif