#include "BakedGood.h"

#include <string>
using namespace std;

BakedGood::BakedGood(double cost) {
	price = cost;
}

string BakedGood::ToString() const {
	return "Baked Good";
}

double BakedGood::DiscountedPrice(int amount) const {
	return 0.0;
}
