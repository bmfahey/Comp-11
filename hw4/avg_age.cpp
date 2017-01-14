//Brendan Fahey
//10/7/15
//avg_age.cpp
//Returns average age of people with a certain name
//Homework 4

#include<iostream>
using namespace std;

const int SPACE = 50001;
const int SENTINEL = -1;

void find_indices (int matchesarr[], string names[], string name, int len);
int compute_matches (string names[], string name, int len);
void compute_ages (int ages[], int len);
double avg (int ages[], int matchesarr[], int matches);

int main() {
	int y, pos = 0;
	string z; //y holds years, z holds names
	int ages[SPACE];
	string  names[SPACE];
	do {
		cin >> y;
		cin >> z;
		ages[pos] = y;
		names[pos++] = z;
		if (pos >= SPACE) {
			cout << "too much data" << endl;
			return 1;
	      	}
	} while (y != SENTINEL);
	string name;
	cout << "Enter a name: ";
	cin >> name;
	compute_ages(ages, pos); //changes to ages
	int matches = compute_matches(names, name, pos); //num of matches
	if (matches == 0) {
		cout << "name not found" << endl;
		return 0;
	}
	int matchesarr[matches]; //array of indices of matches
	find_indices(matchesarr, names, name, pos); //fills matchesarr
	double average = avg(ages,matchesarr, matches);
	cout << "average age = " << average << endl;
	return 0;
}

//function: compute_ages
//purpose: changes years into ages
//params: array of years, length of array
//returns: nothing, void			
void compute_ages(int ages[], int len) {
	for (int i = 0; i < len; i++) {
		ages[i] = 2015 - ages[i];
	}
//this function (and others) rely on the fact that arrays are passed
	//as reference, not value
}

//function:compute_matches
//purpose: to find the number of times the name appears
//params: array of names, name to check, length of array
int compute_matches(string names[], string name, int len) {
	int count = 0;	
	for (int i = 0; i < len; i++) {
		if (names[i] == name) {
			count++;
		}
	}
	return count;
}

//function:find_indices
//purpose: finds the indices of all matches and puts them into matchesarr
//params:matchesarr(empty),array of names, name to check,length of array
//returns: nothing, void
void find_indices(int matchesarr[], string names[], string name, int len) {
	int matchpos = 0;
	for (int i = 0; i < len; i++) {
		if (names[i] == name) {
			matchesarr[matchpos++] = i;
		}
	}
}

//function: avg
//purpose: calculate the average age of everyone with a certain name
//params: array of ages, array of match indices, number of matches
//returns: double, the average of ages 
double avg(int ages[], int matchesarr[], int matches) {
	double sum = 0;
	for (int i = 0; i < matches; i++) {
		sum += ages[matchesarr[i]];
	}
	return sum/matches;
}
