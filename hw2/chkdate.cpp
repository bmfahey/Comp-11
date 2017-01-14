//Brendan Fahey
//9/17/15
//checkdate.cpp
//this program checks if dates are valid

#include <iostream>
using namespace std;

int check_month (int month);
int check_year (int year);	       //declarations of functions
int check_day (int month, int day, int leapyear);

int main() {
	int month, day, year;
	cin >> month >> day >> year;		//user input
	int date_true = 0;	// variable to store true/false 
	int leapyear = 0;	//true/false leap year
	if (year % 4 == 0 && year % 100 != 0)	//checking for leap year
	{
		leapyear += 1;
	}
	if (year % 400 == 0)
	{
		leapyear += 1;
	}
	date_true -= check_month(month);
	date_true -= check_year(year);	    //calls each checking function
	date_true -= check_day(month,day,leapyear);
	if (date_true < 0)
	{
		cout << "N" << endl;
	}     			//output
	else
	{
		cout << "Y" << endl;
	}
	return 0;
}

//check_month accepts int month and returns 1 if it is invalid
int check_month(int month) {
	if (month < 1 || month > 12)
	{
		return 1;
	}
	return 0;
}

//check_year accepts int year and returns 1 if it is invalid
int check_year(int year) {
	if (year < 1 || year > 9999)
	{
		return 1;
	}
	return 0;
}

//check_day accepts ints month, day, and leapyear and returns 1 if it is invalid
int check_day(int month, int day, int leapyear) {
	const int JAN = 1, FEB = 2, MAR = 3, APR = 4;
	const int MAY = 5, JUN = 6, JUL = 7, AUG = 8;
	const int SEP = 9, OCT = 10, NOV = 11, DEC = 12;
	if (month == SEP || month == APR || month == JUN || month == NOV)
	{
		if (day < 1 || day > 30)
		{
			return 1;
		}
		return 0;
	}

	if (month == JAN || month == MAR || month == MAY || month == JUL
		 || month == AUG || month == OCT || month == DEC)
	{
		if (day < 1 || day > 31)
		{
			return 1;
		}
		return 0;
	}

	if (month == FEB)
	{
		if (leapyear > 0)
		{
			if (day < 1 || day > 29)
			{
				return 1;
			}
			return 0;
		}
		else
		{
			if (day < 1 || day > 28)
			{
				return 1;
			}
			return 0;
		}
	}
	return 0;
}
