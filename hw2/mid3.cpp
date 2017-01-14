#include <iostream>

/* 
 *   mid3.cpp -- program to print out the middle of three input values
 *
 *   usage:  ./mid3
 *   input:  three doubles 
 *   output: the middle of the three input values
 *   note:   Do not prompt the user, do not print explanations on output.
 *           In fact, do not change main() at all, and don't use cin or
 *           cout in mid3().
 *  
 *  modified by: Brendan Fahey
 *  modified on: 9/15/15
 */

using namespace std;

double mid3(double n1, double n2, double n3);    // tell compiler about this

int main()
{
	// NOTE: DO NOT CHANGE ANYTHING IN main()!
        double  a, b, c;                // input values
        double  middle;                 // result
        
        cin >> a >> b >> c;             // read in three values

        middle = mid3(a, b, c);         // compute the middle

        cout << middle << endl;         // display it on the screen

        return 0;
}

//
// mid3() return the middle of three values passed as arguments
//
double mid3(double n1, double n2, double n3)
{
	double swap = 0;
	if (n2 < n1) {
		swap = n2;
		n2 = n1;    //all of this code is to sort numbers so 
		n1 = swap; // that n2 will be in the middle
	}

	if (n3 < n1) {
		swap = n3;
		n3 = n1;
		n1 = swap;
	}

	if (n2 > n3) {
		swap = n3;
		n3 = n2;
		n2 = swap;
	}

	return n2;
	
}
