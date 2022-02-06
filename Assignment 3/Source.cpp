/*
* Liberty Anderson
* ITDEV 185 900
* Assignment 3
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

void getUserInput(int& ordered, int& stock, int& shipCost);

void calcOrderInfo(int ordered, int stock, int shipCost);


int main() { 
	int ordered,
		stock,
		shipCost;
	
	getUserInput(ordered, stock, shipCost);
	calcOrderInfo(ordered, stock, shipCost);

	return 0;
}



void getUserInput(int& ordered, int& stock, int& shipCost) {
	cout << "Enter number of spools ordered... ";
	cin >> ordered;
	cout << "Enter number of spools in stock... ";
	cin >> stock;
	cout << "\nEnter special shipping costs\n(Enter 0 if using normal $10 rate)... ";
	cin >> shipCost;
}

void calcOrderInfo(int ordered, int stock, int shipCost) {
	const int	UNIT_PRICE = 100,
				BASE_SHIP_COST = 10;

	int unitsInOrder;

	double	unitTotalPrice,
			shippingTotalPrice,
			orderTotalPrice;

	shipCost += BASE_SHIP_COST;		//add shipping cost
	//default arg value didn't seem to make sense given the math that was shown in the examples

	//determine backorder
	if (stock > ordered) {
		unitsInOrder = ordered;
	}
	else {
		unitsInOrder = stock;
	}

	unitTotalPrice = unitsInOrder * UNIT_PRICE;
	shippingTotalPrice = unitsInOrder * shipCost;
	orderTotalPrice = unitTotalPrice + shippingTotalPrice;

	cout << "\n" << "  Order Summary\n" << endl;
	cout << left << setw(27) << "Spools ordered:" 
		<< right << setw(5) << ordered << endl;
	cout << left << setw(27) << "Spools in this shipment: "
		<< right << setw(5) << unitsInOrder << endl;

	if (unitsInOrder != ordered) {	//report backorder if present
		cout << left << setw(27) << "Spools back ordered: "
			<< right << setw(5) << ordered - unitsInOrder << endl;
	}

	cout << "\n" << fixed << setprecision(2);
	cout << left << setw(22) << "Spool charges: "
		<< right << "$ " << setw(8) << unitTotalPrice << endl;
	cout << left << setw(22) << "Shipping charges: "
		<< right << "$ " << setw(8) << shippingTotalPrice << endl;
	cout << left << setw(22) << "Total this shipment: "
		<< right << "$ " << setw(8) << orderTotalPrice << endl;

}