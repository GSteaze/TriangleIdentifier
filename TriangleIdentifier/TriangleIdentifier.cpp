#include <iostream>
#include <fstream>
#include <string>

#include "TriangleIdentifier.h"

using namespace std;

const int kEndOfLine = 1024;
const double kMinimumSideLength = 0.1;
const double kStandardOfPrecision = .01;

namespace triangleidentifier
{
	/*
	Prompts the user for the length of each side of the triangle and inputs the data

	@param the array that the user input will be stored in
	*/
	void UserInput(double sidesOfTriangle[])
	{
		double sideOne = 0.0;
		double sideTwo = 0.0;
		double sideThree = 0.0;

		cout << "Please enter the three sides of the triangle." << endl
			<< "Side One : ";
		cin >> sideOne;
		sideOne = InvalidInput(sideOne);
		
		cout << "Side Two : ";
		cin >> sideTwo;
		sideTwo = InvalidInput(sideTwo);

		cout << "Side Three : ";
		cin >> sideThree;
		sideThree = InvalidInput(sideThree);
		

		sidesOfTriangle[0] = sideOne;
		sidesOfTriangle[1] = sideTwo;
		sidesOfTriangle[2] = sideThree;

		return;
	}

	/*
	Initializes the array

	@param double arrayToBeInitialized [] the array that will be filled
	@param int size the size of the array
	@param double defaultValue the value that will be used to initialize the array
	*/
	void InitializeArray(double arrayToBeInitialized[], int size, double defaultValue)
	{
		for (int index = 0; index < size; index++)
		{
			arrayToBeInitialized[index] = defaultValue;
		}
	}

	/*
	Checks if the user input is a valid value

	@param double userInput the input from the user
	*/
	double InvalidInput(double userInput)
	{
		bool isInvalid = (cin.fail()) || (userInput < kMinimumSideLength);
		while (isInvalid)
		{
			cout << "Please try again : ";
			cin.clear();
			cin.ignore(kEndOfLine, '\n');
			cin >> userInput;
			isInvalid = (cin.fail()) || (userInput < kMinimumSideLength);
		}

		return userInput;
	}

	/*
	Examines the three side lengths from the user, identifies the hypotenuse, and makes the hypotenuse sidesOfTriangle[2]

	@param sidesOfTriangle the array that contains the lengths input by the user
	*/
	void HypotenuseLocator(double sidesOfTriangle[])
	{
		if ((sidesOfTriangle[1] > sidesOfTriangle[0]) && (sidesOfTriangle[1] > sidesOfTriangle[2]))
		{
			double temporaryNumber = 0;
			temporaryNumber = sidesOfTriangle[2];
			sidesOfTriangle[2] = sidesOfTriangle[1];
			sidesOfTriangle[0] = temporaryNumber;
			return;
		}
		else if ((sidesOfTriangle[0] > sidesOfTriangle[1]) && (sidesOfTriangle[0] > sidesOfTriangle[2]))
		{
			double temporaryNumber = 0;
			temporaryNumber = sidesOfTriangle[2];
			sidesOfTriangle[2] = sidesOfTriangle[0];
			sidesOfTriangle[0] = temporaryNumber;
			return;
		}
		else
		{
			return;
		}
	}

	/*
	Calculates the expected length of the hypotenuse using the pythagorean theorem

	@param sidesOfTriangle[] the array that contains the reordered lengths of the triangle sides

	@return expectedHypotenuseLength the expected length based on the theorem
	*/
	double ExpectedHypotenuseLength(double sidesOfTriangle[])
	{
		double aSquaredPlusBSquared = (sidesOfTriangle[0] * sidesOfTriangle[0]) + (sidesOfTriangle[1] * sidesOfTriangle[1]);
		
		return sqrt(aSquaredPlusBSquared);
	}

	/*
	Compares the hypotenuse input by the user with the calculated hypotenuse to determine if the triangle is a right triangle

	@param sidesOfTriangle the array that contains the reordered lengths of the triangle sides
	@param expectedHypotenuseLength the expected length based on the pythagorean theorem
	@return returns true if the user given input and the expected hypotenuse are the same
	*/
	bool IsItRight(double sidesOfTriangle[], double expectedHypotenuseLength)
	{
		bool isItRight = 0;
		if (abs(sidesOfTriangle[2] - expectedHypotenuseLength) < kStandardOfPrecision)
		{
			return isItRight = 1;
		}
		else return isItRight = 0;
	}

	/*
	Tests if the triangle is an isosceles triangle

	@param sidesOfTriangle

	@return returns true if there are exactly two sides of equal length
	*/
	bool IsItIsosceles(double sidesOfTriangle[])
	{
		bool isItIsosceles = 0;
		if ((sidesOfTriangle[0] == sidesOfTriangle[1])
			&& (sidesOfTriangle[0] != sidesOfTriangle[2]))
		{
			return isItIsosceles = 1;
		}
		else if ((sidesOfTriangle[0] == sidesOfTriangle[2])
			&& (sidesOfTriangle[0] != sidesOfTriangle[1]))
		{
			return isItIsosceles = 1;
		}
		else if ((sidesOfTriangle[2] == sidesOfTriangle[1])
			&& (sidesOfTriangle[2] != sidesOfTriangle[0]))
		{
			return isItIsosceles = 1;
		}
		else
		{
			return isItIsosceles = 0;
		}
	}

	/*
	Tests if the triangle is a scalene triangle

	@param sidesOfTriangle

	@return returns true if there are no sides of equal length
	*/
	bool IsItScalene(double sidesOfTriangle[])
	{
		bool isItScalene = 0;
		if ((sidesOfTriangle[0] != sidesOfTriangle[1])
			&& (sidesOfTriangle[0] != sidesOfTriangle[2])
			&& (sidesOfTriangle[1] != sidesOfTriangle[2]))
		{
			return isItScalene = 1;
		}
		else
		{
			return isItScalene = 0;
		}
	}

	/*
	Tests if the triangle is an equilateral triangle

	@param sidesOfTriangle[]

	@ return returns true if all three sides of the triangle are of equal length
	*/
	bool IsItEquilateral(double sidesOfTriangle[])
	{
		bool isItEquilateral = 0;
		if ((sidesOfTriangle[0] == sidesOfTriangle[1]) && (sidesOfTriangle[0] == sidesOfTriangle[2]))
		{
			return isItEquilateral = 1;
		}
		else
		{
			return isItEquilateral = 0;
		}
	}

	/*
	Displays the results on the console
	*/
	void DisplayResults(double sidesOfTriangle[], double expectedHypotenuseLength)
	{
		bool isItRight = IsItRight(sidesOfTriangle, expectedHypotenuseLength);
		bool isItIsosceles = IsItIsosceles(sidesOfTriangle);
		bool isItScalene = IsItScalene(sidesOfTriangle);
		bool isItEquilateral = IsItEquilateral(sidesOfTriangle);

		cout << "The triangle has sides " << sidesOfTriangle[0] << ", " << sidesOfTriangle[1] << ",and apparent hypotenuse " << sidesOfTriangle[2] << "." << endl
			<< "The expected hypotenuse is " << expectedHypotenuseLength << "." << endl
			<< "This triangle is ";
		if (isItRight)
		{
			cout << "a right triangle." << endl;
		}
		else if (!isItRight)
		{
			cout << "not a right triangle." << endl;
		}

		if (isItIsosceles)
		{
			cout << "It is an isosceles triangle." << endl;
		}
		else if (isItScalene)
		{
			cout << "It is a scalene triangle." << endl;
		}
		else if (isItEquilateral)
		{
			cout << "It is an equilateral triangle." << endl;
		}
	}

	/*
	Contains test cases for functions
	*/
	void TestCases()
	{
		//UserInput

		//InitializeArray

		//InvalidInput
		cout << "Invalid Input Tests:" << endl;
		cout << "Test 0" << endl;
		cout << InvalidInput(0) << endl;
		cout << "Test a" << endl;
		cout << InvalidInput('a') << endl;
		cout << "Test -1" << endl;
		cout << InvalidInput(-1) << endl;
		cout << "Test 1" << endl;
		cout << InvalidInput(1) << endl;

		//InitializeArray
		double arrayToBeInitialized[3];
		int size = 3;
		double defaultValue = 0.0;
		InitializeArray(arrayToBeInitialized, size, defaultValue);
		for (int index = 0; index < 2; index++)
		{
			cout << arrayToBeInitialized[index] << endl;
		}
	}

};