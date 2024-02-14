//
//  SimpleMC.cpp
//  Payoff_class_with_inheritance


#include "SimpleMC.h"
#include "PayOff.h"
#include "Random.h"
#include <cmath>

//the basic math functions should be in
#if !defined(_MSC_VER)
using namespace std;
#endif

double SimpleMonteCarlo(const PayOff& thePayOff, // use PayOff class, actually two subclasses, each for call and put
                         double Expiry,
                         double Spot,
                         double Vol,
                         double r,
                         unsigned long NumberOfPath)
{
    double variance = Vol * Vol * Expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5 * variance;
    
    double movedSpot = Spot * exp(r *Expiry + itoCorrection);
    double thisSpot;
    double runningSum = 0;
    
    for(unsigned long i = 0; i < NumberOfPath; i++)
    {
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot * exp(rootVariance * thisGaussian);
        double thisPayoff = thePayOff(thisSpot);
        runningSum += thisPayoff;
    }

    double mean = runningSum / NumberOfPath;
    mean *= exp(-r * Expiry);

    return mean;
}


