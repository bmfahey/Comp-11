//Brendan Fahey
//10/7/15
//most_frequent.cpp
//Homework 4
//This program finds the most frequent number(s) in a set

#include <iostream>
using namespace std;

const int SENTINEL = 0;
const int SPACE = 30001;

int freq_num(int nums[], int number, int len);
int highest_frequency(int nums[], int len);

int main() {
	int pos = 0;
	int nums[SPACE];
	int y;
	do { //input until sentinel
		cin >> y;
		nums[pos++] = y;
		if (pos >= SPACE && y != SENTINEL) {
			cout << "too much input" << endl;
			return 1;
		}
	} while (y != SENTINEL);
	int maxfrq = highest_frequency(nums, pos);
	for (int i = 0; i < pos; i++) {
		if (freq_num(nums, nums[i], pos)==maxfrq && nums[i]!=SENTINEL) {
			cout << nums[i] << endl;
			for (int j = 0; j < pos; j++) {	
				if (nums[i] == nums[j])
					nums[j] = SENTINEL;
//this was to ensure the same number wouldn't print over and over		
			}
		}
	}
	return 0;
}

//function:freq_num
//returns frequency of a number in an array
//parameters: array of ints, number to check, length of array
//return type: int
int freq_num(int nums[], int number, int len) {
	int count = 0;
	for (int i = 0; i < len; i ++) {
		if (nums[i] == number)
			count++;
	}
	return count;
}

//function: highest_frequency
//returns the highest frequency of number
//parameters: integer array, length of array
//returns: integer: highest frequency of numbers
int highest_frequency(int nums[], int len) {
	int freqs[len];
	for (int i = 0; i < len; i ++) {
		freqs[i] = freq_num(nums, nums[i], len);
	}
	int max = 0;
	for (int i = 0; i < len; i++) {
		if (freqs[i] > max)
			max = freqs[i];
	}
	return max; 
}
