#pragma once
#include <iostream>

using namespace std;

class RetailItem
{
private:
	string description;
	int unitsOnHand;
	double price;
public:
	RetailItem(string, int, double);
	float getStockValue();
	string getDescription() const;
	int getUnits() const;
	double getPrice() const;
};
