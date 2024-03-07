#include "SimpleMC.h"
#include "PayOff.h"
#include <iostream>

int main()
{
    double Expiry = 1.0;
    double Strike = 50;
    double Spot = 50;
    double Vol = 0.30;
    double r = 0.05;

    unsigned long NumberOfPaths = 1000;
    unsigned long NumberOfSteps = 250;

    PayOffCall callPayOff(Strike);
    PayOffPut putPayOff(Strike);

    AsianOptionGeometric callOption(&callPayOff);
    AsianOptionGeometric putOption(&putPayOff);

    double callPrice = SimpleMonteCarlo3(callOption, Spot, Vol, r, NumberOfPaths, NumberOfSteps);
    double putPrice = SimpleMonteCarlo3(putOption, Spot, Vol, r, NumberOfPaths, NumberOfSteps);

    std::cout << "The price of the Asian geometric call option is " << callPrice << std::endl;
    std::cout << "The price of the Asian geometric put option is " << putPrice << std::endl;

    return 0;
}