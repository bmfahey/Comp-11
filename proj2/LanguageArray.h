// Brendan Fahey
//11/13/15
//LanguageArray.h
//header file/class definition for LanguageArray.cpp
//LanguageArrays hold an array of Language objects

#ifndef LANGUAGEARRAY_H
#define LANGUAGEARRAY_H
#include "Language.h"
#endif

class LanguageArray {
private:
	int maxLength;
	Language* arr;
	void expand();
	int length;

	double doMath(Language, Language);
	double totalTrigrams(Language,Language);
public:
	LanguageArray();
	int get_length();
	void add(Language);
	Language at(int);
	void consolidate();
	void computeProbs(double[], std::string[], int);
};
