#include "FindFault.h"
//CONSTANTS
const int NO_CORRUPTION = 5;
const int CORRUPTION = 6;

int arraySize;
EncryptWord * ewArray;
string * phraseArray;

FindFault::FindFault()
{
	ewArray = NULL;
	phraseArray = NULL;
	arraySize = 0;
}


int FindFault::getArraySize() {
	return arraySize;
}

string FindFault::encrypt(string phrase) {
	setArraySize();
	EncryptWord ew;
	addEW(ew);
	addPhrase(phrase);
	phrase = corruptionPossible(phrase);
	return phrase;
}

int FindFault::detectCorruption(int objectNumber, int guess) {
	int relativeShift = ewArray[objectNumber].checkShift(guess);
	if (relativeShift == 0) {
		int corruption = comparePhrases(objectNumber);
		return corruption;
	}else
	return relativeShift;
}

int FindFault::checkQueryAttempts(int objectNumber) {
	int queryAttempts = ewArray[objectNumber].getGuessCount();
	return queryAttempts;
}

void FindFault::addEW(EncryptWord& ew) {
	if (ewArray == NULL) {
		ewArray = new EncryptWord[1];
		ewArray[0] = ew;
	}
	else {
		EncryptWord* temp = ewArray;
		ewArray = new EncryptWord[getArraySize()];

		for (int i = 0; i < getArraySize(); ++i) {
			ewArray[i] = temp[i];
		}
		ewArray[getArraySize()] = ew;
		delete[] temp;
		temp = nullptr;
	}
}

void FindFault::addPhrase(string phrase) {
	if (phraseArray == NULL) {
		phraseArray = new string[1];
		phraseArray[0] = phrase;
	}
	else {
		string* temp = phraseArray;
		phraseArray = new string[getArraySize()];

		for (int i = 0; i < getArraySize(); ++i) {
			phraseArray[i] = temp[i];
		}
		phraseArray[getArraySize()] = phrase;
		delete[] temp;
		temp = nullptr;
	}
}

void FindFault::setArraySize() {
	this-> arraySize++;
}

string FindFault::corruptionPossible(string phrase) {
	if (phrase.length() % 2 == 0) {
		// insert Corruption
		return phrase;
	}else
	return phrase;
}

/*necessary???
EncryptWord FindFault::getEW(int ewNumber) {
	EncryptWord ew;
	return ew;
}

string FindFault::getPhrase(int phraseNumber) {
	string phrase;
	return phrase;
}
*/

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
