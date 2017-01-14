// iftest.cpp
//      purpose: report number of digits in an integer
//        shows: use of output, input, conditional statements
//         note: has bugs, needs work
//
//  modified by: Brendan Fahey	
//         date: 9/12/15
//

#include <iostream>
using namespace std;

int main()
{
	int input;

	cout << "Enter a number: ";
	cin  >> input;

	if (input >= 100 || input <= -100) {     //I hope it was ok to use || for "OR," I knew that from Java
		cout << "input has three or more digits" << endl;
	} else if (input >= 10 || input <= -10) {     //see above comment
		cout << "input has two digits" << endl;
	} else {
		cout << "input has one digit" << endl;
	}

	if ( input < 0) {
		cout << "and input is negative" << endl;
	}
        return 0;
}
