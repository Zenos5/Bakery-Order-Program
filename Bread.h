#ifndef BREAD_H
#define BREAD_H

#include <string>
using namespace std;

#include "BakedGood.h"

class Bread : public BakedGood {
public:
	Bread(string breadVariety);
	string ToString() const;
	double DiscountedPrice(int amount) const;
protected:
	string variety = "";
};

#endif
