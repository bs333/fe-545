<Vanilla1.h>

#ifndef VANILLA_1_H
#define VANILLA_1_H

#include <PayOff2.h>

class VanillaOption
{
	public:
		VanillaOption(const PayOff& ThePayOff_, double Expiry_);
		double GetExpiry() const;
		double OptionPayOff(double Spot) const;
		
	private:
		double Expiry;
		PayOff& ThePayOff;
};