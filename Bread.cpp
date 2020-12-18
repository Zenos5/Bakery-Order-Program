#include "Bread.h"
#include "BakedGood.h"

#include <string>
using namespace std;

Bread::Bread(string breadVariety) : BakedGood(4.50){
	variety = breadVariety;
}

string Bread::ToString() const {
	return variety + " bread ($" + to_string(price) + ")";
}

double Bread::DiscountedPrice(int amount) const {
	return (amount * price) - ((amount / 3) * price);
}
