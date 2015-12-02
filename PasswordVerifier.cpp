/* 
 * PasswordVerifier.cpp : This program verifies a password entered by the user which needs to meet
 * the described criteria.
 * Author: Jose Luis Castillo
 */

#include <string>	// Needed for the string data type
#include <cstdlib>
#include <cctype>	// Needed for isupper, islower, isdigit.
#include <iostream>
using namespace std;

// Function prototype
bool testPassword(string);

int main()
{
	bool check = false;
	string input;

	cout << " \n\nPlease enter a password that meets the following criteria: \n";
	cout << " It must have at least six characters long.\n";
	cout << " It needs to have at least one uppercase and one lowercase letter.\n";
	cout << " It must contain at least one digit.\n";
	cout << " It can be up to 20 characters long.\n";
	cout << " You may enter 'stop' to stop entering passwords and terminate this program.\n";
	cin >> input;

	// Check for 'stop' request and exit out. Cannot convert to lower/upper case since this could be the password.
	if (input == "stop" || input == "STOP" || input == "Stop") {
		cout << "\nYou requested to stop this program. Exiting now ...\n";
		exit(0);
	}


	do {
		cout << "\n\tThe password entered is: " << input << endl;
	
		check = testPassword(input); 		// test the password's criteria

		if (check == true) {
			cout << "The password meets the criteria. Exiting program now  ... \n";
			exit(0);
		} 
		
		 // Else, re-display the menu to the user
		cout << " \n\nPlease enter a password that meets the following criteria: \n";
		cout << " It must have at least six characters long.\n";
		cout << " It needs to have at least one uppercase and one lowercase letter.\n";
		cout << " It must contain at least one digit.\n";
		cout << " It can be up to 20 characters long.\n";
		cout << " You may enter 'stop' to stop entering passwords and terminate this program.\n";
		cin >> input;


		// Check for 'stop' request again and exit out accordingly
		// Cannot convert to lower/upper case since this could be the password.
		if (input == "stop" || input == "STOP" || input == "Stop") {
			cout << "\nYou requested to stop this program. Exiting now ...\n";
			exit(0);
		}
	
	} while(input != "stop" || input != "STOP" || input != "Stop" || check != true);
	
	return 0;
}


/* Tests the password's criteria */
bool testPassword(string password)
{
	int length = password.length();			
	
	// Test minimum length
	if(length < 6) {
		cout << "\tYour password is not at least 6 characters in length. Try again.\n";
		return false;
	}		

	// Test for at least an upper case letter.
	int upperCount = 0;
	for (int i = 0; i < length; ++i)
	{
		if(isupper(password[i]))
		{
			upperCount += 1;
			if (upperCount >= 1) break; // passed this check
		}
	}

	if (upperCount < 1) {
		cout << "\tYour password does not contain at least an upper case letter. Try again.\n";
		return false;
	}

	// Test the string for a lower case letter.
	int lowerCount = 0;
	for (int i = 0; i < length; ++i)
	{
		if(islower(password[i]))
		{
			lowerCount += 1;
			if (lowerCount >= 1) break; // passed this check
		}
	}

	if (lowerCount < 1) {
		cout << "\tYour password does not contain at least a lower case letter. Try again.\n";
		return false;
	}

	// Test the string for numeric digits.
	int digitCount = 0;
	for (int i = 0; i < length; ++i)
	{
		if(isdigit(password[i]))
		{
			digitCount += 1;
			if (digitCount >= 1) break;
		}
	}

	if (digitCount < 1) {
		cout << "\tYour password does not contain at least one digit. Try again.\n";
		return false;
	}

	// Test for the maximum string length allowed
	if (length > 20) {
		cout << "\tYour password exceeded the maximum 20-character length. Try again.\n";
		return false;
	}


	return true;	// All criteria met, password is acceptable
}
