# CryptographyProgram
This will be used for instructional use to explain many of the beginning simple ciphers.

This will touch on the following:
  ROT13 Cipher
  Caesar Cipher
  Reverse Transposition Cipher
  RSA Assymetric Encryption
  Columnar Transpositions
  Double Columnar Transpositions
  Keyed Alphabets
  
Details about each function:
	ASCII/Numbers
		ASCII is simply a character on a keyboard that corresponds to a decimal number. (Such as A == 65 || 82 == R). This works both ways and is used alot when dealing in encryption. 
	ROT13 Cipher
		The ROT13 cipher will begin by converting all the letters to a capital letter. Once this has been done the Cipher will then convert the letters by 13.
	Caesar Cipher
		The Caesar Cipher is a little bit more advanced than the ROT13 Cipher. The Cipher will begin by converting each character to capital letters. Once this has been completed, the user will be prompted for the offset number. This will be verified less than 25. The Offset Number is a number that will be added to the converted ASCII Number. When the two numbers are added, the converted number will verified it has not gone beyond 90. If the number is higher than 90 then subtraction from 26 will be applied to ensure ConvertedNumber stays within the alphabet. The program will then convert each ACII Number back to ASCII text and then print out the text.
	Reverse Transposition Cipher
		The Reverse Transposition Cipher is one of the simplest ciphers. All that is being done is just reversing the text. Such as "This is the text" to "txet eht is sihT".
	RSA Encryption
		RSA Encryption is the type of encryption used when dealing with Public and Private Keys. This function begins by pulling in the original string and then prompts the user to enter two prime numbers, P and Q. Then the Program will ask the user to enter a small prime number and then a constant value. The program will then multiply P and Q, then it will find Phi of N. Checks will be made on the small CoPrime Number. Once everything passes, the program will find the EuclineD. Once all of this is completed, the program will encrypt the message. Instead of using massive number and encrypting the entire message as a whole. With this program, I chose to simply loop through running power of CoPrime upon each ASCII Number. Finally, the mod of MultipliedN was run on each ASCII Number. Then the message was printed out with additional details.
	Columnar Transposition
		The Columnar Transposition Cipher is a very simple and very common cipher. This function will prompt the user for a column number. The program will then print out one row with the width, defined with a counter, no larger than the Column Amount specified. There is a command to remove all the spaces from the string. Once the ColumnAmount has been reached, a new line will be printed. This will continue until the StringSize integar is met.
	Encrypted Columnar Transposition
		The Encrypted Columnar Transposition Cipher is one more step compared to the original. This function will prompt the user for a column number and an OffsetNumber. The program will then convert the entire string to Uppercase. There is a command to remove all the spaces from the string. Once the string is converted, the program will call CaesarCipher and send the ASCII Number with the OffsetNumber. Once this has been looped through with the length of the string, The Program will print the EncryptedUpString. The program will then print out one row with the width, defined with a counter, no larger than the Column Amount specified. Once the ColumnAmount has been reached, a new line will be printed. This will continue until the StringSize integar is met.
	Double Columnar Transposition
		Similar to the Encrypted Columnar Transposition Cipher, the Double Columnar Transposition is also encrypted. The difference is how many times the text goes through the encryption process. The Double goes through a Caesar Cipher Twice. The user will choose both Offset Numbers and then the program will take off. The String is converted to upper case and run through one encryption. Then once that has finished the program will run the encrypted text through a second encryption. Once this has been complete, the program will take the secondencrypted array and convert it to a matrix. After the Matrix has been completed, the output will be reversed and instead of reading the matrix [0][0],[0][1],[0][2]... The matrix will output to an array reading top down from column [0][0],[1][0],[2][0]... (Once this has reached the end of the column it will proceed) [1][0],[1][1]... This will build Ciphertext.
	Vigenere Cipher
		The Vigenere Cipher requires to begin by having a 26 by 26 matix built. When this is done then they user will input the OrgString and a keyword. The program will need to remove the spaces from OrgString. Then it will calculate the size of OrgString. Then create a new char array with the letters of keyword repeating until the size of OrgString is met. After this to encrypt the string one must compare the OrgString and KeyWord chars. The OrgString is on the left going down and the Keyword is across the top. Match the letter of the OrgString to the position and Match the letter of the Keyword on that position. Once this has been done us [x][y] to pull from that position. When the program has found the cipher letter add the [x][y] corresponding letter to the CipherTextArray. Repeat through the loop to the OrgString.size() then print out the CipherTextArray.
