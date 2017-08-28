#ifndef TRIANGLEIDENTIFIER_H
#define TRIANGLEIDENTIFIER_H

#include <string>

using namespace std;

namespace triangleidentifier
{
	/*
	Prompts the user for the length of each side of the triangle and inputs the data

	@param the array that the user input will be stored in
	*/
	void UserInput(double[]);

	/*
	Initializes the array

	@param double arrayToBeInitialized [] the array that will be filled
	@param int size the size of the array
	@param double defaultValue the value that will be used to initialize the array
	*/
	void InitializeArray(double arrayToBeInitialized[], int size, double defaultValue);

	/*
	Checks if the user input is a valid value

	@param double userInput the input from the user
	*/
	int InvalidInput(double userInput);

	/*
	Contains test cases for functions
	*/
	void TestCases();


}

#endif
