// TrinomialTree.h

#ifndef TRINOMIALTREE_H
#define TRINOMIALTREE_H

#include "TreeProducts.h"
#include "Parameters.h"
#include "Arrays.h"
#include <vector>

class SimpleTrinomialTree {
public:
    SimpleTrinomialTree(double Spot_,
                        const Parameters& r_,
                        const Parameters& d_
                        double Volatility_,
                        unsigned long Steps_,
                        double Time_);

    double GetThePrice(const TreeProducts& TheProduct);

protected:
    void BuildTree();

private:
    double Spot;
    Parameters r;
    double Volatility;
    unsigned long Steps;
    double Time;
    bool TreeBuilt;

    std::vector<std::vector<std::vector<double>>> TheTree;
    MJArray Discounts;
};

#endif