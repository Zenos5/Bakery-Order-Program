#include "LayerCake.h"
#include "BakedGood.h"
#include "Cake.h"

#include <string>
using namespace std;

LayerCake::LayerCake(string taste, string topping, int numLayers) : Cake(taste, topping, 9.00) {
	layerNum = numLayers;
	if (frosting == "cream-cheese") {
		price += 1.00 * layerNum;
	}
	if (layerNum > 1) {
		price += 3.00 * (layerNum - 1);
	}
}

string LayerCake::ToString() const {
	return to_string(layerNum) + "-layer " + flavor + " cake with " + frosting 
		+ " frosting ($" + to_string(price) + ")";
}

double LayerCake::DiscountedPrice(int amount) const {
	if (amount >= 3) {
		return amount * (price - 2.00);
	}
	else {
		return amount * price;
	}
}
