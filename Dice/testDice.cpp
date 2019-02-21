// client code to use the Die class goes here
#include<iostream>
#include<iomanip>
#include "Die.h"

using namespace std;

void displayPct(int dieArray[], int size);

int main()
{
	const int DIE1_SIZE = 6;
	const int DIE2_SIZE = 12;
	const int FIRST_DIE = 7;
	const int SECOND_DIE = 13;
	Die die1(DIE1_SIZE);
	Die die2(DIE2_SIZE);
	int firstDie[FIRST_DIE] = { 0, 0, 0, 0, 0, 0, 0 };
	int secondDie[SECOND_DIE] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	int result1, result2;

	for (int i = 0; i < 1000000; i++)
	{
		die1.roll();
		die2.roll();
		result1 = die1.getValue();
		result2 = die2.getValue();
		firstDie[result1]++;		// adds the frequency to the array element that corresponds to the rolled number
		secondDie[result2]++;
	}

	displayPct(firstDie, DIE1_SIZE);
	displayPct(secondDie, DIE2_SIZE);

	return 0;
}

void displayPct(int dieArray[], int size)
{

	cout << "Stats for " << size << " sided die:" << endl;
	for (int count = 1; count <= size; count++)
	{
		cout << "Side   " << count << ":\t" <<
			fixed << showpoint << setprecision(2) << (dieArray[count] / 1000000.00) * 100.00 << "%" << endl;
	}
	cout << endl;
}