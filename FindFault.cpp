// Author: Damien Sudol
// Filename: EncryptWord P2
// Date: 10/16/2017
// Version: 1.1

#include "FindFault.h"
//FindFault.cpp constants are used to enhance readability and avoid hard coding.
const int NO_CORRUPTION = 5;
const int CORRUPTION = 6;

// class attributes
int arraySize;
EncryptWord * ewArray;
string * phraseArray;

// default constructor setting initial state of object.
// all pointers set to NULL, arraySize set to 0
FindFault::FindFault()
{
	ewArray = NULL;
	phraseArray = NULL;
	arraySize = 0;
}

int FindFault::getArraySize() const{
	return arraySize;
}

string FindFault::encrypt(string phrase, int position) {

	
	addEW(position);
	addPhrase(phrase, position);
	phrase = corruptionPossible(phrase);
	phrase = ewArray[position - 1].encrypt(phrase);
	return phrase;
}

int FindFault::detectCorruption(int objectNumber, int guess) {
	int relativeShift = ewArray[objectNumber - 1].checkShift(guess);
	if (relativeShift == 0) {
		int corruption = comparePhrases(objectNumber-1);
		return corruption;
	}else
	return relativeShift;
}

int FindFault::checkQueryAttempts(int objectNumber) {
	int queryAttempts = ewArray[objectNumber-1].getGuessCount();
	return queryAttempts;
}

// Definition: method responsible for creating array to size specified in application and assigns
// object
void FindFault::addEW(int position) {
	EncryptWord ew;
	if (ewArray == NULL) {
		ewArray = new EncryptWord[getArraySize()];
		ewArray[0] = ew;

	}
	else 
		ewArray[position - 1] = ew;
	
}

void FindFault::addPhrase(string phrase, int position) {
	if (phraseArray == NULL) {
		phraseArray = new string[getArraySize()];
		phraseArray[0] = phrase;
	}
	else 
		phraseArray[position - 1] = phrase;
}

void FindFault::setArraySize(int size)  {
	this->arraySize = size;
}

string FindFault::corruptionPossible(string phrase) {
	if (phrase.length() % 2 == 0) {
		// insert Corruption
		return phrase;
	}else
	return phrase;
}

int FindFault::comparePhrases(int phraseNumber) {
	if (ewArray[phraseNumber].getPhrase() == phraseArray[phraseNumber]) {
		return NO_CORRUPTION;
	} else
	return CORRUPTION;
}

FindFault::~FindFault()
{
	delete ewArray;
	ewArray = nullptr;
	delete phraseArray;
	phraseArray = nullptr;
}
