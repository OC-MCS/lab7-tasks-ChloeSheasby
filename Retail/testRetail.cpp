// code to test your RetailItem class goes here
#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <string>
#include <iomanip>
#include "RetailItem.h"

using namespace std;

void loadItems(vector<RetailItem> &v);

int main()
{
	vector< RetailItem > v;
	float total = 0;
	loadItems(v);

	cout << "   Description\tPrice\tOn Hand" << setw(9) << right << "Value" << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << setw(15) << left << v[i].getDescription() << "\t" << fixed << showpoint
			<< setprecision(2) << v[i].getPrice() << "\t" << setw(7) << right << v[i].getUnits()
			<< "\t" << setw(8) << right << v[i].getStockValue() << endl;
		total += v[i].getStockValue();
	}

	cout << endl << "Total inventory value: " << fixed << showpoint << setprecision(2) << total << endl;

	return 0;
}

void loadItems(vector<RetailItem> &v)
{
	ifstream inFile;
	string description, unitsOnHand, price;

	inFile.open("retailItemLab7.csv");		//this is not opening

	while (getline(inFile, description, ','))
	{
		getline(inFile, unitsOnHand, ',');
		getline(inFile, price);
		RetailItem item(description, stoi(unitsOnHand), stof(price));
		v.push_back(item);
	}

}