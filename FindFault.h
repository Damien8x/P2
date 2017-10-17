// Author: Damien Sudol
// Filename: EncryptWord P2
// Date: 10/16/2017
// Version: 1.1
#pragma once
#include <iostream>
#include "EncryptWord.h"
using namespace std;
// Description: class aims to provide functions in a logical, efficient format, capable of encrypting, and containing multiple objects which are passed strings greater than 3 characters, using a caesar cryptic shift.
// In addition, class provides necessary functions to fascilitate a guessing game from passed data in relation to the shift value used during encryption. Upon
// identifying the correct shift value, helper methods will determine if corruption had occured during encryption.
// Statistics are also provided for query attempts to determine the shift key and corruption. Minimal error handling provided through the class.
// Error handling on the application side will be necessary to maintain integrity of the program. Access to the encrypt() method 
// will be dependent on the internal state of the object, details  of dependencies are presented and defined below for the encrypt() method. 
//
// Assumptions: class will be utilized for its intended purporse of encryption followed by an interactive guessing game which provides statitical feedback. Failure to succesfuly encrypt
// a phrase prior to calling checkShift() method or any accesor methods will yield insignifcant data.  Error handling will consist of pre-determined return values stated below, indicating errors have occured.
// Application programmers must handle, and review all preconditions to avaoid improper data and ensure object integrety.  All public funtions are necessary for 
// succesful implementation of the classes intended use. Please review all definitions, pre and post conditions outlined below.

class FindFault
{
public:
	// Definiton: Class constructor, takes no arguments. Set's object to stable initial state. Necessary for access to public methods.
	// precondition: constructor accepts no arguments. state of object is not applicable prior to call.
	// postcondition: object initialized with default values.  All object attributes are private and cannot be directly accessed.
	FindFault();
	// Definition: Returns size of array associated with the number of EncryptWord objects held. Default value of 0.
	// precondition: Will return a default of 0 if array size has not been set by user.
	// postcondition: returns length of array containing EncryptWord objects.
	int getArraySize() const;
	// Definition: method accepts argument of type string, with a minimum of 4 characters. passed string will be returned as an encrypted string, pending condtions are met. encryption 
	// will shift characters according to the "shift", a randomly generated value between 1 and 9. if "shift" value is equal to "3" all characters of passed string will
	// increment by "3" according to associated ascii value, and returned as the newly associated character; for instance, the character 'a' = 97(ascii value) will shift 3 and returned as 
	// 'd' = 100(ascii). If character in passed string is "shifted" beyond the english alphabet, according to new ascii value, shift will wrap back to beginning of alphabelt; for instance, the character 'y' = 121(ascii value) with  
	// a shift of "3" will be returned as "b"= 98 (ascii value). any characters of passed string outside of english alphabelt, including numbers and special characters, will 
	// shift without wrapping, aside from empty spaces, which will be returned equal to themselves.  If encryption takes place, internal states will change and reuse of the function will be disabled,
	// getPhrase() will return the encrypted phrase until either checkShift() is passed the value equal to the encrypted shift value provided. 
	// precondition: method accepts two arguments of type string, and integer.The integer value will correspond to the associated object to modify, related to the users chosen array size of EncryptWord objects per the setArraySize() function.
	// String argument requires a minimum of 4 characters for succesful encryption. Succesful encryption will disable re-use of the function and set the return
	// value of getPhrase() to the newly encrypted phrase. If one of two conditions are met; objectReset() is called or the "shift" value is passed to the checkShift() method, the encrypt() method will be unlocked.
	// postcondition: returns encrypted version of argument according to the associated shift value. A string return of -1 indicates minimal size of argument is not met. A return value of -2 indicates encryption has been disabled.
	string encrypt(string, int);
	// Definition: assumed that method will be used as a tool to determine value of the encryption "shift" used in encrypt(string). method has five possible integer return values
	// which relate to the integer values passed to method and the current EncryptWord "shift" value. -1 will be returned if passed argument is less than "shift" value,
	// 1 will be returned if passed argument is greater than "shift" value, value 2 will be returned if argument is invalid or out of bounds, value of 6 will be returned if shift value
	// has been correctly identified but corruption has occured during encryption, value of 5 will be returned if the shift key has been correctly identified and no corruption has occured.
	// Returned value can be utilized in application to guide user's guesses towards the "shift value". 
	// detectCorruption method tracks data, keeping track of every query until shift is identified and corruption determined.
	// Out of bounds or invalid integer arguments will return a value of 2, indicating an error, and must be handled by the application programmer.
	// Method accepts two integer arguments, firt relating to the associated object and the second, the users "guess" of shift value. 
	// precondition: User must set arraySize prior to method call, as well as call to the encrypt() method for associated object.
	// legal arguments: first integer must be of value associated to object which has called the encrypt() method.
	// second integer argument must be between 1 and 9 or a return value of 2 must be handled.
	// postcondition: return integer value of -1, 1, 2, 5, 6 
	int detectCorruption(int, int);
	// Definition: returns number of calls to detectCorruption() method for each independant EncryptWord object.
	// precondition: integer argument is the position of the intended object to query against in the ewArray.
	// postcondition: returns an integer value.
	int checkQueryAttempts(int);
	// Definition: integral method to class which dictates the size of the dynamic array used to encapsulate EncryptWord objects.
	// precondition: accepts unsigned integer value
	// postcondition: attribute arraySize will be set to the value of passed argument.
	void setArraySize(int);
	~FindFault();

private:
	int arraySize;
	EncryptWord * ewArray;
	string * phraseArray;
	string phrase;
	void addEW(int);
	void addPhrase(string, int);
	string corruptionPossible(string);
	int comparePhrases(int);
	
};
