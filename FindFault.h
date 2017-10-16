#pragma once
#include <iostream>
#include "EncryptWord.h"
using namespace std;

class FindFault
{
public:
	FindFault();
	int getArraySize();
	string encrypt(string);
	int detectCorruption(int, int);
	int checkQueryAttempts(int);

private:
	int arraySize;
	EncryptWord * ewArray;
	string * phraseArray;
	string phrase;
	void addEW(EncryptWord&);
	void addPhrase(string);
	void setArraySize();
	string corruptionPossible(string);
	EncryptWord getEW(int);
	string getPhrase(int);
	int comparePhrases(int);
	~FindFault();
};

