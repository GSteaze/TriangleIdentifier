#include <iostream>
#include <fstream>
#include <string>

#include "TriangleIdentifier.h"

using namespace std;

const int kEndOfLine = 1024;

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

	void TestCases()
	{
		//UserInput

		//InitializeArray

		//InvalidInput
	}

};