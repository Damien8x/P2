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
	cout << ff.encrypt("ASDLFADFLAFsadfsfassasdfa", 3) << endl;
	cout << ff.encrypt("How dod you like this now", 4) << endl;
	cout << ff.getArraySize() << endl;
	
	for (int i = 1; i < 10; i++) {
		int test = ff.detectCorruption(2, i);
		if (test == 1) {
			cout << "too high" << endl;
		}
		else if (test == -1) {
			cout << "too low" << endl;
		}
		else if (test == 5) {
			cout << "No corruption" << endl;
		}
		else if (test == 6) {
			cout << "CORRUPTION" << endl;
		}
		else if (test== -2) {
			cout << "error";
		}
		else if (test== 0) {
			cout << "huh?";
		}
	}
	cout << ff.checkQueryAttempts(2);
	cin.get();
	return 0;
}