#ifndef BAKEDGOOD_H
#define BAKEDGOOD_H

#include <string>
using namespace std;

class BakedGood {
public:
	BakedGood(double cost);
	virtual string ToString() const;
	virtual double DiscountedPrice(int amount) const;
protected:
	double price = 0.0;
};

#endif
