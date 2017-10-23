// Author: Damien Sudol
// Filename: EncryptWord P2
// Date: 10/16/2017
// Version: 1.1

#ifndef FINDFAULT_H
#define FINDFAULT_H

#include "EncryptWord.h"
#include <iostream>
#include <string>
using namespace std;
// Description: class aims to provide functions in a logical, efficient format, capable of encrypting and containing multiple objects which are passed strings greater than 3 characters, using a caesar cryptic shift.
// In addition, class provides necessary functions to fascilitate a guessing game from passed data in relation to the shift value used during encryption. Upon
// identifying the correct shift value, helper methods will determine if corruption had occured during encryption.
// Statistics are also provided for query attempts to determine the shift key and corruption. Minimal error handling provided through the class.
// Error handling on the application side will be necessary to maintain integrity of the program. Access to the encrypt() method 
// will be dependent on the internal state of the object, details  of dependencies are presented and defined below for the encrypt() method. 
// Legal States ON (setArraySize(int) set to unsigned integer of 1 or greater for class functionality.
// Legal States OFF(setArraySize(int) has not been set to an integer of 1 or greater.
// FindFault.getArraySize() can be used to determine the state of a FindFault object. 
//
// Assumptions: class will be utilized for its intended purpose, first and foremost by providing a FindFault object with the desired amount of EncryptWord objects 
// to be created and stored, by using the FindFault.setArraySize() method.
// Array size must be set prior to any encryption. Once encryption has been called the array will be set to the argument last provided to FindFault.setArraySize().
// This means the number of objects for the given FindFault object will be locked in after the first FindFault.encrypt() method is called. After size of array has been set
// encryption of any distinct object will be permitted, followed by an interactive guessing game which provides statitical feedback for each contained EncryptWord object. Failure to succesfuly encrypt
// a phrase prior to calling FindFault.detectCorruption() method or any accesor methods will yield insignifcant data.  Error handling will consist of pre-determined return values stated below, indicating errors have occured.
// Application programmers must handle, and review all preconditions to avaoid improper data and ensure object integrety.  All public funtions are necessary for 
// succesful implementation of the classes intended use. Please review all definitions, pre and post conditions outlined below.
// 
// State Transitions
// OFF-> OFF (constructor -> getNumberOfElements())
// OFF-> OFF (constructor-> getQueryAttempts())
// OFF-> ON (constructor -> encrypt())
// ON-> ON (encrypt() -> getQueryAttempts())
// ON-> ON (encrypt() -> encrypt())
// ON-> ON (Encrypt() -> getNumberOfElements())
// ON-> ON (encrypt() -> detectCorruption()) 
// 


class FindFault
{
public:
	// Definiton: Class constructor, takes no arguments. Set's object to stable initial state. Necessary for access to public methods.
	// precondition: constructor accepts no arguments. state of object is not applicable prior to call.
	// postcondition: object initialized with default values.  All object attributes are private and cannot be directly accessed.
	FindFault();
	// Definition: returns number of EncryptWord objects contained in FindFault class. Method should be referenced to determine
	// legal argument boundries for FindFault.decrypt() method, FindFault.detectCorruption() method. 
	// precondition: none
	// postcondition: FindFault object not impacted. 
	int getNumberOfElements() const;
	// Definition: takes in string, returns encrypted string via creation of EncryptWord object and call to EncryptWord.encrypt() method. 
	// For all queries for related element, a call to FindFault.getNumberOfElements() prior to any additional calls to FindFault.encrypt() method
	// will return the positon associated with THIS object. 
	// precondition: object may or may not be ON. string argument must be greater than 4 characters.
	// postcondition: FindFault.numberOfElements will increase by 1. New EncryptWord object will be created in heap memory. New string will be 
	// stored in heap memory.
	string encrypt(string);
	// Definition: returns number of calls to FindFault.detectCorruption() method, creating an up to date reference for corruption query attempts.
	// This method returns a value for ALL query calls to FindFault.detectCorruption method, not object specific.
	// precondition: none
	// postcondition: FindFault object not impacted. 
	int getQueryAttempts(bool) const;
	// Definition: detects whether corruption has occured during the encryption process. A return of true indicates no corruption has occured.
	// A return type of false indicates corruption has occured. Legal argument boundries: lower: greater than zero. upper: less than or equal to FindFault.getNumberOfElements()
	// precondition: object ON (getNumberrOfElements() > 0). argument is unsigned integer within legal bounds.
	// postcondition: FindFault.queryAttempts will increase by 1. 
	bool detectCorruption(int);
	// Defintion: returns FindFault contained EncryptWord object's decrypted string, associated with the passed argument. 
	// returned string may or may not have been corrupted during encryption. Legal argument boundries: lower: greater than zero. upper: less than or equal to FindFault.getNumberOfElements()
	// precondition: object ON (getNumberrOfElements() > 0). argument is unsigned integer within legal bounds.
	// postcondition: FindFault object not impacted.
	string decrypt(int) const;

	string printCorruption(int) const;
	// Definition: Destructor called at end of program to free up all heap allocated memory. Will delete both dynamic arrays from heap and set pointers 
	// to point to NULL.
	~FindFault();

private:
	void setNumberOfElements();
	int numberOfElements;
	void setQueryAttempts(bool);
	EncryptWord * ewArray;
	string * phraseArray;
	string phrase;
	void addEW();
	void addPhrase(string);
	string corruptionPossible(string);
	int corruptedEncryption;
	int encryptionNotCorrupted;
};

#endif