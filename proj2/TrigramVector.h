// Brendan Fahey
//11/13/15
//TrigramVector.h
//this is the definition of the class TrigramVector
//TrigramVectors hold dynamic arrays of sorted trigrams

#include <string>

class TrigramVector {
private:
	int length;
	int maxLength;
	std::string* trigrams;
	double* frequencies;
	void bump(int);
	void expand();
//	void print_freq();
public:
	TrigramVector();
	double get_frequency(std::string);
	void insert(std::string);
	int search(std::string);
	std::string at(int);
	int get_length();
	void normalize(double);
	void print_freq();
};
