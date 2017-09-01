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