#include <iostream>

/* 
 *   3wordsort.cpp -- program to print out three words in alpha order
 *
 *   usage:  ./3wordsort
 *   input:  three words
 *   output: the three words in alphabetical order, separated by spaces
 *   note:   Do not prompt the user; Do not print explanations on output.
 *           In fact, don't modify main().
 *  
 *  modified by: Brendan Fahey
 *  modified on: 9/17/15
 */

using namespace std;

void printInOrder(string s1, string s2, string s3);

int main()
{
	string	w1, w2, w3;		// input values
	
	cin >> w1 >> w2 >> w3;		// read in three values
	printInOrder(w1, w2, w3);	// function does not return anything

	return 0;
}

//
// printInOrder() prints out the three words in alpha order
//		  with spaces between them, no return value
//
void printInOrder(string x, string y, string z)	
{
	string swap = "";

	if (y < x) {
		swap = x;
		x = y;
		y = swap;
	}

	if (z < x) {
		swap = x;  //these statements all serve to sort the strings
		x = z;
		z = swap;
	}

	if (z < y) {
		swap  = y;
		y = z;
		z = swap;
	}

	cout << x << " " << y << " " << z << endl;

	// your function does NOT use return
	// Instead, it sends values to cout, separated by spaces
	// followed by an endl.
        // Just print the 3 strings as described in the assignment
        // with no extra stuff.
}
