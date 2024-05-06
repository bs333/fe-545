// RandomLowTree.cpp
#include "RandomLowTree.h"

RandomLowTree::RandomLowTree(double spot, double r, double d, double vol, unsigned long steps, double expiry)
: theTree(spot, r, d, vol, steps, expiry) {}

void RandomLowTree::BuildTree() {
    // Low tree building logic
    // Example: theTree.BuildLow();  // Assuming BuildLow is a method of TrinomialTree
}

double RandomLowTree::GetThePrice() {
    // Calculate low estimator option price
    return theTree.CalculateLowPrice();
}