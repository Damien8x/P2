// Author: Damien Sudol
// Filename: EncryptWord P2
// Date: 10/16/2017
// Version: 1.1

#include "FindFault.h"
// Definition: class designed to implement all features laid out in FindFault.h, with focus on containment, composition and class maintenance.
// class is responsible for encapsulating several distinct EncryptWord objects using a dynamic array, with a size assigned by application. A FindFault object
// will be capable of encryption and decryption by utilizinig the EncryptWord class, through composition. Class will also add a notion of corruption, which
// will be identified after the application determines the correct shift value used in encryption. The FindFault.comparePhrase() methodd will detect
// corruption by comparing values of decrypted encryption and orignal phrase, prior to encyption. Class will provide responsive feedback to clients attempts
// at determining the shift key value, thus aiding in the detection of corruption. All queries in the attempt to determine the key value will be tracked
// and available to the application through the help of the EncryptWord class. Upon completion of the program all memory assigned to the heap will be properly 
// managed to assure no memory leaks have been left present.


//FindFault.cpp constants are used to enhance readability and avoid hard coding.
const int NO_CORRUPTION = 5;
const int CORRUPTION = 6;

// class attributes
int arraySize;
EncryptWord * ewArray;
string * phraseArray;

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

// Definition: creates dynamic array to size specified by application from FindFault.setArraySize() method, if ewArray has NULL value.
// adds EncryptWord object at position of current encryption, as specified by passed argument to FindFault.encrypt() method.
// precondition: Legally accepts unsigned integer argument no larger than current value of getArraySize()
// postcondition: may create dynamic array in heap memory, pointed to by ewArray pointer. Will add object to ewArray array.
void FindFault::addEW(int position) {
	EncryptWord ew;
	if (ewArray == NULL) {
		ewArray = new EncryptWord[getArraySize()];
		ewArray[0] = ew;
	}
	else 
		ewArray[position - 1] = ew;	
}

// Definition: creates dynamic array to size specified by application from FindFault.setArrraySize() method, if phraseArray has Null value.
// designed for method access to compare decrypted phrase to  original, testing for corruption. adds phrase at position of current object calling
// FindFault.encrypt() method. 
// precondition: Legally accepts type string and unsigned integer no larger than current value of getArrarySize()
// postconditioin: may create dynamic array in heap memory, pointed to by phraseArray pointer. Will add string "phrase" to phraseArray array.
void FindFault::addPhrase(string phrase, int position) {
	if (phraseArray == NULL) {
		phraseArray = new string[getArraySize()];
		phraseArray[0] = phrase;
	}
	else 
		phraseArray[position - 1] = phrase;
}

// Definition: mutator member function, responsible for setting class attribute arraySize to size of argument. ArraySize may be set multiple times prior to call
// of FindFault.encrypt(), after which, the dynamic array has been set to size and will no longer be influenced by the method.
// precondition: no prior call to FindFault.encrypt(). Legally accepts unsigned integer value above 0.
// modify: changes value of attribute arraySize.
// postcondition: arraySize set to argument value.
void FindFault::setArraySize(int size)  {
	this->arraySize = size;
}

// Definition: responsible for adding element of possible corruption to EncryptWorld object encryption. Using the length of phrase to be encrypted as the 
// precursor to whether corruption will occur.
// precondition: legal argument of type string passed from FindFault.encrypt() method.
// postcondition: original argument may or may not be corrupted by method and then returned to FindFault.encrypt() method.
string FindFault::corruptionPossible(string phrase) {
	if (phrase.length() % 2 == 0) {
		// insert Corruption
		return phrase;
	}else
	return phrase;
}

// Definition: method call triggered by application succesful identification of shift value. compares returned decrypted phrase from EncryptWord object
// to original phrase, determining if corruption had occured. Return values will be passed to FindFault.detectCorruption() method.
// precondition: legally accepts unsigned integer value between 1 and the value of ewArray.length();
// postcondition: returns either 5 (no corruption) or 6 (corruption).
int FindFault::comparePhrases(int phraseNumber) const{
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
