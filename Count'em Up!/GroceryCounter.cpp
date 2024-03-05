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
	//counts up by 1 in the tens digit, if it goes above 9, set to zero and count up by 1 in the overflow counter & in the hundreths counter
	if (tens_digit == 9) {
		tens_digit = 0;
		overflow++;
		hundreths();
	}
	else {
		tens_digit++;
	}
}

void GroceryCounter::ones() {
	//counts up by 1 in the hundreths digit, if it goes above 9, set to zero and count up by 1 in the tenths digit
	if (ones_digit == 9) {
		ones_digit = 0;
		tens();
	}
	else {
		ones_digit++;
	}
}
void GroceryCounter::tenths() {
	//counts up by 1 in the tenths digit, if it goes above 9, set to zero and count up by 1 in the ones digit
	if (tenths_digit == 9) {
		tenths_digit = 0;
		ones();
	}
	else {
		tenths_digit++;
	}
}
void GroceryCounter::hundreths() {
	//counts up by 1 in the hundreths digit, if it goes above 9, set to zero and count up by 1 in the tenths digit
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
	return overflow;
}

void GroceryCounter::clear() {
	tens_digit = 0;
	ones_digit = 0;
	tenths_digit = 0;
	hundreths_digit = 0;
	overflow = 0;
}