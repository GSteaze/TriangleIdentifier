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
	double InvalidInput(double userInput);

	/*
	Examines the three side lengths from the user, identifies the hypotenuse, and makes the hypotenuse sidesOfTriangle[2]

	@param sidesOfTriangle the array that contains the lengths input by the user
	*/
	void HypotenuseLocator(double sidesOfTriangle[]);

	/*
	Calculates the expected length of the hypotenuse using the pythagorean theorem

	@param sidesOfTriangle[] the array that contains the reordered lengths of the triangle sides

	@return expectedHypotenuseLength the expected length based on the theorem
	*/
	double ExpectedHypotenuseLength(double sidesOfTriangle[]);

	/*
	Compares the hypotenuse input by the user with the calculated hypotenuse to determine if the triangle is a right triangle

	@param sidesOfTriangle the array that contains the reordered lengths of the triangle sides
	@param expectedHypotenuseLength the expected length based on the pythagorean theorem
	@return returns true if the user given input and the expected hypotenuse are the same
	*/
	bool IsItRight(double sidesOfTriangle[], double expectedHypotenuseLength);

	/*
	Tests if the triangle is an isosceles triangle

	@param sidesOfTriangle

	@return returns true if there are exactly two sides of equal length
	*/
	bool IsItIsosceles(double sidesOfTriangle[]);

	/*
	Tests if the triangle is a scalene triangle

	@param sidesOfTriangle

	@return returns true if there are no sides of equal length
	*/
	bool IsItScalene(double sidesOfTriangle[]);

	/*
	Tests if the triangle is an equilateral triangle

	@param sidesOfTriangle[]

	@ return returns true if all three sides of the triangle are of equal length
	*/
	bool IsItEquilateral(double sidesOfTriangle[]);

	/*
	Displays the results on the console
	*/
	void DisplayResults(double sidesOfTriangle[], double expectedHypotenuseLength);

	/*
	Contains test cases for functions
	*/
	void TestCases();


}

#endif
