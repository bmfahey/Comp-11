// Brendan Fahey
// Program: yoda.cpp
// Purpose: To rearrange words in a sentence (and sound like Yoda)
// Date: 9/12/15

#include<iostream>
using namespace std;

int main(){
	string word1,word2,word3,word4; //these are the four words of the sentence
	cout << "Type in four words: ";
	cin >> word1;
	cin >> word2;
	cin >> word3; //these lines input all four words
	cin >> word4;
	cout << word4 << " "  << word3 << " "  << word2 << " "  << word1 << endl; //displays words in reverse order with spaces
	return 0; 
}
