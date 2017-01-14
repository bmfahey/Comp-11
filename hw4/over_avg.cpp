//Brendan Fahey
//10/6/15
//over_avg.cpp
//Homework 4
//This program finds how many numbers in a set are over the average

#include <iostream>
using namespace std;

const int SENTINEL = 0;
const int SPACE = 30001;

double numsAvg(int nums[]);
int numsOver(int nums[], double average);

int main() {
	int pos = 0;
	int nums[SPACE];
	int y;

	do { //input until sentinel
		cin >> y;
		nums[pos++] = y;
		if (pos > SPACE) {
			cout << "too much input" << endl;
			return 1;
		}
	} while (y != SENTINEL);

	double avg = numsAvg(nums);
	int num = numsOver(nums, avg);
	cout << num << endl;
	return 0;
}

//function:avg
//returns average of array
//parameters: array of ints
//return type: double
double numsAvg(int nums[]) {
	int i = 0; //counter
	double sum = 0; //running sum
	while (nums[i] != SENTINEL) {
		sum += nums[i];
		i++;
	}
	return sum/i;
}

//function: num_over
//returns number of things greater than average
//parameters: array of numbers, double average
//returns: int
int numsOver(int nums[], double avg) {
	int over = 0;
	int i = 0;
	while (nums[i] != SENTINEL) {
		if (nums[i] > avg) {
			over ++;
		}
		i++;
	}
	return over;
}
