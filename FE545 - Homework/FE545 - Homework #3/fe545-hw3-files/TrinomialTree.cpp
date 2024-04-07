// TrinomialTree.cpp
#include "TrinomialTree.h"
#include <cmath>

SimpleTrinomialTree::SimpleTrinomialTree(double Spot_, const Parameters& r_, const Parameters& q_, double Volatility_, unsigned long Steps_, double Time_)
: Spot(Spot_), r(r_), q(q_), Volatility(Volatility_), Steps(Steps_), Time(Time_), TreeBuilt(false) {
}

void SimpleTrinomialTree::BuildTree() {
    TreeBuilt = true;
    double dt = Time / Steps;
    double u = exp(Volatility * sqrt(2 * dt));
    double d = 1 / u;
    // Middle move factor m is implicitly 1
    
    double pu = pow((exp((r.Integral(0, dt) - q.Integral(0, dt)) * dt / 2) - exp(-Volatility * sqrt(dt / 2))) / (exp(Volatility * sqrt(dt / 2)) - exp(-Volatility * sqrt(dt / 2))), 2);
    double pd = pow((exp(Volatility * sqrt(dt / 2)) - exp((r.Integral(0, dt) - q.Integral(0, dt)) * dt / 2)) / (exp(Volatility * sqrt(dt / 2)) - exp(-Volatility * sqrt(dt / 2))), 2);
    double pm = 1 - pu - pd;

    TheTree.resize(Steps + 1);
    for (unsigned long i = 0; i <= Steps; ++i) {
        TheTree[i].resize(i + 1);
        for (long j = -static_cast<long>(i); j <= static_cast<long>(i); j+=2) {
            double exponent = j * sqrt(dt);
            // Calculate S_{i,j} for each node.
            double Spot_ij = Spot * pow(u, (i + j)/2) * pow(d, (i - j)/2);
            TheTree[i][(j + i)/2].resize(3);
            TheTree[i][(j + i)/2][0] = Spot_ij * d; // Down
            TheTree[i][(j + i)/2][1] = Spot_ij;     // Middle
            TheTree[i][(j + i)/2][2] = Spot_ij * u; // Up
        }
    }

    // Discount factor adjusted for each step.
    Discounts.resize(Steps);
    for (unsigned long i = 0; i < Steps; ++i) {
        Discounts[i] = exp(-(r.Integral(i * dt, (i + 1) * dt)));
    }
}

double SimpleTrinomialTree::GetThePrice(const TreeProducts& TheProduct) {
    if (!TreeBuilt) BuildTree();

    for (unsigned long i = 0; i <= Steps; ++i) {
        for (unsigned long j = 0; j < TheTree[Steps][i].size(); ++j) {
            TheTree[Steps][i][j] = TheProduct.FinalPayOff(TheTree[Steps][i][j]);
        }
    }

    // Backward induction to calculate the price at the root
    for (int i = Steps - 1; i >= 0; --i) {
        for (unsigned long j = 0; j < TheTree[i].size(); ++j) {
            // Simplified calculation: adjust based on your model
            double discountedValue = (pu * TheTree[i + 1][j + 1] + pm * TheTree[i + 1][j] + pd * TheTree[i + 1][j - 1]) * Discounts[i];
            TheTree[i][j] = discountedValue;
        }
    }
    
    return TheTree[0][0]; // The price of the option at time 0
}