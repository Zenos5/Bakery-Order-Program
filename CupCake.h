#ifndef CUPCAKE_H
#define CUPCAKE_H

#include <string>
using namespace std;

#include "Cake.h"

class CupCake : public Cake {
public:
	CupCake(string cakeFlavor, string cakeFrosting, string color);
	string ToString() const;
	double DiscountedPrice(int amount) const;
protected:
	string sprinklesColor = "";
};

#endif

