/*
 * CryptographyProgram.cpp : This file contains the 'main' function. Program execution begins and ends there.
*/

/*	
*	From: Matthew Harris
*	To those onlooking at the program:
*	I do understand that this can be written differently. It would be better and more appealing to see things in classes and nice organized calls.
*	The problem with that is this is used as an educational tool. This is written for a beginner in programming or a non programmer to be able to follow.
*	This will be used for instructional use to explain many of the beginning simple ciphers.
*/

/*
*	Details about each function:
*	ASCII/Numbers
*		ASCII is simply a character on a keyboard that corresponds to a decimal number. (Such as A == 65 || 82 == R). This works both ways and is used alot when dealing in encryption. 
*	ROT13 Cipher
*		The ROT13 cipher will begin by converting all the letters to a capital letter. Once this has been done the Cipher will then convert the letters by 13.
*	Caesar Cipher
*		The Caesar Cipher is a little bit more advanced than the ROT13 Cipher. The Cipher will begin by converting each character to capital letters. 
*		Once this has been completed, the user will be prompted for the offset number. This will be verified less than 25. The Offset Number is a number that will be added to the converted ASCII Number. 
*		When the two numbers are added, the converted number will verified it has not gone beyond 90. If the number is higher than 90 then subtraction from 26 will be applied to ensure ConvertedNumber stays within the alphabet.
*		The program will then convert each ACII Number back to ASCII text and then print out the text.
*	Reverse Transposition Cipher
*		The Reverse Transposition Cipher is one of the simplest ciphers. All that is being done is just reversing the text. Such as "This is the text" to "txet eht is sihT".
*	RSA Encryption
*		RSA Encryption is the type of encryption used when dealing with Public and Private Keys. This function begins by pulling in the original string and then prompts the user to enter two prime numbers, P and Q.
*		Then the Program will ask the user to enter a small prime number and then a constant value. The program will then multiply P and Q, then it will find Phi of N. Checks will be made on the small CoPrime Number.
*		Once everything passes, the program will find the EuclineD. Once all of this is completed, the program will encrypt the message. Instead of using massive number and encrypting the entire message as a whole. 
*		With this program, I chose to simply loop through running power of CoPrime upon each ASCII Number. Finally, the mod of MultipliedN was run on each ASCII Number. Then the message was printed out with additional details.
*	Columnar Transposition
*		The Columnar Transposition Cipher is a very simple and very common cipher. This function will prompt the user for a column number. 
*		The program will then print out one row with the width, defined with a counter, no larger than the Column Amount specified. There is a command to remove all the spaces from the string.
*		Once the ColumnAmount has been reached, a new line will be printed. This will continue until the StringSize integar is met.
*	Encrypted Columnar Transposition
*		The Encrypted Columnar Transposition Cipher is one more step compared to the original. This function will prompt the user for a column number and an OffsetNumber. 
*		The program will then convert the entire string to Uppercase. There is a command to remove all the spaces from the string. 
*		Once the string is converted, the program will call CaesarCipher and send the ASCII Number with the OffsetNumber. 
*		Once this has been looped through with the length of the string, The Program will print the EncryptedUpString.
*		The program will then print out one row with the width, defined with a counter, no larger than the Column Amount specified.
*		Once the ColumnAmount has been reached, a new line will be printed. This will continue until the StringSize integar is met.
*	Double Columnar Transposition
*		Similar to the Encrypted Columnar Transposition Cipher, the Double Columnar Transposition is also encrypted. The difference is how many times the text goes through the encryption process. The Double goes through a Caesar Cipher Twice.
*		The user will choose both Offset Numbers and then the program will take off. The String is converted to upper case and run through one encryption. Then once that has finished the program will run the encrypted text through a second encryption.
*		Once this has been complete, the program will take the secondencrypted array and convert it to a matrix. After the Matrix has been completed, the output will be reversed and instead of reading the matrix [0][0],[0][1],[0][2]...
*		The matrix will output to an array reading top down from column [0][0],[1][0],[2][0]... (Once this has reached the end of the column it will proceed) [1][0],[1][1]...
*		This will build Ciphertext.
*	Vigenere Cipher
*		The Vigenere Cipher requires to begin by having a 26 by 26 matix built. When this is done then they user will input the OrgString and a keyword.
*		The program will need to remove the spaces from OrgString. Then it will calculate the size of OrgString. Then create a new char array with the letters of keyword repeating until the size of OrgString is met.
*		After this to encrypt the string one must compare the OrgString and KeyWord chars. The OrgString is on the left going down and the Keyword is across the top. 
*		Match the letter of the OrgString to the position and Match the letter of the Keyword on that position. Once this has been done us [x][y] to pull from that position.
*		When the program has found the cipher letter add the [x][y] corresponding letter to the CipherTextArray. Repeat through the loop to the OrgString.size() then print out the CipherTextArray.
*/

#include <iostream>
#include <string.h>
#include <locale>
#include <string>
#include <istream>
#include <stdc++.h>
#include <math.h>
#include <algorithm>
using namespace std;

//Custom Global Definitions
char ConvertedLetter;
int p;

//Custom Functions
int ConvertASCIItoNumber(char);
int MainMenu();
int InitialRun(int);
char ROT13Math(char); 
char CaesarCipher(int, int);
char ConvertNumbertoASCII(int);
int VigenereCipher(string, string);
string generateKey(string, string);
string cipherText(string, string);
string originalText(string, string);
int RSAEncryption(string);
int ColumnarTransposition(string, int);
int EncryptedColumnarTransposition(string, int, int);
int DoubleColumnarTransposition(string, int, int, int);
//int KeyedAlphabets(string);

int main() {
	MainMenu();
	return 0;
}

int ConvertASCIItoNumber(char c) {		// Convert Letter to Number
	int a = 0;
	a = (int)c;
	return a;
}

char ConvertNumbertoASCII(int ASCIINumber) {		// Convert Number to Letter
	char ConvertedNumtoASCII;
	ConvertedNumtoASCII = char(ASCIINumber);
	return ConvertedNumtoASCII;
}

int MainMenu() {
	int Selection = 0;
	cout << "Please Select the Form of Encryption to Use: \n1. ROT13Math\n2. Caesar Cipher\n3. Reverse Transposition Cipher" << endl;
	cout << "4. RSA Assymetric Encryption\n5. Columnar Transpositions\n6. Encrypted Columnar Transpositions\n7. Double Columnar Transpositions\n8. Vigenere Cipher\n9. Keyed Alphabets" << endl;
	cin >>  Selection;
	InitialRun(Selection);
	return 0;
}

// To Do List:
// Need to add decryption to RSA Encryption
// Need to add Keyed Alphabets 1.2.1 
// Need to fix Vigenere Cipher

int InitialRun(int Selection) {		// Program call from Main
	string OrgString, Keyword;
	char UpString[255];
	int FinalString[255];
	char NewString[255];
	char ReverseString[255];
	int OffsetNumber = 0;
	int SecondOffsetNumber = 0;
	int NumberShift = 0;
	int ColumnAmount = 0;
	int CaesarNumber[255];
	int loops = 0;
	cout << "Enter A String: ";
	getline(cin, OrgString, 'Q');
	loops = OrgString.size();
	for (int i = 0; i < loops; i++) {
		UpString[i] = ConvertNumbertoASCII(toupper(ConvertASCIItoNumber(OrgString[i])));
	}
	switch (Selection) {
		case 1:		// ROT13 Cipher
			cout << "Please note that all Characters will be converted to Uppercase." << endl;
			for (int j = 0; j < loops; j++) {
				NewString[j] = ROT13Math(UpString[j]);
				FinalString[j] = ConvertASCIItoNumber(NewString[j]);
			}
			break;
		case 2:		// Caesar Cipher
			cout << "Please note that all Characters will be converted to Uppercase." << endl;
			cout << "Please enter the Offset of the Letter: ";
			cin >> NumberShift;
			for (int k = 0; k < loops; k++) {
				CaesarNumber[k] = ConvertASCIItoNumber(UpString[k]);
			}
			for (int l = 0; l < loops; l++) {
				NewString[l] = CaesarCipher(NumberShift, CaesarNumber[l]);
				FinalString[l] = ConvertASCIItoNumber(NewString[l]);
			}
			break;
		case 3:			// This is the Reverse Transposition Cipher
			cout << "Please note that all Characters will be converted to Uppercase." << endl;
			for (int o = loops; o > 0; --o) {
				ReverseString[p] = UpString[o];
				p++;
			}
			for (int q = 1; q < loops; q++) {
				cout << ReverseString[q];
			}
			return 0;
			break;
		case 4:		// RSA Encryption
			RSAEncryption(OrgString);
			return 0;
			break;
		case 5:		// Basic Columnar Transposition Cipher
			cout << "Please Enter the Amount of Columns: ";
			cin >> ColumnAmount;
			ColumnarTransposition(OrgString, ColumnAmount);
			return 0;
			break;
		case 6:		// Encrypted Single Columnar Transposition Cipher
			cout << "Please Enter the Amount of Columns: ";
			cin >> ColumnAmount;
			EncryptedColumnarTransposition(OrgString, ColumnAmount);
			return 0;
			break;
		case 7:		// Double Encrypted Columnar Transposition Cipher
			cout << "Please Enter the Amount of Columns: ";
			cin >> ColumnAmount;
			cout << "Please Enter the First Offset Number: ";
			cin >> OffsetNumber;
			cout << "Please Enter the Second Offset Number: ";
			cin >> SecondOffsetNumber;
			DoubleColumnarTransposition(OrgString, ColumnAmount, OffsetNumber, SecondOffsetNumber);
			return 0;
			break;
		case 8:		//Credit to GEEKSFORGEEKS.ORG (Ayush Khanduri) with modifications
			cout << "Please Enter the Keyword: ";
			cin >> Keyword;
			remove_if(OrgString.begin(), OrgString.end(), isspace);
			VigenereCipher(OrgString, Keyword);
			return 0;
			break;
		}
	for (int m = 1; m < loops; m++) {
		cout << "ASCII value of " << NewString[m] << " is : " << FinalString[m] << "\n";
	}
	return 0;
}

char ROT13Math(char OrgLetter) {						// This is Switch Option 1
	int OrgNumber = 0;
	int ConvertedNumber = 0;
	OrgNumber = ConvertASCIItoNumber(OrgLetter);
	if (OrgNumber <= 77 && OrgNumber >= 65) {		// Dealing in only UpperCase A - M
		ConvertedNumber = OrgNumber + 13;
		ConvertedLetter = ConvertNumbertoASCII(ConvertedNumber);
	}
	if (OrgNumber <= 90 && OrgNumber >= 78) {		// Dealing in only UpperCase N - Z
		ConvertedNumber = OrgNumber - 13;
		ConvertedLetter = ConvertNumbertoASCII(ConvertedNumber);
	}
	return ConvertedLetter;
}

char CaesarCipher(int OptionN, int CaesarNumber) {		// This is Switch Option 2
	char CaesarShiftC;
	int ConvertedNumber = 0;
	ConvertedNumber = CaesarNumber + OptionN;
	if (ConvertedNumber > 90) {			// This is a catch if the number is greater than the ASCII Number value 90 then 26 will be subtracted to wrap the value around
		ConvertedNumber = ConvertedNumber - 26;
	}
	CaesarShiftC = ConvertNumbertoASCII(ConvertedNumber);
	return CaesarShiftC;
}

// Potentially create decryption program (add a system pause and then create a decryption of the encrypted RSA Encryption)
int RSAEncryption(string OrgString) {				// This is Switch Option 4
	int FirstEncryptNumberList[255];
	int FinalEncryptNumberList[255];
	int EncryptedListSize;
	int PrimeNumberP = 0;
	int PrimeNumberQ = 0;
	int MultipliedN = 0;
	int CoPrimeNumber = 0;
	int PhiN = 0;
	int ConstantValue = 0;
	int EuclideanD = 0;
	EncryptedListSize = OrgString.size();

	cout << "Please Choose Prime Number P: ";
	cin >> PrimeNumberP;
	cout << "Please Choose Prime Number Q: ";
	cin >> PrimeNumberQ;
	cout << "Please Choose a prime number smaller than P and Q: ";
	cin >> CoPrimeNumber;
	cout << "Please Choose a Small Constant Value: ";
	cin >> ConstantValue;
	
	// Prep Math Section for RSA
	MultipliedN = PrimeNumberP * PrimeNumberQ;
	PhiN = (PrimeNumberP - 1) * (PrimeNumberQ - 1);
	while (CoPrimeNumber < MultipliedN) {
		if (gcd(CoPrimeNumber, MultipliedN) == 1)
			break;
		else
			CoPrimeNumber++;
	}
	EuclideanD = (1 + (ConstantValue * PhiN)) / CoPrimeNumber;

	//Encrypting the Message
	for (int j = 0; j < EncryptedListSize; j++) {
		FirstEncryptNumberList[j] = pow(ConvertASCIItoNumber(OrgString[j]),CoPrimeNumber) ;
	}
	for (int k = 0; k < EncryptedListSize; k++) {
		FinalEncryptNumberList[k] = FirstEncryptNumberList[k] % MultipliedN;
	}

	cout << "The Original Message is: " << OrgString << endl;
	cout << "The Private Key is: " << PrimeNumberP << " and " << PrimeNumberQ << " come together to form " << PhiN << " which is Phi." << endl;
	cout << "The CoPrime Number is: " << CoPrimeNumber << endl;
	cout << "The Euclidean Value D is: " << EuclideanD << endl;
	cout << "The Encrypted Message is: ";
	for (int i = 0; i < EncryptedListSize; i++) {
		cout << FinalEncryptNumberList[i];
	}
	cout << "\n";
	return 0;
}

int ColumnarTransposition(string OrgString, int ColumnAmount) {	//This is Switch Option 5
	char EncryptedMessage[255];
	char MatrixMessage[255][255];
	int count = 0;
	int col = 0;
	int c = 0;
	int RowAmount = 0;
	int StringSize = 0;
	char NewStringNoSpace[255];
	int FinalStringSize = 0;

	remove_if(OrgString.begin(), OrgString.end(), isspace);
	StringSize = OrgString.size();

	RowAmount = StringSize / ColumnAmount;

	for (int l = 0; l < RowAmount; l++) { // Columns
		for (int i = 0; i < ColumnAmount; i++) {
			cout << OrgString[count];
			MatrixMessage[l][i] = OrgString[count];
			count++;
		}
		cout << "\n";
	}

	count = 0;
	for (int k = 0; k < ColumnAmount; k++) {
		for (int j = 0; j < RowAmount; j++) {
			EncryptedMessage[count] = MatrixMessage[j][k];
			count++;
		}
	}

	cout << "\nThe Encrypted Message Reads: ";
	for (int k = 0; k < StringSize - 2; k++) {
		cout << EncryptedMessage[k];
	}
	cout << "\n";
	return 0;
}

int EncryptedColumnarTransposition(string OrgString, int ColumnAmount, int OffsetNumber) {		// This will be Switch Option 6
	char FinalEncryptedMessage[255];
	char MatrixMessage[255][255];
	char EncryptedUpString[255];
	char UpString[255];
	int OffsetNumber = 0;
	int CaesarNumber[255];
	int count = 0;
	int StringSize = 0;
	char NewStringNoSpace[255];
	int RowAmount = 0;

	remove_if(OrgString.begin(), OrgString.end(), isspace);
	StringSize = OrgString.size();

	RowAmount = StringSize / ColumnAmount;

	for (int i = 0; i < StringSize; i++)
		UpString[i] = ConvertNumbertoASCII(toupper(ConvertASCIItoNumber(OrgString[i])));

	cout << "Please Enter the Offset of the Letter: ";						// This will use the Caesar Cipher to Encrypt the Letters
	cin >> OffsetNumber;
	cout << "Please note that all Characters will be converted to Uppercase." << endl;
	for (int k = 0; k < StringSize; k++) {
		CaesarNumber[k] = ConvertASCIItoNumber(UpString[k]);
	}
	for (int f = 0; f < StringSize; f++) {
		EncryptedUpString[f] = CaesarCipher(OffsetNumber, CaesarNumber[f]);
	}

	for (int l = 0; l < RowAmount; l++) { // Columns
		for (int i = 0; i < ColumnAmount; i++) {
			MatrixMessage[l][i] = EncryptedUpString[count];
			count++;
		}
	}

	count = 0;
	for (int k = 0; k < ColumnAmount; k++) {
		for (int j = 0; j < RowAmount; j++) {
			FinalEncryptedMessage[count] = MatrixMessage[j][k];
			count++;
		}
	}

	cout << "\nThe Encrypted Message Reads: ";
	for (int k = 0; k < StringSize; k++) {
		cout << FinalEncryptedMessage[k];
	}
	cout << "\n";
	return 0;
}

int DoubleColumnarTransposition(string OrgString, int ColumnAmount, int OffsetNumber, int SecondOffsetNumber) {		//This is Switch Option 7
	char FinalEncryptedMessage[255];
	char MatrixMessage[255][255];
	char UpString[255];
	char EncryptedUpString[255];
	char SecondEncryptedUpString[255];
	int CaesarNumber[255];
	int count = 0;
	int StringSize = 0;
	int RowAmount = 1;
	char NewStringNoSpace[255];
	int FinalStringSize = 0;

	remove_if(OrgString.begin(), OrgString.end(), isspace);
	StringSize = OrgString.size();
	for (int i = 0; i < StringSize; i++)
		UpString[i] = ConvertNumbertoASCII(toupper(ConvertASCIItoNumber(OrgString[i])));

	cout << "Please note that all Characters will be converted to Uppercase." << endl;
	for (int k = 0; k < StringSize; k++) {
		CaesarNumber[k] = ConvertASCIItoNumber(UpString[k]);
	}
	for (int f = 0; f < StringSize; f++) {
		EncryptedUpString[f] = CaesarCipher(OffsetNumber, CaesarNumber[f]);
	}
	for (int f = 0; f < StringSize; f++) {
		SecondEncryptedUpString[f] = CaesarCipher(SecondOffsetNumber, ConvertASCIItoNumber(EncryptedUpString[f]));
	}

	RowAmount = StringSize / ColumnAmount;

	for (int l = 0; l < RowAmount; l++) { // Columns
		for (int i = 0; i < ColumnAmount; i++) {
			MatrixMessage[l][i] = SecondEncryptedUpString[count];
			count++;
		}
	}

	count = 0;
	for (int k = 0; k < ColumnAmount; k++) {
		for (int j = 0; j < RowAmount; j++) {
			FinalEncryptedMessage[count] = MatrixMessage[j][k];
			count++;
		}
	}

	cout << "\nThe Encrypted Message Reads: ";
	for (int k = 0; k < StringSize; k++) {
		cout << FinalEncryptedMessage[k];
	}
	//cout << "\n";
	return 0;
}



/*int KeyedAlphabets(string OrgString){							// This will be Switch Option 9
	return 0;
}*/


/*
	The Vigenere Cipher requires to begin by having a 26 by 26 matix built.
	When this is done then they user will input the OrgString and a keyword.
	The program will need to remove the spaces from OrgString.
	Then it will calculate the size of OrgString. Then create a new char array with the letters of keyword repeating until the size of OrgString is met.
	After this to encrypt the string one must compare the OrgString and KeyWord chars. The OrgString is on the left going down and the Keyword is across the top. 
	Match the letter of the OrgString to the position and Match the letter of the Keyword on that position. Once this has been done us [x][y] to pull from that position.
	When the program has found the cipher letter add the [x][y] corresponding letter to the CipherTextArray.
	Repeat through the loop to the OrgString.size() then print out the CipherTextArray.
*/

//Credit to GEEKSFORGEEKS.ORG (Ayush Khanduri) with modifications
// Driver program for Vigenere Cipher
int VigenereCipher(string OrgString, string keyword)		// This is Switch option 8
{
	string key = generateKey(OrgString, keyword);
	string cipher_text = cipherText(OrgString, key);
	cout << "Ciphertext : "
		<< cipher_text << "\n";

	cout << "Original/Decrypted Text : "
		<< originalText(cipher_text, key);
	return 0;
}

//Credit to GEEKSFORGEEKS.ORG (Ayush Khanduri) with modifications
// C++ code to implement Vigenere Cipher
// This function generates the key in
// a cyclic manner until it's length isi'nt
// equal to the length of original text
string generateKey(string str, string key)
{
	int x = str.size();

	for (int i = 0; ; i++)
	{
		if (x == i)
			i = 0;
		if (key.size() == str.size())
			break;
		key.push_back(key[i]);
	}
	return key;
}

//Credit to GEEKSFORGEEKS.ORG (Ayush Khanduri) with modifications
// This function returns the encrypted text
// generated with the help of the key
string cipherText(string str, string key)
{
	string cipher_text;

	for (int i = 0; i < str.size(); i++)
	{
		// converting in range 0-25
		int x = (str[i] + key[i]) %26;

		// convert into alphabets(ASCII)
		x += 'A';

		cipher_text.push_back(x);
	}
	return cipher_text;
}

//Credit to GEEKSFORGEEKS.ORG (Ayush Khanduri) with modifications
// This function decrypts the encrypted text
// and returns the original text
string originalText(string cipher_text, string key)
{
	string orig_text;

	for (int i = 0 ; i < cipher_text.size(); i++)
	{
		// converting in range 0-25
		int x = (cipher_text[i] - key[i] + 26) %26;

		// convert into alphabets(ASCII)
		x += 'A';
		orig_text.push_back(x);
	}
	return orig_text;
}

