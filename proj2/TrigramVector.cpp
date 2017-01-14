// Brendan Fahey
//TrigramVector.cpp
//This is the implementation of the TrigramVector
//class. It makes dynamic arrays of trigrams, and
//implements some searching and sorting to make 
//it faster.
//11/20/15

#include <iostream>
#include "TrigramVector.h"
#include <string>
using namespace std;

const int INITIAL_SIZE = 1;
const string DEFAULT_STR = "zzz";

//function:TrigramVector
//constructor - initializes variables
//parameters: none
//returns: nothing, void
TrigramVector::TrigramVector() {
	maxLength = INITIAL_SIZE;
	length = 0;
	trigrams = new string[maxLength];
	frequencies = new double[maxLength];
	trigrams[0] = DEFAULT_STR;
	frequencies[0] = 0;
}

//function: get_frequency
//get the frequency of a given trigram
//parameters: string trigram
//returns: int - frequency of trigram if it exists, 0 if it doesn't
double TrigramVector::get_frequency(string trigram) {
	if (search(trigram) != -1) {
		return frequencies[search(trigram)];
	}
	else
		return 0;
}

//function: insert
//inserts a given trigram into an array at the correct position
//parameters: string - trigram to be inserted
//returns: nothing, void
void TrigramVector::insert(string trigram) {
	if (length == 0) {
		trigrams[0] = trigram;
		frequencies[0] = 1;
		length = 1;
	}
	else if (search(trigram) == -1) { //if it doesn't exist
		int test = 0;
		while (test < length && trigrams[test] < trigram) {
			test++; //finding correct place to put it
		}
		bump(test); //moving everything one to the right
		trigrams[test] = trigram;
		frequencies[test] = 1;
		length++;
	}
	else { //if it does exist
		frequencies[search(trigram)] ++;
	}
}

//function: search
//finds the given trigram
//parameters: string - trigram to be found
//returns : int - index of trigram if it exists, -1 if it doesn't
int TrigramVector::search(string trigram) {
	if (length == 1) {
		if (trigram == trigrams[0])
			return 0;
		else 	
			return -1;
	}
	int max = length-1;
	int min = 0;
	while (max-min >= 0) {
		if (trigrams[max] == trigram) {
			return max;
		}
		else if (trigrams[min] == trigram) {
			return min;
		}
		else if (trigrams[(max+min)/2] == trigram) {
			return (max+min)/2;
		}
		else if (trigrams[(max+min)/2] < trigram) {
 			min = (max+min)/2 + 1;
		}
		else {
			max = (max+min)/2 - 1;
		}
	}
	return -1;
}

//function: bump
//"bumps" everything one to the right, starting at the index
//parameters: int start, where the bumping should begin
//returns: nothing, void
void TrigramVector::bump(int start) {
	if (length + 1 > maxLength) {
		expand();
	}
	string stemp1 = trigrams[start];
	string stemp2;
	trigrams[start] = "aaa";
	for (int i = start + 1; i < length+1; i++) {
		stemp2 = trigrams[i];
		trigrams[i] = stemp1;
		stemp1 = stemp2;
	}
	int itemp1 = frequencies[start];
	int itemp2;
	frequencies[start] = 0;
	for (int i = start+1; i < length+1; i++) {
		itemp2 = frequencies[i];
		frequencies[i] = itemp1;
		itemp1 = itemp2;
	}
}

//function: expand
//expands the array to twice its current size using pointers
//parameters: none
//returns: nothing, void
void TrigramVector::expand() {
	string* temptri = new string[maxLength * 2];
	double* tempfreq = new double[maxLength * 2];
	for (int i = 0; i < length; i++) {
		temptri[i] = trigrams[i];
		tempfreq[i] = frequencies[i];
	}
	delete[] trigrams;
	delete[] frequencies;
	trigrams = temptri;
	frequencies = tempfreq;
	maxLength *= 2;
}

//function: at
//works like [] for a TrigramVector
//parameters: an integer index
//returns: a string, the trigram at that index
string TrigramVector::at(int i) {
	return trigrams[i];
}

//function: get_length
//gets the current length of the TrigramVector
//parameters: none
//returns: int - the length of the Vector
int TrigramVector::get_length() {
	return length;
}

//function: normalize
// divides entire vector by a factor
//parameters: a double - the factor
//returns: none, void
void TrigramVector::normalize(double factor) {
	for (int i = 0; i < length; i++) {
		frequencies[i] /= factor;
	}
}

//function:: print_freq
//added 11/24
//prints the frequency followed by the trigram
//parameters: none
//returns: void
//I realize that this does not meet the specifications for the project,
//I had completely finished before this requirement was added, and
//I would have had to change my entire working program to 
//make this work. Sorry!! I realize I'll lose points.
void TrigramVector::print_freq() {
	for (int i = 0; i < length; i++) {
		cout << frequencies[i] << "  " << trigrams[i] << endl;
	}
}
