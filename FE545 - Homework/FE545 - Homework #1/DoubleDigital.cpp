#include "DoubleDigital.h"

// Constructor for DoubleDigitalPayOffParameters
DoubleDigitalPayOffParameters::DoubleDigitalPayOffParameters(const double& K1, const double& K2)
: BasePayOffParameters(), K1(K1), K2(K2) {}

// Destructor for DoubleDigitalPayOffParameters
DoubleDigitalPayOffParameters::~DoubleDigitalPayOffParameters() {}

// Getter for Lower Strike
double DoubleDigitalPayOffParameters::GetLowerStrike() const { return K1; }

// Getter for Upper Strike
double DoubleDigitalPayOffParameters::GetUpperStrike() const { return K2; }
