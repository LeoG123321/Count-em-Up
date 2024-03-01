#include "GroceryCounter.h"
#include <string>
using namespace std;

GroceryCounter::GroceryCounter() {
	tens_digit = 0;
	ones_digit = 0;
	tenths_digit = 0;
	hundreths_digit = 0;
	overflow = 0;
}

void GroceryCounter::tens() {
	if (tens_digit == 9) {
		tens_digit = 0;
		number_of_overflows();
	}
	else {
		tens_digit++;
	}
}

void GroceryCounter::ones() {
	if (ones_digit == 9) {
		ones_digit = 0;
		tens();
	}
	else {
		ones_digit++;
	}
}
void GroceryCounter::tenths() {
	if (tenths_digit == 9) {
		tenths_digit = 0;
		ones();
	}
	else {
		tenths_digit++;
	}
}
void GroceryCounter::hundreths() {
	if (hundreths_digit == 9) {
		hundreths_digit = 0;
		tenths();
	}
	else {
		hundreths_digit++;
	}
}

string GroceryCounter::total(){
	string temp = "$";
	temp += tens_digit + ones_digit;
	temp += ".";
	temp += tenths_digit + hundreths_digit;
	return temp;
}

int GroceryCounter::number_of_overflows() {
	overflow++;
	hundreths();
}

void GroceryCounter::clear() {
	tens_digit = 0;
	ones_digit = 0;
	tenths_digit = 0;
	hundreths_digit = 0;
	overflow = 0;
}