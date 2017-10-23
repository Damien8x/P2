// Author: Damien Sudol
// Filename: EncryptWord P2
// Date: 10/16/2017
// Version: 1.1

#include "FindFault.h"
#include <iostream>
#include <string>
// Definition: Driver designed to test all public functions and legeal state transitions provided by the FindFault class with all possible inputs laid out per the 
// contract set in the FindFault.h documentation. Driver will create a FindFault object, assign an integer value to FindFault.arraySize(), followed by
// a call to the FindFault.encrypt() method, thus setting a limit to the number of EncryptWord objects contained in the FindFault object. Multiple, distinct
// FindFault objects will be created and maintained to ensure objects retain an independent identity and are not impacted by one another. 

void printIfElementCorrupted(FindFault&, int);
void addAndEncrypt(FindFault&, string);
void printNumberOfElements(FindFault&);
void printNumberOfQueries(FindFault&);

int main() {
	
	// Driver Welcome Message
	cout << "\n*************************************************\n*\t\t\t\t\t\t*\n*WELCOME TO FIND FAULT TEST DRIVER!!\t\t*\n""*CPSC 5011 PROJECT 2\t\t\t\t*\n"<<
		"*AUTHOR: DAMIEN SUDOL\t\t\t\t*\n*Version: 1.1\t\t\t\t\t*\n*\t\t\t\t\t\t*\n*************************************************" << endl;
	// call to FindFault constructor, creating FindFault object ff capable of accessing FindFault public methods
	// expected output n/a
	FindFault ff;
	// expected number of elements for object ff: 0
	cout << "Number of elements. expected output: 0" << endl;
	printNumberOfElements(ff);
	// expected number of queries for object ff: 0
	cout << "Number of queries. expected output: 0" << endl;
	printNumberOfQueries(ff);
	// expected number of elements for object ff: 1
	cout << "Encryption. expected output: encrypted string at position 1" << endl;
	addAndEncrypt(ff, "ABC123 abc123");
	// expected number of elements for object ff: 2
	cout << "Encryption. expected output: encrypted string at position 2" << endl;
	addAndEncrypt(ff, "Scoobie Doobie Doo");
	// check for encryption corruption for FindFault object ff at element position 1
	printIfElementCorrupted(ff, 1);
	// expected number of queries for object ff: 1
	cout << "print number of query calls to FindFault.detectCorruption() expected output: 1" << endl;
	printNumberOfQueries(ff);
	// check for encryption corruption for FindFault object ff at element position 2
	printIfElementCorrupted(ff, 2);
	// expected number of queries for object ff: 2
	cout << "print number of query calls to FindFault.detectCorruption() expected output: 2" << endl;
	printNumberOfQueries(ff);
	// print decrypted EncryptWord object's stored word which may or may not be corrupted
	cout << "Decryption. expected output to be decrypted string which may or may not be corrupted" << endl;
	cout << ff.decrypt(1) << endl;
	cout << "*************************************************" << endl;
	// create 2nd FindFault object, independent of existing FindFault object
	FindFault fff;
	// expected number of elements for object ff2: 0
	cout << "Number of elements for object 2. expected output: 0" << endl;
	printNumberOfElements(fff);
	// expected number of elements for object ff2: 1
	cout << "Encryption for object 2. expected output: encrypted string at position 1" << endl;
	addAndEncrypt(fff, "Testing that encryptioooon");
	// expected number of elements for object ff2: 2
	cout << "Encryption for object 2. expected output: encrypted string at position 2" << endl;
	addAndEncrypt(fff, "tst spcl kys !@#$%^&");

	printIfElementCorrupted(fff, 2);
	//expected total number of queries for object ff2: 1
	cout << "print number of query calls returning corruption and no corruption." << endl;
	printNumberOfQueries(fff);

	

	// returns formatted string for if corruption has occured for specific EncryptWord object encapsulated by FindFault object

	cout << ff.printCorruption(1) << endl;
	cout << "*************************************************" << endl;
	cout << fff.printCorruption(1) << endl;
	cout << "*************************************************" << endl;
	cout << ff.printCorruption(1) << endl;
	cout << "*************************************************" << endl;
	
	FindFault hh;
	addAndEncrypt(hh, "TESTING");
	cout<< hh.printCorruption(1) << endl;
	cout << "*************************************************" << endl;
	cout << fff.printCorruption(1) << endl;
	cout << "*************************************************" << endl;

	cin.get();
	return 0;
}

void printNumberOfQueries(FindFault& ffobject) {
	cout << "Number of queries detecting corruption:\t\t" << ffobject.getQueryAttempts(false) << endl;
	cout << "Number of queries with no corruption detected:\t" << ffobject.getQueryAttempts(true) << endl;
	cout << "*************************************************" << endl;
}

// Definition: Check number of elements (EncryptWord objects) stored by FindFault object
// precondition: none
// modify: none
// expected output: Number of EncryptWord objects ontained within FindFault object
void printNumberOfElements(FindFault& ffobject) {
	cout << "Number of elements: " << ffobject.getNumberOfElements() << endl;
	cout << "*************************************************" << endl;
}
// Defintion: Adding EncryptWord object to container which will be accesible by its associated element number. encypted string will be printed,
// next line indicates number of elements in container/associated element number.
// precondition: object may be ON or OFF for encyption
// modify: adding two elements to heap memory; passed string argument, and new EncryptWord object. FindFault.numberOfElements will increase by 1
// expected output: encrypted string , number of elements contained in ff object
void addAndEncrypt(FindFault &ffobject, string encryptWord) {
	cout << ffobject.encrypt(encryptWord) << endl;
	cout << "Element Number: " << ffobject.getNumberOfElements() << endl;
	cout << "*************************************************" << endl;
}

// Defintion: Detects whether corruption had occured during the encryption process. prints corrupted, decrypted string if corruption has occured.
// precondtion: none
// modify: none
// expected output: Element Number, Whether corruption has occured, corrupted string if corruption has occured.
void printIfElementCorrupted(FindFault &ffobject, int elementNumber) {
	cout << "Element Number: " << elementNumber << endl;
	if (ffobject.detectCorruption(elementNumber) == true) {
		cout << "NOT CORRUPTED" << endl;
	}
	else {
		cout << "CORRUPTED" << endl;
		cout << ffobject.decrypt(elementNumber) << endl;
	}
	cout << "*************************************************" << endl;
}