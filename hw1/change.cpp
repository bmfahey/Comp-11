// Brendan Fahey
// Program: change.cpp
// Purpose: to display the correct amount of change to the user
// Date: 9/12/15

#include<iostream>
using namespace std;

int main(){
	int change; //amount entered by the user
	cout << "Amount of change in cents? ";
	cin >> change;
	int quarters = change/25;	//I've usually been taught to initialize variables when I declare
	change -= 25*quarters;		// but I don't know what the convention is in this class
	int dimes = change/10;
	change -= 10 * dimes;	       // I probably would've used WHILE loops but I don't know those in C++ yet
	int nickels = change/5;
	change -= 5 * nickels;		// The homework suggested using modulus operators but I wanted a challenge
	// no need to calculate pennies, that's what's left!

	cout << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, " << change << " pennies" << endl;

		return 0;
}
