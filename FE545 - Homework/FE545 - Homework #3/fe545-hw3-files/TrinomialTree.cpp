// TrinomialTree.cpp
#include "TrinomialTree.h"
#include <cmath>

SimpleTrinomialTree::SimpleTrinomialTree(double Spot_, const Parameters& r_, const Parameters& d_, double Volatility_, unsigned long Steps_, double Time_)
: Spot(Spot_), r(r_), d(d_), Volatility(Volatility_), Steps(Steps_), Time(Time_), TreeBuilt(false) {
}

void SimpleTrinomialTree::BuildTree() {
    TreeBuilt = true;
    double dt = Time / Steps;
    double u = exp(Volatility * sqrt(2 * dt));
    double d = 1 / u;
    // Middle move factor m is implicitly 1
    
    double pu = pow((exp((r.Integral(0, dt) - d.Integral(0, dt)) * dt / 2) - exp(-Volatility * sqrt(dt / 2))) / (exp(Volatility * sqrt(dt / 2)) - exp(-Volatility * sqrt(dt / 2))), 2);
    double pd = pow((exp(Volatility * sqrt(dt / 2)) - exp((r.Integral(0, dt) - d.Integral(0, dt)) * dt / 2)) / (exp(Volatility * sqrt(dt / 2)) - exp(-Volatility * sqrt(dt / 2))), 2);
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

double SimpleTrinomialTree::GetThePrice(const TreeProduct& TheProduct) {
    if (!TreeBuilt) BuildTree();
}