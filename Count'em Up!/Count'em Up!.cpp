/*
    Leonardo Gonzalez   3/1/2024

    Week 7              Count'em Up!
*/

#include <iostream>
#include <cassert>
#include "GroceryCounter.h"

using namespace std;

int main()
{
    GroceryCounter counter;

    cout << "Begin Tests..." << endl;
    
    cout << "\tChecking Default..." << endl;
    assert(counter.total() == "$00.00");
    
    cout << "\tTesting Counters..." << endl;
    for (int i = 0; i != 12; i++) {
        counter.hundreths();
    }
    assert(counter.total() == "$00.12");

    for (int i = 0; i != 10; i++) {
        counter.tenths();
    }
    assert(counter.total() == "$01.12");

    for (int i = 0; i != 14; i++) {
        counter.ones();
    }
    assert(counter.total() == "$15.12");

    for (int i = 0; i != 8; i++) {
        counter.tens();
    }
    assert(counter.total() == "$95.12");

    cout << "\tTesing Overflows..." << endl;
    counter.tens();
    assert(counter.total() == "$05.13");
    assert(counter.number_of_overflows() == 1);

    cout << "\tTesting Clearing..." << endl;
    counter.clear();
    assert(counter.total() == "$00.00");
    assert(counter.number_of_overflows() == 0);

    cout << "\tTesting Custom Constructor..." << endl;
    GroceryCounter custom_counter(5, 6, 7, 8);
    assert(custom_counter.total() == "$56.78");
    GroceryCounter custom_counter2(12, 32, 41, 6);
    assert(custom_counter2.total() == "$00.00");
    GroceryCounter custom_counter3(3, 13, 7, 24);
    assert(custom_counter3.total() == "$43.94");

    cout << "Testing Complete." << endl;
    return 0;
}

