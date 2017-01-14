// Brendan Fahey
//11/13/15
//langdetmain.cpp
//the main file for Project 2- Language Determination
//accepts input in the form of files, determines the 
//language using probability, displays sorted order
//of languages

#include "LanguageArray.h"
#include <iomanip>
#include <fstream>
#include <iostream>
using namespace std;

void receive_input(LanguageArray*);
void compute_probability (LanguageArray*);
void read_file(string, string, LanguageArray*);
void toTrigrams(string, string[]);
string formatString(string);
string remove(string, int);
void sort(string[],double[],int);

int main() {
	LanguageArray* languages = new LanguageArray;
	receive_input(languages);
	compute_probability(languages);
	return 0;
}

//function: receive_input
//gets the file that has the titles and filenames
//parameters: LanguageArray languages (empty array)
//returns: LanguageArray (now filled)
void receive_input(LanguageArray* languages) {
	string title, filename;
	while (cin >> title >> filename) {
		read_file(title, filename, languages);
	}
}
		
//function: read_file
//reads in a file as a string. Stores appropriate trigrams in a TrigramVector
//will eventually also store it in language, and those in LanguageArray
//parameters: string title (eg "English") string filename, LanguageArray
//returns: filled LanguageArray
void read_file(string title, string fName, LanguageArray* languages) {
	if (title == "Unknown")
		cout<< fName << endl;
	ifstream finput;
        finput.open(fName.c_str());
	string file = "";
	char c;
	while (finput.get(c)) {
		file += c;
	}
	file = formatString(file);
	string* trigrams = new string[(int)file.length()-2];
	toTrigrams(file,trigrams);
	TrigramVector vector;
	for (int i = 0; i < (int)file.length()-2; i++) {
		vector.insert(trigrams[i]);
	}
	delete[] trigrams; //trigrams was a pointer
	Language l(title);
	l.addVector(vector);
	languages->add(l);
}

//function: toTrigrams
//takes a formatted string and converts it into an array of trigrams
//parameters: formatted string str, an array of strings (empty)
//returns: nothing (but populates trigrams)
void toTrigrams(string str, string trigrams[]) {
	string temp = "";
	for (int i = 0; i < (int)str.length()-2; i++) {
		temp = temp + str[i] + str[i+1] + str[i+2];
		trigrams[i] = temp;
		temp = "";
	}
}

//function: formatString
//takes out spaces, non-alphabetic characters, etc
//parameters: string str
//returns: formatted string
string formatString (string str) {
	for (int i = 0; i < (int)str.length(); i++) {
		if (!isalpha(str[i]) && !isspace(str[i])) {
			str = remove(str,i);
			i--;  //on purpose: to catch consecutive bad chars
		}
		str[i] = tolower(str[i]);
		if (isspace(str[i])) {
			str[i] = ' ';
		}
	}

	for (int i = 0; i < (int)str.length()-1; i++) {
		if (isspace(str[i]) && isspace(str[i+1])) {
			str[i] = ' ';
			str = remove(str,i+1);
			i--; //see above
		}
	}
	return str;
}

//function: remove
//removes the given index from a string
//parameters: string, index of string to be removed
//returns: string with character removed
string remove(string str, int index) {
	string temp = "";
	for (int i = 0; i < index; i++) {
		temp += str[i];
	}
	for (int i = index+1; i < (int)str.length(); i++) {
		temp += str[i];
	}
	return temp;
}

//function: compute_probability
//computes the probability for each language and displays them
//parameters: a LanguageArray
//returns: none, void
void compute_probability(LanguageArray* languages) {
	languages->consolidate();
	int index, i = 0;
	while (i < languages->get_length()) {
		if (languages->at(i).getName() == "Unknown") {
			index = i;
		}
		i++;
	}
	double* probabilities = new double[languages->get_length()-1];
	string* languageNames = new string[languages->get_length()-1];
	languages->computeProbs(probabilities, languageNames, index);
	sort(languageNames, probabilities, languages->get_length()-1);
	for (int i = 0; i < languages->get_length()-1; i++) {
		cout<<"\t"<<setw(10)<<languageNames[i]<<": "<<probabilities[i]<<endl;
	}
}

//function: sort
//sorts the two arrays from highest to lowest based on the nums
//Selection Sort?
//parameters: a string[], a double[], and their length
//returns: none, void
void sort(string names[], double prob[], int len) {
	double tempProb;
	string tempName;
	for (int i = 0; i < len; i++) {
		for (int j = i; j < len; j++) {
			if (prob[j] > prob[i] ) {
				tempProb = prob[j];
				prob[j] = prob[i];
				prob[i] = tempProb;
				tempName = names[j];
				names[j] = names[i];
				names[i] = tempName;
			}
		}
	}
}
