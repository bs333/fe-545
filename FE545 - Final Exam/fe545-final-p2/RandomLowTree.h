// RandomLowTree.h
#ifndef RANDOMLOWTREE_H
#define RANDOMLOWTREE_H

#include "TrinomialTree.h"
#include "Random.h"

class RandomLowTree {
private:
    TrinomialTree theTree;
public:
    RandomLowTree(double spot, double r, double d, double vol, unsigned long steps, double expiry);
    void BuildTree();
    double GetThePrice();
};

#endif