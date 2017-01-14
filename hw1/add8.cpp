// Brendan Fahey
// Program: add8.cpp
// Purpose: to add 8 floating point numbers and display the result to the user
// Date: 9/12/15

#include<iostream>
using namespace std;


// I can write this program using two variables, as the homework suggests less than eight


int main(){
	float input, total = 0;	// Initializing variables input (to get input) and total (to keep a running total).
				// the initializing was done because of a compiler warning
	cout << "Please enter eight numbers: ";
	cin >> input;
	total += input;
	cin >> input;
	total += input;
	cin >> input;
	total += input;
	cin >> input;
	total += input;
	cin >> input;
	total += input;
	cin >> input;
	total += input;
	cin >> input;
	total += input;
	cin >> input;
	total += input;

	// I know that those lines could have been greatly simplified by a "FOR" loop
	// but I don't know how to do that in C++, only Java and Python

	cout << "The total is: " << total << endl;

	return 0;
}

// questions:
// the interface of the program is the part that the user can see and interact with
//no, the user cannot tell how many varables the program has by using it
