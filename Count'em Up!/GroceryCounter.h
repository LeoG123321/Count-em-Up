#pragma once
#include <string>
using namespace std;

class GroceryCounter
{
private:		
	int tens_digit;
	int ones_digit;
	int tenths_digit;
	int hundreths_digit;

public:
	GroceryCounter();	//Default Constructor

	void tens();	//Adds 1 in the tens place, $10.00
	void ones();	//Adds 1 in the ones place, $01.00
	void tenths();	//Adds 1 in the tenths place, $00.10
	void hundreths();	//Adds 1 in the hundreths place, $00.01

	std::string total();	//Returns the counter amount in money notation, "$10.00"
	int number_of_overflows();	//Counts number of times the user overflowed the counter

	void clear();	//Sets everything back to 0
};

