#include <iostream>
#include "RetailItem.h"

using namespace std;

RetailItem::RetailItem(string d, int u, double p)
{
	description = d;
	unitsOnHand = u;
	price = p;
}

float RetailItem::getStockValue()
{
	return unitsOnHand * price;
}

string RetailItem::getDescription() const
{
	return description;
}

int RetailItem::getUnits() const
{
	return unitsOnHand;
}

double RetailItem::getPrice() const
{
	return price;
}
