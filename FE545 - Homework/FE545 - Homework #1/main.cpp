//
//  main.cpp

#include <iostream>
#include <string>
#include <vector>
#include "PayOff.h"
#include "Random.h"
#include "SimpleMC.h"

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Please describe your payoff class as a string:\n";
    
    double Expiry = 1;
    double Strike = 50;
    double Spot = 50;
    double Vol = 0.30;
    double r = 0.05;
    unsigned long NumberOfPath = 100;
    
    // Create PayOffParameter object
    
    // Create Payoff objects
    PayOffCall callPayOff(Param); //PayOff object
    PayOffPut putPayOff(Param);

    double resultCall = SimpleMonteCarlo(callPayOff,
                                          Expiry,
                                          Spot,
                                          Vol,
                                          r,
                                          NumberOfPath);
    
    double resultput = SimpleMonteCarlo(putPayOff,
                                         Expiry,
                                         Spot,
                                         Vol,
                                         r,
                                         NumberOfPath);

    cout <<"\nThe prices are "<< resultCall<<" for the call and \n"<<resultput<<" for the put\n";

    return 0;
}