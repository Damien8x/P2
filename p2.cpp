// Author: Damien Sudol
// Filename: EncryptWord P2
// Date: 10/16/2017
// Version: 1.1

#include "FindFault.h"
#include <iostream>
#include <string>

int main() {

	FindFault ff;

	ff.setArraySize(6);
	cout << ff.encrypt("aaaaAAAzZ", 1) << endl;
	cout << ff.encrypt("DAFDSFA", 2) << endl;
	cout << ff.encrypt("ASDLFADFLAFsadfsfassasdfa", 2) << endl;
	cout << ff.getArraySize() << endl;
	
	for (int i = 1; i < 10; i++) {
		if (ff.detectCorruption(1, i) == 1) {
			cout << "too high" << endl;
		}
		else if (ff.detectCorruption(1, i) == -1) {
			cout << "too low" << endl;
		}
		else if (ff.detectCorruption(1, i) == 5) {
			cout << "No corruption" << endl;
		}
		else if (ff.detectCorruption(1, i) == 6) {
			cout << "CORRUPTION" << endl;
		}
		else
			cout << "error";
	}
	cin.get();
	return 0;
}