// Author: Damien Sudol
// Filename: EncryptWord P2
// Date: 10/16/2017
// Version: 1.1

#include "FindFault.h"
#include <iostream>
#include <string>
// Definition: Driver designed to test all public functions and legeal state transitions provided by the FindFault class, with all possible inputs laid out per the 
// contract set by the FindFault.h documentation. All public functions of the FindFault class will be tested for integrety based on expected vs actual output. 
// Multiple, distinct FindFault objects will be created and maintained to ensure objects retain an independent identity and are not impacted by one another. 
// This application holds the FindFault class accountable for its core requriements; properly encapsualting EncryptWord objects, retaining encryption and decryption,
// adding the possibility of corruption, providing a means to test for corruption, and the tracking/providing of queries to the FindFault class to detect
// whether corruption has occured.
//

void detectCorruption(FindFault&, int);
void addAndEncrypt(FindFault&, string);
void printNumberOfElements(FindFault&);
void printNumberOfQueries(FindFault&);
void welcomeMessage();
void printCorruption(FindFault&, int);
void corruptionDetectLoop(FindFault&);

int main() {
	
	// Driver Welcome Message
	welcomeMessage();

	// call to FindFault constructor, creating FindFault object ff capable of accessing FindFault public methods
	// expected output n/a
	FindFault ff;

	// expected number of elements for object ff: 0
	cout << "Number of elements. expected output: 0" << endl << endl;
	printNumberOfElements(ff);

	// expected number of queries for object ff: 0
	cout << "Number of corruption check queries. total queries expected: 0" << endl << endl;
	printNumberOfQueries(ff);

	// expected number of elements for object ff: 1
	cout << "Encryption. expected output: encrypted string at position 1" << endl << endl;
	addAndEncrypt(ff, "ABC123 abc123");

	// expected number of elements for object ff: 2
	cout << "Encryption. expected output: encrypted string at position 2" << endl << endl;
	addAndEncrypt(ff, "Scoobie Doobie Doo");

	// check for encryption corruption for FindFault object ff at element position 1
	cout << "Expected output: display if corruption has occured and element number" << endl << endl;
	detectCorruption(ff, 1);

	// expected number of queries for object ff: 1
	cout << "Number of corruption check queries. total queries expected: 2" << endl << endl;
	printNumberOfQueries(ff);

	// check for encryption corruption for FindFault object ff at element position 2
	cout << "Expected output: display if corruption has occured and element number" << endl << endl;
	detectCorruption(ff, 2);

	// expected number of queries for object ff: 2
	cout << "print number of query calls to FindFault.detectCorruption() expected output: 2" << endl << endl;
	printNumberOfQueries(ff);

	// print decrypted EncryptWord object's stored word which may or may not be corrupted
	cout << "Decryption. expected output to be decrypted string which may or may not be corrupted" << endl << endl;
	cout << ff.decrypt(1) << endl;
	cout << "*********************************************************************************" << endl;

	// create 2nd FindFault object, independent of existing FindFault object
	FindFault ff2;

	// expected number of elements for object ff2: 0
	cout << "Number of elements for object 2. expected output: 0" << endl << endl;
	printNumberOfElements(ff2);

	// expected number of elements for object ff2: 1
	cout << "Encryption for object 2. expected output: encrypted string at position 1" << endl << endl;
	addAndEncrypt(ff2, "Testing that encryptioooon");

	// print decrypted EncryptWord object's stored word which may or may not be corrupted
	cout << "Decryption. expected output to be decrypted string which may or may not be corrupted" << endl << endl;
	cout << ff2.decrypt(1) << endl;
	cout << "*********************************************************************************" << endl;

	// expected number of elements for object ff2: 2
	cout << "Encryption for object 2. expected output: encrypted string at position 2" << endl << endl;
	addAndEncrypt(ff2, "tst spcl kys !@#$%^&");

	// check for encryption corruption for FindFault object ff2 at element position 2
	cout << "Expected output: display if corruption has occured and element number: 2" << endl << endl;
	detectCorruption(ff2, 2);

	//expected total number of queries for object ff2: 1
	cout << "print number of query calls returning corruption and no corruption." << endl << endl;
	printNumberOfQueries(ff2);
	
	// create third FindFault object
	FindFault ff3;

	// create new EncryptWord object for new FindFault object ff3
	cout << "Encryption. expected output: encrypted string at position 1" << endl << endl;
	addAndEncrypt(ff3, "TESTING");

	// prints formatted string for if corruption has occured for specific EncryptWord object encapsulated by FindFault object
	printCorruption(ff, 1);
	printCorruption(ff, 2);
	printCorruption(ff2, 1);
	printCorruption(ff2, 2);
	printCorruption(ff3, 1);

	// re-call printCorruption to ensure objects retain their values
	cout << "re-call same method to ensure object retains value after multiple calls" << endl << endl;
	printCorruption(ff, 1);

	// expected number of elements for object ff2: 3
	cout << "Encryption for object 2. expected output: encrypted string at position 3" << endl << endl;
	addAndEncrypt(ff2, "this is EW 3");

	// expected number of elements for object ff2: 4
	cout << "Encryption for object 2. expected output: encrypted string at position 4" << endl << endl;
	addAndEncrypt(ff2, "THIS IS ew 4");

	// expected number of elements for object ff2: 5
	cout << "Encryption for object 2. expected output: encrypted string at position 5" << endl << endl;
	addAndEncrypt(ff2, "go seahawks");

	// expected number of elements for object ff2: 6
	cout << "Encryption for object 2. expected output: encrypted string at position 6" << endl << endl;
	addAndEncrypt(ff2, "BUY ETHEREUM");

	// expected number of elements for object ff2: 7
	cout << "Encryption for object 2. expected output: encrypted string at position 7" << endl << endl;
	addAndEncrypt(ff2, "ob ob ob ject");

	// print number of queries for object ff2 before entering corruptDetectLoop
	printNumberOfQueries(ff2);

	// loop through all encapsualted objects of ff2 object, displaying if corruption has occured, followed by query results.
	corruptionDetectLoop(ff2);

	cin.get();
	return 0;
}

//Formatted Welcome Message
void welcomeMessage() {
	cout << "\n*********************************************************************************"<<
	"\n*\t\t\t\t\t\t\t\t\t\t*\n*WELCOME TO FIND FAULT TEST DRIVER!!\t\t\t\t\t\t*\n""*CPSC 5011 "<<
	"PROJECT 2\t\t\t\t\t\t\t\t*\n*AUTHOR: DAMIEN SUDOL\t\t\t\t\t\t\t\t*\n*Version: 1.1\t\t\t\t\t\t\t\t\t*"<<
	"\n*\t\t\t\t\t\t\t\t\t\t*\n*********************************************************************************" << endl;
}
// Definition: prints number of queries which have detected corruption, and number of queries which have not detected corruption
// precondition: none
// modify: none
// expected output: formatted display indicating number of corruptions and succesful encryptions queried.
void printNumberOfQueries(FindFault& ffobject) {
	cout << "Number of queries detecting corruption:\t\t" << ffobject.getQueryAttempts(true) << endl;
	cout << "Number of queries with no corruption detected:\t" << ffobject.getQueryAttempts(false) << endl;
	cout << "*********************************************************************************" << endl;
}

// Definition: Check number of elements (EncryptWord objects) stored by FindFault object
// precondition: none
// modify: none
// expected output: Number of EncryptWord objects ontained within FindFault object
void printNumberOfElements(FindFault& ffobject) {
	cout << "Number of elements: " << ffobject.getNumberOfElements() << endl;
	cout << "*********************************************************************************" << endl;
}
// Defintion: Adding EncryptWord object to container which will be accesible by its associated element number. encypted string will be printed,
// next line indicates number of elements in container/associated element number.
// precondition: object may be ON or OFF for encyption
// modify: adding two elements to heap memory; passed string argument, and new EncryptWord object. FindFault.numberOfElements will increase by 1
// expected output: encrypted string , number of elements contained in ff object
void addAndEncrypt(FindFault &ffobject, string encryptWord) {
	cout << ffobject.encrypt(encryptWord) << endl;
	cout << "Element Number: " << ffobject.getNumberOfElements() << endl;
	cout << "*********************************************************************************" << endl;
}

// Defintion: Detects whether corruption had occured during the encryption process. prints corrupted, decrypted string if corruption has occured.
// precondtion: none
// modify: none
// expected output: Element Number, Whether corruption has occured, corrupted string if corruption has occured.
void detectCorruption(FindFault &ffobject, int elementNumber) {
	cout << "Element Number: " << elementNumber << endl;
	if (ffobject.detectCorruption(elementNumber) == true) {
		cout << "NOT CORRUPTED" << endl;
	}
	else {
		cout << "CORRUPTED" << endl;
		cout << ffobject.decrypt(elementNumber) << endl;
	}
	cout << "*********************************************************************************" << endl;
}

// Defintion: Prints formatted string returned by FindFault.printCorruption() method. Purpose is to display whether
// corruption of encryption has been detected in a readable way.
// precondition: Object must be ON. Argument 1 must be of a valid initialized object of type FindFault. integer argument must be within bounds;
// greater than 0 and less than or equal to getNumberOfElements();
// modify: none
// expected output: formatted string printed, displaying whether corruption has occured.
void printCorruption(FindFault& ffobject, int elementNumber) {
	cout << ffobject.printCorruption(elementNumber) << endl;
	cout << "*********************************************************************************" << endl;
}

// Defintion: loops through all encapsualted EncryptWord objects for passed FindFault object. calls driver detectCorruption() and printNumberOfQueries methods.
// to demonstrate incremental increases for returned corrupted vs not corrupted encryptions.
// precondition. Object must be ON. Argument 1 must be of a valid initialized object of type FindFault. integer argument must be within bounds;
// modify: each call will increase by a value of one either FindFault.orruptedEncryption or FindFault.encryptionNotCorrupted
// expected output: formatted display of corruption, followed by formatted display of query statistics, with a total increasing by one per call.
void corruptionDetectLoop(FindFault& ffobject) {
	for (int i = 1; i <= ffobject.getNumberOfElements(); i++) {
		cout << "Expected output: display if corruption has occured and element number: " << i << endl << endl;
		detectCorruption(ffobject, i);
		printNumberOfQueries(ffobject);
	}
}