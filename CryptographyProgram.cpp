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
#include <iostream>
#include <stdio.h>
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
//int DoubleColumnarTransposition(string, int);
//int KeyedAlphabets(string);

int main() {
	MainMenu();
	system("pause");
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
	cout << "Please Select the Form of Encryption to Use: \n1. ROT13Math\n2. Caesar Cipher\n3. Reverse Transposition Cipher\n4. RSA Assymetric Encryption\n5. Columnar Transpositions\n6. Double Columnar Transpositions\n7. Keyed Alphabets\n";
	cin >>  Selection;
	InitialRun(Selection);
	return 0;
}
// To Do List:
// Need to add Keyed Alphabets 1.2.1 
// Need to add Double Columnar Transposition
// Need to fix Vigenere Cipher

int InitialRun(int Selection) {		// Program call from Main
	string OrgString, Keyword;
	char UpString[255];
	int FinalString[255];
	char NewString[255];
	char ReverseString[255];
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
		case 1:
			cout << "Please note that all Characters will be converted to Uppercase." << endl;
			for (int j = 0; j < loops; j++) {
				NewString[j] = ROT13Math(UpString[j]);
				FinalString[j] = ConvertASCIItoNumber(NewString[j]);
			}
			break;
		case 2:
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
		case 4:
			RSAEncryption(OrgString);
			return 0;
			break;
		case 5:
			cout << "Please Enter the Amount of Columns: ";
			cin >> ColumnAmount;
			ColumnarTransposition(OrgString, ColumnAmount);
			return 0;
			break;
	/*	case 8:		//Credit to GEEKSFORGEEKS.ORG (Ayush Khanduri) with modifications
			cout << "Please Enter the Keyword: ";
			cin >> Keyword;
			VigenereCipher(OrgString, Keyword);
			return 0;
			break;
		}
		*/
		for (int m = 1; m < loops; m++) {
				cout << "ASCII value of " << NewString[m] << " is : " << FinalString[m] << "\n";
			}
		return 0;
	}
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

int RSAEncryption(string OrgString) {				// This is Switch Option 4
	int FirstEncryptNumberList[255];
	int SecondEncryptNumberList[255];
	int FinalEncryptNumberList[255];
	int EncryptedListSize;
	int PrimeNumberP = 0;
	int PrimeNumberQ = 0;
	int MultipliedN = 0;
	int CoPrimeNumber = 0;
	int PublicKeyEncrypt = 0;
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
	char FinalEncryptedMessage[255];
	int count = 0;
	int StringSize = 0;
	char NewStringNoSpace[255];
	int FinalStringSize = 0;

	remove_if(OrgString.begin(), OrgString.end(), isspace);
	StringSize = OrgString.size();

	for (int l = 0; l < StringSize; l++) { // Columns
		cout << OrgString[l];
		count++;
		if (count > ColumnAmount) {
			cout << "\n";
			count = 0;
//			FinalEncryptedMessage[l] = ' ';
		}
	}
// Need to Add a section that will add the Encrypted Message. Reading on every ColumnAmount Char till all characters have been accounted for.
/*	Here
*/
	cout << "\nThe Encrypted Message Reads: ";
	for (int k = 0; k < FinalStringSize; k++) {
		cout << FinalEncryptedMessage[k];
	}
	cout << "\n";
	return 0;
}

int DoubleColumnarTransposition(string OrgString, int ColumnAmount) {		// This will be Switch Option 6
	char FinalEncryptedMessage[255];
	int count = 0;
	int StringSize = 0;
	char NewStringNoSpace[255];
	
	remove_if(OrgString.begin(), OrgString.end(), isspace);
	StringSize = OrgString.size();

	for (int l = 0; l < StringSize; l++) {
		cout << OrgString[l];
		count++;
		if (count > ColumnAmount) {
			cout << "\n";
			count = 0;
//			FinalEncryptedMessage[l] = ' ';
		}
	}
// Need to Add a section that will add the Encrypted Message. Reading on every ColumnAmount Char till all characters have been accounted for.
/*	Here
*/

	cout << "\nThe Encrypted Message Reads: ";
	for (int k = 0; k < StringSize; k++) {
		cout << FinalEncryptedMessage[k];
	}
	cout << "\n";
	return 0;
}


/*int KeyedAlphabets(string OrgString){							// This will be Switch Option 7
	return 0;
}*/
/*
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
*/
