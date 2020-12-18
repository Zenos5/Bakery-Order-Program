#include "Cake.h"
#include "BakedGood.h"

#include <string>
using namespace std;

Cake::Cake(string cakeFlavor, string cakeFrosting, double cost) : BakedGood(cost) {
	flavor = cakeFlavor;
	frosting = cakeFrosting;
}

string Cake::ToString() const {
	return "Cake";
}

double Cake::DiscountedPrice(int amount) const {
	return 0.0;
}
