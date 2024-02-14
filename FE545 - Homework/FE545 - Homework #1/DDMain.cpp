// DDMain.cpp

#include "DoubleDigital.h"
#include "PayOff.h"
#include "SimpleMC.h"
#include <iostream>

int main() {
    double Expiry = 1.0;
    double LowerLevel = 43.0;
    double UpperLevel = 57.0;
    double Spot = 50.0;
    double Vol = 0.30;
    double r = 0.05;
    unsigned long NumberOfPaths = 200;

    DoubleDigitalPayOffParameters doubleDigitalParams(LowerLevel, UpperLevel);
    PayOffDoubleDigital doubleDigitalPayOff(doubleDigitalParams);

    BasePayOffParameters callPutParams(50.0);
    PayOffCall callPayOff(callPutParams);
    PayOffPut putPayOff(callPutParams);

    double priceDoubleDigital = SimpleMonteCarlo(doubleDigitalPayOff, Spot, Vol, r, NumberOfPaths);
    double priceCall = SimpleMonteCarlo(callPayOff, Spot, Vol, r, NumberOfPaths);
    double pricePut = SimpleMonteCarlo(putPayOff, Spot, Vol, r, NumberOfPaths);

    std::cout << "Double Digital option price: " << priceDoubleDigital << std::endl;
    std::cout << "Call option price: " << priceCall << std::endl;
    std::cout << "Put option price: " << pricePut << std::endl;

    return 0;
}
