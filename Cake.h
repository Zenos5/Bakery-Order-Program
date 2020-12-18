#ifndef CAKE_H
#define CAKE_H

#include "BakedGood.h"

#include <string>
using namespace std;

class Cake : public BakedGood {
public:
	Cake(string cakeFlavor, string cakeFrosting, double cost);
	virtual string ToString() const;
	virtual double DiscountedPrice(int amount) const;
protected:
	string flavor = "";
	string frosting = "";
};

#endif
