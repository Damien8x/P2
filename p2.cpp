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



int main() {
	// call to FindFault constructor, creating FindFault object ff capable of accessing FindFault public methods
	// expected output n/a
	FindFault ff;
	// Definition: setting dynamic array size to 6, allowing for 6 objects to be created and managed.
	
	
	// expected ouput: n/a
	cout << ff.getArraySize() << endl;
	
	// Definition: create first element of EncryptWord array.
	// first argument: phrase to be encrypted and returned. 2nd argument: position in array for object to be asssigned to.
	// expected output: encryption of first argument
	cout << ff.encrypt("aaaaAAAzZ") << endl;
	cout << ff.getArraySize() << endl;
	
	// Defintion: create second element of EncryptWord array.
	// first argument: phrase to be encrypted and returned. 2nd argument: position in array for object to be asssigned to.
	// expected output: encryption of first argument
	cout << ff.encrypt("DAFDSFA") << endl;
	cout << ff.getArraySize() << endl;
	
	// Definition: create thrid element of EncryptWord array.
	// first argument: phrase to be encrypted and returned. 2nd argument: position in array for object to be asssigned to.
	// expected output: encryption of first argument
	cout << ff.encrypt("ASDLFADFLAFsadfsfassasdfa") << endl;
	cout << ff.getArraySize() << endl;
	
	// Definition: create fourth element of EncryptWord array.
	// first argument: phrase to be encrypted and returned. 2nd argument: position in array for object to be asssigned to.
	// expected output: encryption of first argument
	cout << ff.encrypt("How dod you like this now") << endl;
	cout << ff.getArraySize() << endl;
	// Definition: returns number of calls to FindFault.detectCorruption();
	// expected output: expect return value of 9 based on above for loop for 2nd object in array.
	if (ff.detectCorruption(1) == true) {
		cout << "NO CORRUPTION" << endl;
	}else
		cout<<"CORRUPTION";

	if (ff.detectCorruption(2) == true) {
		cout << "NO CORRUPTION" << endl;
	}
	else
		cout << "CORRUPTION";

	cout << ff.getQueryAttempts();
	
	cin.get();
	return 0;
}