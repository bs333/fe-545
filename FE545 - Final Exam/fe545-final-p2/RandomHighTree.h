// RandomHighTree.h
#ifndef RANDOMHIGHTREE_H
#define RANDOMHIGHTREE_H

#include "TrinomialTree.h"
#include "Random.h"  // Ensure this file provides the necessary function prototypes

class RandomHighTree {
private:
    TrinomialTree theTree;
public:
    RandomHighTree(double spot, double r, double d, double vol, unsigned long steps, double expiry);
    void BuildTree();
    double GetThePrice();
};

#endif