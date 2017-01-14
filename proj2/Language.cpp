// Brendan Fahey
//11/20
//Project 2
//Language.cpp
//Implementation file for the Language class.
//Stores and deals with Languages - can hold
//multiple trigram vectors and perform operations
//on them.

#include <iostream>
#include "Language.h"
#include <string>
using namespace std;

const string DEFAULT_NAME = "";
const int INITIAL_LENGTH = 1;

//function: Language
//constructor - initializes variables
//parameters: none
//returns: nothing, void
Language::Language() {
	name = DEFAULT_NAME;
	length = 0;
	maxLength = INITIAL_LENGTH;
	arr = new TrigramVector[maxLength];
}

//function: Language
//overloaded constructor - also sets the name of the Language
//parameters: string n
//returns: nothing, void
Language::Language(string n) {
	name = n;
	length = 0;
	maxLength = INITIAL_LENGTH;
	arr = new TrigramVector[maxLength];
}

//function: getName
//a getter for the name of the Language
//parameters: none
//returns: string - the name
string Language::getName() {
	return name;
}
 
//function: addVector
//adds a TrigramVector to the Language
//parameters: TrigramVector v
//returns: nothing, void
void Language::addVector(TrigramVector v){
	if (length+1 > maxLength) {
		expand();
	}
	arr[length] = v;
	length++;
}

//function: getVectorAt
//works like [], gets the vector at a given index
//parameter:
TrigramVector Language::getVectorAt(int i) {
	return arr[i];
}

//function: expand
//expands the dynamic array using pointers
//paramters: none
//returns: none, void
void Language::expand() {
	TrigramVector* temp = new TrigramVector[maxLength*2+1];
	for (int i = 0; i < length; i++) {
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
	maxLength = maxLength * 2 + 1;
}

//function: consolidate
//consolidates all trigramvectors into a single vector at space (0)
//parameters: none
//returns: none, void
void Language::consolidate() {
	for (int i = 1; i < length; i++) {
	  for (int j = 0; j < arr[i].get_length(); j++) {
	    for (int k=0; k<arr[i].get_frequency(arr[i].at(j)); k++) {
				arr[0].insert(arr[i].at(j));
			}
		}
	}
}

//function: get_length
//returns the length of the vector at space 0 (useful after 
//	consolidation has happened)
//parameters: none
//returns: an integer length
int Language::get_length() {
	return arr[0].get_length();
}
