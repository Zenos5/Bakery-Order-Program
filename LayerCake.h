#ifndef LAYERCAKE_H
#define LAYERCAKE_H

#include <string>
using namespace std;

#include "Cake.h"

class LayerCake : public Cake {
public:
	LayerCake(string cakeFlavor, string cakeFrosting, int numLayers);
	string ToString() const;
	double DiscountedPrice(int amount) const;
protected:
	int layerNum = 1;
};

#endif
