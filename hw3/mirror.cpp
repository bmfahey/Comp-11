//Brendan Fahey
//mirror.cpp
//this program outputs a "mirror" whose length is defined by the user
//9/24/15
//Homework 3 Problem 2

#include <iostream>
using namespace std;

void print_mirror (int length);

int main ()
{
	int length;
	cout << "Maximum value? "; //output/input to get length
	cin >> length;
	print_mirror(length); //calls print_mirror and passes length
	return 0;
}

//function: print_mirror
//parameters: int length
//purpose: to print the mirror pattern
//returns: nothing, void
void print_mirror (int length)
{
	if (length < 0)
		return; //without this, negative inputs produced '|'
	for (int i = 0; i < 4; i++)
	{
		for (int j = length; j >= 0; j--)
		{
			cout << j; //descending
		}
		cout << "|";
		for (int j = 0; j <= length; j++)
		{
			cout << j; //ascending
		}
		cout << endl;
	}
}
 
