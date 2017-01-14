// Brendan Fahey
//11/20/15
//LanguageArray.cpp
//implementation file for LanguageArray class
//stores a dynamic array of distinct Language
//objects

#include "LanguageArray.h"
using namespace std;
#include <math.h>
#include<iostream>

//function: LanguageArray
//constructor - initializes variables
//parameters: none
//returns: none, void
LanguageArray::LanguageArray() {
	length = 0;
	maxLength = 0;
	arr = NULL;
}

//function: get_length
//a getter for the length of the LanguageArray
//parameters: none
//returns: int - the length
int LanguageArray::get_length() {
	return length;
}

//function: at
//works like [] for LanguageArrrays
//parameters: an integer index
//returns: the Language at that index
Language LanguageArray::at(int i) {
	return arr[i];
}

//function: add
//adds a Language to the LanguageArray
//parameters: Language
//returns: none, void
void LanguageArray::add(Language l) {
	for (int i = 0; i < length; i++) {
		if (arr[i].getName() == l.getName()) {
			arr[i].addVector(l.getVectorAt(0));
			return;
		}
	}
	if (length + 1 > maxLength) {
		expand();
	}
	arr[length] = l;
	length++;
}

//function: expand
//expands the dynamic array using pointers
//parameters: none
//returns: none, void
void LanguageArray::expand() {
	Language* temp = new Language[maxLength*2+1];
	for (int i = 0; i < length; i++) {
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
	maxLength *= 2;
	maxLength++;
}

//function: consolidate
//calls the consolidate function of the language itself for each language
//parameters: none
//returns: none, void
void LanguageArray::consolidate() {
	for (int i = 0; i < length; i++){
		arr[i].consolidate();
	}
}

//function: computeProbs
//computes the probability for each language
//parameters: a double array, a string array, the index of the unknown 
//		language
//returns: nothing, void (modifies the arrays)
void LanguageArray::computeProbs(double p[], string l[], int unknown) {
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (i != unknown) {
			p[count] = doMath(arr[unknown],arr[i]);
			l[count++] = arr[i].getName();
		}
	}
}

//function: doMath
//performs cosine similarity operations on two languages
//parameters: an unknown language, then the language to compare it to 
//returns: a double, the similarity
double LanguageArray::doMath(Language unknown, Language language) {
	double numerator = 0;
	double denominator;
	double dleft = 0;
	double dright = 0;
	TrigramVector unknownTri = unknown.getVectorAt(0);
	TrigramVector languageTri = language.getVectorAt(0);
	for (int i = 0; i < unknownTri.get_length(); i++) {
		string tri = unknownTri.at(i);
		numerator+=unknownTri.get_frequency(tri)*languageTri.get_frequency(tri);
		dleft += pow(unknownTri.get_frequency(tri),2);
		dright += pow(languageTri.get_frequency(tri),2);
	}
	for (int i = 0; i < languageTri.get_length(); i++) {
		string tri = languageTri.at(i);
		if (unknownTri.get_frequency(tri) == 0) 
			dright += pow(languageTri.get_frequency(tri),2);
	}
	dleft = sqrt(dleft);
	dright = sqrt(dright);
	denominator = dleft*dright;
	cout << "numerator: " << numerator << endl;
	cout << "denominator: " << denominator << endl;
	return numerator/denominator;
}

//function: totalTrigrams
//finds the total number of trigrams from 2 languages
//parameters: any two languages
//returns: their total number of trigrams
double LanguageArray::totalTrigrams(Language l1, Language l2) {
	return l1.getVectorAt(0).get_length() + l2.getVectorAt(0).get_length();
}
