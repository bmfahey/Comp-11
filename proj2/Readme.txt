Brendan Fahey
COMP11
Project 2
Due 12/2/15

Design:
	My design for this project is essentially a three-dimensional 
array. Each class is itself a dynamic array. The main program reads the 
files, in order. It translates them into TrigramVectors. 
These TrigramVectors are then put into Languages. Languages are then put 
into LanguageArrays. At the end of the program, the LanguageArray computes
the statistics and the main program displays the sorted output.
	TrigramVector: This class holds a one-dimensional array of strings.
The trigrams are sorted as they're put into the array. The sorting has an
efficiency of log(2)O. 
	Language: This class is built to hold all the members of a 
language. It can hold a dynamic array of TrigramVectors, so a language can 
have multiple Vectors. It also holds a name for the language, like "English"
for example. 
	LanguageArray: This class is designed to be a dynamic array 
that holds Language objects. It, like the other dynamic arrays, expands 
as needed. This is the class that handles all the math at the end of the
program. 

Preconditions: 
	The file that is sent in with the program must be names of
		languages followed by valid filenames that include
		text written in that language.
	All languages must have the Latin alphabet.
	Capitalization matters. "French" and "french" are not equal
	
Operating Instructions:
	You must send in a file in the format:
		Language	/file/path1.txt
		Language	/file/path2.txt
		Language	/file/path3.txt

	There should be no sentinels in the file.

	You can call the program with: ./program_name < testfile.txt

Technical Details:
	File Names:
		langdetmain.cpp
		TrigramVector.h
		TrigramVector.cpp
		Language.h
		Language.cpp
		LanguageArray.h
		LanguageArray.cpp

	To Compile (all on one line):
		clang++ -Wall -Wextra -g langdetmain.cpp 
			TrigramVector.cpp Language.cpp
			LanguageArray.cpp
