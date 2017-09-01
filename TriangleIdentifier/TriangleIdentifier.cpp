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
	void UserInput(double sidesOfTriangle[])
	{
		double sideOne = 0.0;
		double sideTwo = 0.0;
		double sideThree = 0.0;

		cout << "Please enter the three sides of the triangle" << endl
			<< "Side One : ";
		cin >> sideOne;
		sideOne = InvalidInput(sideOne);
		
		cout << endl << "Side Two : ";
		cin >> sideTwo;
		sideTwo = InvalidInput(sideTwo);

		cout << endl << "Side Three : ";
		cin >> sideThree;
		sideThree = InvalidInput(sideThree);
		

		sidesOfTriangle[0] = sideOne;
		sidesOfTriangle[1] = sideTwo;
		sidesOfTriangle[2] = sideThree;

		return;
	}

	void InitializeArray(double arrayToBeInitialized[], int size, double defaultValue)
	{
		for (int index = 0; index < size; index++)
		{
			arrayToBeInitialized[index] = defaultValue;
		}
	}

	double InvalidInput(double userInput)
	{
		bool isInvalid = (cin.fail()) || (userInput < kMinimumSideLength);
		while (isInvalid)
		{
			cin.clear();
			cin >> userInput;
			isInvalid = (cin.fail()) || (userInput < kMinimumSideLength);
		}

		return userInput;
	}

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

	double ExpectedHypotenuseLength(double sidesOfTriangle[])
	{
		double aSquaredPlusBSquared = (sidesOfTriangle[0] * sidesOfTriangle[0]) + (sidesOfTriangle[1] * sidesOfTriangle[1]);
		
		return sqrt(aSquaredPlusBSquared);
	}

	bool IsItRight(double sidesOfTriangle[], double expectedHypotenuseLength)
	{
		bool isItRight = 0;
		if (abs(sidesOfTriangle[2] - expectedHypotenuseLength) < kStandardOfPrecision)
		{
			return isItRight = 1;
		}
		else return isItRight = 0;
	}
	void DisplayResults(double sidesOfTriangle[], double expectedHypotenuseLength, bool isItRight)
	{
		cout << "The triangle has sides " << sidesOfTriangle[0] << ", " << sidesOfTriangle[1] << ",and apparent hypotenuse " << sidesOfTriangle[2] << "." << endl
			<< "The expected hypotenuse is " << expectedHypotenuseLength << "." << endl;
		if (isItRight)
		{
			cout << "This triangle is a right triangle." << endl;
		}
		else if (!isItRight)
		{
			cout << "This triangle is not a right triangle." << endl;
		}
	}

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