// RandomHighTree.cpp
#include "RandomHighTree.h"

RandomHighTree::RandomHighTree(double spot, double r, double d, double vol, unsigned long steps, double expiry)
: theTree(spot, r, d, vol, steps, expiry) {}

void RandomHighTree::BuildTree() {
    // High tree building logic, potentially using GetGBMNextPrice
    // Example: theTree.BuildHigh();  // Assuming BuildHigh is a method of TrinomialTree
}

double RandomHighTree::GetThePrice() {
    // Calculate high estimator option price
    return theTree.CalculateHighPrice();
}