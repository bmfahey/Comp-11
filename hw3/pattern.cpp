//Brendan Fahey
//pattern.cpp
//Homework 3
//this program creates a pattern based on input from the user 
//9/24/15

#include <iostream>
using namespace std;
void draw_picture (string first_string, string second_string, int width);
void printchars (string s, int num);

int main()
{
	string first_string, second_string;
	int width;
	cout << "First string? ";     //output/input to fill variables
	cin >> first_string;
	cout << "Second string? ";
	cin >> second_string;	
	cout << "Width? ";
	cin >> width;
	draw_picture(first_string, second_string, width); //calls draw_picture
	return 0;
}

//function:draw_picture
//parameters:string first_string, string second_string, int width
//purpose: call printchars with correct arguments to print picture
//rules: width must be positive to work correctly
//returns: nothing, void
void draw_picture (string first_string, string second_string, int width)
{
	int nums_left = width;
	while (nums_left >= 2) //descending
	{
		printchars(first_string, nums_left);
		printchars(second_string, width-nums_left);
		nums_left -=2;
		cout << endl;
	}
	while (nums_left <= width) //ascending
	{
		printchars(first_string, nums_left);
		printchars(second_string, width-nums_left);
		nums_left +=2;
		cout << endl;
	}
}

//function: printchars
//parameters: string s, int num
//note: num must be positive
//purpose: print characters
//returns: nothing, void
void printchars (string s, int num)
{
	for (int i = 0; i < num; i++)
	{
		cout << s;
	}
}
