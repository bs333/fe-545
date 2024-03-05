// SimpleMCMain2.cpp

#include "SimpleMC.h"
#include <iostream>
#include <cmath>

int main()
{
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    // Retrieve user input for option parameters and number of paths.
    std::cout << "\nEnter expiry time:\n"; std::cin >> Expiry;
    std::cout << "Enter strike price:\n"; std::cin >> Strike;
    std::cout << "Enter spot price:\n"; std::cin >> Spot;
    std::cout << "Enter volatility:\n"; std::cin >> Vol;
    std::cout << "Enter risk-free interest rate:\n"; std::cin >> r;
    std::cout << "Enter number of paths:\n"; std::cin >> NumberOfPaths;

    PayOff callPayOff(Strike, PayOff::call);
    PayOff putPayOff(Strike, PayOff::put);

    double resultCall = SimpleMonteCarlo2(callPayOff,
                                          Expiry,
                                          Spot,
                                          Vol,
                                          r,
                                          NumberOfPaths);

    double resultPut = SimpleMonteCarlo2(putPayOff,
                                         Expiry,
                                         Spot,
                                         Vol,
                                         r,
                                         NumberOfPaths);

    std::cout << "The prices are " << resultCall
              << " for the call and "
              << resultPut
              << " for the put.\n";

    // This line is typically used to pause the program in some environments
    std::cout << "Press any key to exit.\n";
    std::cin.ignore(); // Ignore the newline left in the input buffer.
    std::cin.get(); // Wait for user input.

    return 0;
}
