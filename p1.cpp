// Author: Damien Sudol
// Filename: EncryptWord P1
// Date: 10/10/2017
// Version: 1.1
//
// Desctription: Application driver is designed to test all public funtions provided by the EncryptWord class, including all data types and values outside of permitted range.
// Driver will mimic the intended use of class in logical order, meaning, encryption first, followed by a guessing game, and then a display of statistics followed by a reset of the object to its intial state.
// All conditions of the class will be tested; including conditions to prevent further encryption (encryption off) and imacts on the getPhrase() return value (encrypted vs decrypted), as described below.
// A second object will be created to test implicit casting and demonstrate an independent state from original object.
// The functions of the EncryptWord class are dependent on a logical order, encryption firtst, game sencond, stats and object reset last, in order to maintain  integrety of
// the object's data. The cryptic shift value will be 0 when an object is intitialized, and adjusted randomly after encrypt() method is called. A call to the checkShift() method prior to 
// encryption taking place will yield insignificant data. method, encrypt() is designed to take an argument of string, greater than 3 characters. no error handling will be provided by EncryptWord
// beyond a prompt stating data does not fit required specifications, and in the case of encrypt() a return value equal to input. Driver will test argument less than 4 characters. It is up to programmers
// to ensure any user input is stored as a string. method is capable of handling any string greater than 4 characters, composed of ascii values. state of object will change upon a succesful encryption, including change of
// attributes "phrase", "encryptPhrase", "on" and "shift". Method function are also dependent on succesful encryption. encrypt() will be disabled and getPhrase() will return strictly an encrypted string
// until one of two conditions are met; objectReset() is called or an argument equal to object's shift value is passed to the checkShift() method (changing state of object's "on" attribute).
// Driver will test checkShift() method (method compares passed integer to shift value) first through a for loop which will pass all acceptable arguments to the method, where we have laid out anticipated
// postconditions in the code. Implicit casting of characters to integer values will also be tested and render a prompt from the method if outside acceptable bounds.  checkShift() has a significant impact on the object state.
// any call to the method with acceptable arguments will change object's "lowGuessCount", "highGuessCount", "avgGuessCount", "totalGuessCount", and "guessCount" attributes; some by incremental values
// others dependent on passed argument, as laid out per EncryptWord.h specifications. Driver will also test arguments outside of the range 1-9 and implicit casting of doubles. Driver will
// display output for each acceptable call to checkShift(), including; integer passed, relation to shift (-1 if below, 1 if above, 0 if the same), objects highGuessCount, lowGuessCount, avgGuessCount
// guessCount and totalGuessCount, and getPhrase(), all of which may be impacted by call to checkShift(). A return value of 2 indicates input is invalid or out of bounds.
// All accesor methods will be tested multiple times, during the testing of the checkShift() method and post call to the objectReset() method, which sets all object attributes to their initial state.
// post call to objectReset() we expect all accessor method to return a value of 0, for integers and "", for strings.
//
// Assumptions: Driver assumes class will be utilized for its intended purporse of encryption, followed by an interactive guessing game which provides statitical feedback. For the class to yield
// significant data from the object structure must be of the logical order laid out above. Driver also assumes any errors regarding data types will be handled on the application side. Although prompts
// indicating improper data has been provided by the class, to preserve order in the application programmers must ensure a succesful encryption has been returned by encrypt(), prior
// to beginning a guessing game. Class design also expects a call to objectRest() or creation of a new object post guessing game, if a new encryption and game is to take place. Again, this is necessary to
// provide integrety to the object's data in reflecting only the active game. For the purpose of this driver all input will be hard coded, not accepting user input, for the purpose of speed and testing.
// For more details on class functions refer to EncryptWord.h

#include "EncryptWord.h"
#include <iostream>
#include <string>
using namespace std;
void iterateGuessShift(int, EncryptWord&);
void testObjectReset(EncryptWord&);
void testCheckShiftBoundries(EncryptWord&);

int main()
{
	// create EncryptWord object
	EncryptWord ew;

	// Desciption: passing illegal argument, string of < 4  will return a string value of -1, indicating a string has less than 4 character. 
	// input: Illegal string under 4 characters
	// modify: State not impacted
	// expected output: string return value of -1.
	cout << "Testing illegal argument for encrypt(). less than 4 characters" << endl << endl;
	
		string shortStringPhrase = "aaa";
		if (ew.encrypt(shortStringPhrase) == "-1"){
			cout << "ERROR invalid input" << endl;
		}
	cout << "********************************************************************" << endl;
	
	// Set phrase to legal argument, string with > 4 characters
	string phrase = "aa bb cc xx yy zz AA BB CC XX YY ZZ";

	// Description: Test legal argument.
	// input: legal string argument
	// modify: state change of object's shift, phrase, and on attribute
	// expect output: 12 pairs of characters in sequential sets of 3. 6 pairs lowercase and 6 pairs of an upppercase equivalent returned.  any value shifted beyond 'z' or 'Z' should 
	// wrap to beginning of alphabet. all blank spaces should be persistent. Shift is randomly generated and should uniformly shift output. 
	cout << "Testing legal argument for encrypt" << endl << endl;
	cout << ew.encrypt(phrase) << endl << endl;
	cout << "********************************************************************" << endl;


	// for loop to determine if checkShift() method provides correct return values of passed argument in relation to "shift" value for all possible shift values.
	cout << "Testing all legal arguments for checkShift()" << endl << endl;
	iterateGuessShift(1, ew);
	cout << "********************************************************************" << endl;


	// function responsible for setting and displaying objects values at their initial state
	cout << "Testing objectReset() method" << endl << endl;
	testObjectReset(ew);
	cout << "********************************************************************" << endl;

	// create a second EncryptWord object
	EncryptWord ew2;

	// function responsible for testing legal high and low integer arguments of object.checkShift()
	cout << "Testing checkShift() high and low boundries and implicit character casting" << endl << endl;
	testCheckShiftBoundries(ew2);
	cout << "********************************************************************" << endl;

	// Descritpion: testing access to encrypt() method after encryption and before call to objectReset() / correct shift value passed to checkShift()
	// input: legal string argument
	// modify: n/a
	// expected output: a string value of "-2" indicating accesability is restricted to the function
	cout << "Testing access to encrypt() method" << endl << endl;
	cout << ew2.encrypt("I Should print a -2") << endl;
	cout << "********************************************************************" << endl;


	cout << "Testing encryption access";
	// Description Testing for implicit casting of doubles. expect i to be rounded down to integer, producing results identical to if i was assigned integer value.
	cout << "Testing implicit casating of doubles for all legal checkShift() arguments" << endl << endl;
	iterateGuessShift(1.3, ew2);
	cout << "********************************************************************" << endl;


	// for testing purposes... keep console window from exiting
	cin.get();	
}

void testObjectReset(EncryptWord& ew) {

	// Descritpion: method will reset object to its initial state
	// input: N/A
	// Modify: All class attributes will be set to default
	// output: N/A
	ew.objectReset();

	// Description: Test state of avgGuess post objectReset()
	// input: n/a
	// modify: n/a
	// output: expect a return of 0
	cout << ew.getAvgGuess() << endl;

	// Description: test state of guessCount post objectReset()
	// input: n/a
	// modify: n/a
	// output: expect a return of 0
	cout << ew.getGuessCount() << endl;

	// Description: test state of highGuessCount post objectReset()
	// input: n/a
	// modify: n/a
	// output: expect a return of 0
	cout << ew.getHighGuessCount() << endl;

	// Description: test state of lowGuessCount post objectReset()
	// input: n/a
	// modify: n/a
	// output: expect a return of 0
	cout << ew.getLowGuessCount() << endl;

	// Description: test state of totalGuess post objectReset()
	// input: n/a
	// modify: n/a
	// output: expect a return of 0
	cout << ew.getTotalGuess() << endl;
	
	// Description: test return value of getPhrase post objectReset()
	// input: n/a
	// modify: n/a
	// ouput: expect a return of ""
	cout << ew.getPhrase() << endl;
}

void testCheckShiftBoundries(EncryptWord& ew) {
	// Description: testing shift of special characters based on ASCII values. 
	// input: legal string with special characters
	// modify: objects phrase, encryptPhrase, on and shift attributes will change
	// output: return value of encrypted phrase.
	cout << ew.encrypt("this is to test special characters: +=;!@#$%^&*( ") << endl << endl;

	// Description: testing for implicit cast of character passed as an integer of an illegal value.
	// input: Type char. will be implicityly cast
	// modify: n/a
	// output: will return an integer of 2, indicating input out of bounds or invalid.
	int testImplicitCast = 'a';
	cout << ew.checkShift(testImplicitCast) << endl << endl;

	// Description: testing an illegal integer argument above 9. 
	// input: integer above 9
	// modify: n/a
	// output: will return an integer of 2, indicating input out of bounds or invalid.
	cout << ew.checkShift(10) << endl << endl;

	// Description: testing an illegal integer argument below 1. 
	// input: integer below 1
	// modify: n/a
	// output:  will return an integer of 2, indicating input out of bounds or invalid.
	cout << ew.checkShift(0) << endl << endl;
}

void iterateGuessShift(int i, EncryptWord& ew) {
	// for loop designed to interate through all possible shift values; 1-9
	for (i; i < 10; i++) {

		// Description: Pass legal integer (or implicit cast of double) to checkShift method to display relative value of "i" to objects "shift" value
		// input: integer
		// modify: changes to objects guessCount, totalGuessCount, lowGuessCount(possibly), highGuessCount(possibly), avgGuessCount attributes.
		// expected ouput: return of -1 prior to a return of 0 as loop iterates, and return values of 1 post return of 0. associated i value to a return of 0 represents the shift value
		cout << "Guess: " << i << ": \t" << "Relative Value: " << ew.checkShift(i) << endl;

		// Description: test getHighGuessCount() returns expected value
		// input: N/A
		// modify: N/A
		// expected output: 0 return value pre encryption key, followed by an incremental return value post encryption key
		cout << "High Guess Count: \t" << ew.getHighGuessCount() << endl;

		// Description: test getLowGuessCount() returns expected value
		// input: N/A
		// modify: N/A
		// expected output: incremental return value pre encryption key and repeating value post encryption key
		cout << "Low Guess Count: \t" << ew.getLowGuessCount() << endl;

		// Descritpion: test getGuessCount() returns expected value
		// input: N/A
		// modify: N/A
		// expected output: incremental return value from 1 to 9
		cout << "Total Guess Count: \t" << ew.getGuessCount() << endl;

		// Description: test getTotalGuess() returns expected value
		// input: N/A
		// modify: N/A
		// expect an addition of passed value to prior value, with an ending value of 45
		cout << "Total Guess Count Sum: \t" << ew.getTotalGuess() << endl;

		// Description: test avgGuessCount() returns expected value
		// input: N/A
		// modify: N/A
		// expect an average between "total guess count sum" and "total guess count" with an ending value of 5.
		cout << "Average Guess Value: \t" << ew.getAvgGuess() << endl << endl;

		// Description: tests if encryption has been disabled due to a correct guess of shift used
		// input: n/a
		// modify: n/a
		// expected output: if checkShift() returns -1 encryption will remain enabled. if checkShift returns 0 or 1, encryption will be disabled 
		cout << "Is encryption off? \t" << ew.getPhrase() << endl << endl;
	}

}
