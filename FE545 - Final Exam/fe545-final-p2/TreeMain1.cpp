// TreeMain1.cpp

#include <iostream>
#include <vector>
#include "TrinomialTree.h"
#include "TreeAmerican.h"
#include "TreeEuropean.h"
#include "BlackScholesFormulas.h"
#include "RandomHighTree.h"
#include "RandomLowTree.h"

using namespace std;

int main()
{
    const int numSimulations = 100;
    double Expiry = 1;
    double Strike = 50;
    double Spot = 50;
    double Vol = 0.3;
    double r = 0.05;
    double d = 0.08;
    unsigned long Steps = 100;

    // Create PayOff objects for Call and Put Options
    PayOffCall thePayOffCall(Strike);
    PayOffPut thePayOffPut(Strike);

    // Create ParametersConstants
    ParametersConstant rParam(r);
    ParametersConstant dParam(d);

    // Initialize accumulators for averaging
    double sumAmericanCallHigh = 0.0, sumAmericanPutHigh = 0.0;
    double sumAmericanCallLow = 0.0, sumAmericanPutLow = 0.0;
    double sumAmericanCallTri = 0.0, sumAmericanPutTri = 0.0;

    // Simulation loop
    for (int i = 0; i < numSimulations; ++i) {
        // Create Trees
        RandomHighTree highTree(Spot, r, d, Vol, Steps, Expiry);
        RandomLowTree lowTree(Spot, r, d, Vol, Steps, Expiry);
        SimpleTrinomialTree trinomTree(Spot, r, d, Vol, Steps, Expiry);

        // Build Trees
        highTree.BuildTree();
        lowTree.BuildTree();
        trinomTree.BuildTree();  // Assume this method exists

        // Get Prices
        sumAmericanCallHigh += highTree.GetThePrice(TreeAmerican(Expiry, thePayOffCall));
        sumAmericanPutHigh += highTree.GetThePrice(TreeAmerican(Expiry, thePayOffPut));

        sumAmericanCallLow += lowTree.GetThePrice(TreeAmerican(Expiry, thePayOffCall));
        sumAmericanPutLow += lowTree.GetThePrice(TreeAmerican(Expiry, thePayOffPut));

        sumAmericanCallTri += trinomTree.GetThePrice(TreeAmerican(Expiry, thePayOffCall));
        sumAmericanPutTri += trinomTree.GetThePrice(TreeAmerican(Expiry, thePayOffPut));
    }

    // Compute averages
    double avgAmericanCallHigh = sumAmericanCallHigh / numSimulations;
    double avgAmericanPutHigh = sumAmericanPutHigh / numSimulations;
    double avgAmericanCallLow = sumAmericanCallLow / numSimulations;
    double avgAmericanPutLow = sumAmericanPutLow / numSimulations;
    double avgAmericanCallTri = sumAmericanCallTri / numSimulations;
    double avgAmericanPutTri = sumAmericanPutTri / numSimulations;

    // Output results
    cout << "High Estimator American Call Price: " << avgAmericanCallHigh << endl;
    cout << "High Estimator American Put Price: " << avgAmericanPutHigh << endl;
    cout << "Low Estimator American Call Price: " << avgAmericanCallLow << endl;
    cout << "Low Estimator American Put Price: " << avgAmericanPutLow << endl;
    cout << "Trinomial Tree American Call Price: " << avgAmericanCallTri << endl;
    cout << "Trinomial Tree American Put Price: " << avgAmericanPutTri << endl;

    return 0;
}