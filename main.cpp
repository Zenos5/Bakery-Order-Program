#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#include "BakedGood.h"
#include "Bread.h"
#include "CupCake.h"
#include "LayerCake.h"

int main() {
	vector<BakedGood*> bakedGoods;
	const int FIRST_COLUMN_WIDTH = 75;
	const int OTHER_COLUMN_WIDTH = 9;
	const int PRECISION = 2;
	int totalItemAmount = 0;
	double totalItemPrice = 0.0;
	bool running = true;
	string itemType = "";

	cout << "**Bread and Cakes Bakery**" << endl << endl;
	cout << "Enter sub-order (enter \"done\" to finish)" << endl;

	while (running) {
		cout << "Sub-order: ";
		cin >> itemType;
		if (itemType == "done") {
			cout << endl;
			running = false;
		}
		else if (itemType == "Bread") {
			string variety = "";
			int itemNum = 0;

			cin >> variety;
			cin >> itemNum;
			for (int i = 0; i < itemNum; ++i) {
				BakedGood* good = new Bread(variety);
				bakedGoods.push_back(good);
			}
		}
		else if (itemType == "Layer-cake") {
			string flavor = "";
			string frosting = "";
			int layerNum = 0;
			int itemNum = 0;

			cin >> flavor;
			cin >> frosting;
			cin >> layerNum;
			cin >> itemNum;
			for (int i = 0; i < itemNum; ++i) {
				BakedGood* good = new LayerCake(flavor, frosting, layerNum);
				bakedGoods.push_back(good);
			}
		}
		else if (itemType == "Cupcake") {
			string flavor = "";
			string frosting = "";
			string sprinkles = "";
			int itemNum = 0;

			cin >> flavor;
			cin >> frosting;
			cin >> sprinkles;
			cin >> itemNum;
			for (int i = 0; i < itemNum; ++i) {
				BakedGood* good = new CupCake(flavor, frosting, sprinkles);
				bakedGoods.push_back(good);
			}
		}
		cout << endl;
	}

	cout << "Order Confirmations:" << endl;
	for (unsigned int i = 0; i < bakedGoods.size(); ++i) {
		cout << bakedGoods.at(i)->ToString() << endl;
	}

	cout << endl << "Invoice:" << endl;
	cout << setw(FIRST_COLUMN_WIDTH) << left << "Baked Good" << setw(OTHER_COLUMN_WIDTH) << left 
		<< "Quantity" << setw(OTHER_COLUMN_WIDTH) << left << "Total" << endl;
	
	int itemAmount = 0;
	unsigned int listPlacement = 0;
	while (bakedGoods.size() > 0) {
		if (listPlacement == 0) {
			totalItemAmount += 1;
			itemAmount += 1;
			cout << setw(FIRST_COLUMN_WIDTH) << left << bakedGoods.at(0)->ToString();
		}
		else if (listPlacement < bakedGoods.size()){

			string one = bakedGoods.at(listPlacement)->ToString();
			string two = bakedGoods.at(0)->ToString();
			int num = one.compare(two);

			if (num == 0) {
				itemAmount += 1;
				totalItemAmount += 1;
				bakedGoods.erase(bakedGoods.begin() + listPlacement);
				listPlacement -= 1;
			}
		}
		else {
			cout << setw(OTHER_COLUMN_WIDTH) << left << itemAmount << setw(OTHER_COLUMN_WIDTH) << left << fixed << setprecision(PRECISION)
				<< bakedGoods.at(0)->DiscountedPrice(itemAmount) << endl;
			totalItemPrice += bakedGoods.at(0)->DiscountedPrice(itemAmount);
			bakedGoods.erase(bakedGoods.begin() + 0);
			listPlacement = -1;
			itemAmount = 0;
		}
		listPlacement += 1;
	}

	cout << setw(FIRST_COLUMN_WIDTH) << left << "Totals" << setw(OTHER_COLUMN_WIDTH) << left << totalItemAmount 
		<< left << setw(OTHER_COLUMN_WIDTH) << fixed << setprecision(PRECISION) << totalItemPrice << endl;
	cout << "Good Bye";
	
	return 0;
}