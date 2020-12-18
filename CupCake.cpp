#include "CupCake.h"
#include "BakedGood.h"
#include "Cake.h"

#include <string>
using namespace std;

CupCake::CupCake(string taste, string topping, string color) : Cake(taste, topping, 1.95){
	sprinklesColor = color;
	if (frosting == "cream-cheese") {
		price += 0.20;
	}
}

string CupCake::ToString() const {
	return flavor + " cupcake with " + frosting + " frosting and "
		+ sprinklesColor + " sprinkles ($" + to_string(price) + ")";
}

double CupCake::DiscountedPrice(int amount) const {
	if (amount >= 4) {
		return amount * (price - 0.40);
	}
	else if (amount >= 2) {
		return amount * (price - 0.30);
	}
	else {
		return amount * price;
	}
}