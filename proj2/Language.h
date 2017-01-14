// Brendan Fahey
//11/13/15
//Language.h
//header file/class definition for Language.cpp
//Language objects hold multiple trigram vectors and a name

#ifndef LANGUAGE_H
#define LANGUAGE_H
#include "TrigramVector.h"
#endif

class Language {
private:
	std::string name;
	int length;
	int maxLength;
	TrigramVector* arr;
	void expand();
public:
	Language();
	Language(std::string);
	void addVector(TrigramVector);
	std::string getName();
	TrigramVector getVectorAt(int);
	void consolidate();
	int get_length();
};
