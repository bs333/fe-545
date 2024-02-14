#include "SimpleMC.h"
#include "PayOff.h"
#include "DoubleDigital.h"
#include <iostream>

int main() {
    double Expiry = 1.0;
    double LowerLevel = 43.0;
    double UpperLevel = 57.0;
    double Spot = 50.0;
    double Vol = 0.30;
    double r = 0.05;
    unsigned long NumberOfPaths = 200;

    PayOffDoubleDigital doubleDigitalPayOff(LowerLevel, UpperLevel);
    double doubleDigitalPrice = SimpleMonteCarlo(doubleDigitalPayOff, Spot, Vol, r, NumberOfPaths);
    std::cout << "The price of the Double Digital option is " << doubleDigitalPrice << std::endl;

    PayOffCall callPayOff(50.0);
    double callPrice = SimpleMonteCarlo(callPayOff, Spot, Vol, r, NumberOfPaths);
    std::cout << "The price of the European Call option is " << callPrice << std::endl;

    PayOffPut putPayOff(50.0);
    double putPrice = SimpleMonteCarlo(putPayOff, Spot, Vol, r, NumberOfPaths);
    std::cout << "The price of the European Put option is " << putPrice << std::endl;

    return 0;
}
