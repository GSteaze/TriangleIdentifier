#include <iostream>
#include <fstream>
#include <string>

#include "TriangleIdentifier.h"

using namespace std;

const int kEndOfLine = 1024;
const double kStandardOfPrecision = .01;

namespace triangleidentifier
{
	void UserInput(double sidesOfTriangle[])
	{
		int sideOne = 0;
		int sideTwo = 0;
		int sideThree = 0;

		cout << "Please enter the three sides of the triangle" << endl
			<< "Side One : ";
		cin >> sideOne;
		sideOne = InvalidInput(sideOne);
		cout << endl << "Side Two : ";
		cin >> sideTwo;
		sideTwo = InvalidInput(sideTwo);
		cout << endl << "Side Three : ";
		sideThree = InvalidInput(sideThree);
		cin >> sideThree;

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

	int InvalidInput(double userInput)
	{
		bool isInvalid = cin.fail() || (userInput < '0' || userInput > '9');
		while (isInvalid)
		{
			cin.clear();
			cin.ignore(kEndOfLine, '\n');
			cout << "Please try again : ";
			cin >> userInput;
			isInvalid = cin.fail() || (userInput < '0' || userInput > '9');
		}

		return userInput;
	}

	void HypotenuseLocator(double sidesOfTriangle[])
	{
		if ((sidesOfTriangle[2] > sidesOfTriangle[1]) && (sidesOfTriangle[2] > sidesOfTriangle[0]))
		{
			return;
		}
		else if ((sidesOfTriangle[1] > sidesOfTriangle[0]) && (sidesOfTriangle[1] > sidesOfTriangle[2]))
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
	}

	double ExpectedHypotenuseLength(double sidesOfTriangle[])
	{
		double aSquaredPlusBSquared = (sidesOfTriangle[0] * sidesOfTriangle[0]) + (sidesOfTriangle[1] * sidesOfTriangle[1]);
		
		double expectedHypotenuseLength = 0;
		return expectedHypotenuseLength = sqrt(aSquaredPlusBSquared);
	}

	bool IsItRight(double sidesOfTriangle[], double expectedHypotenuseLength)
	{
		bool isItRight = 0;
		if (abs(sidesOfTriangle[2] - expectedHypotenuseLength) < kStandardOfPrecision)
		{
			return isItRight = 1;
		}
		else return;
	}

	void TestCases()
	{
		//UserInput

		//InitializeArray

		//InvalidInput
	}

};