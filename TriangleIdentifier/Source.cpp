#include <iostream>
#include <fstream>
#include <string>

#include "TriangleIdentifier.h"

using namespace std;
using namespace triangleidentifier;

const int kNumberOfTriangleSides = 3;
const int kDefaultArrayValue = 0;

int main()
{
	double sidesOfTriangle[3];
	InitializeArray(sidesOfTriangle, kNumberOfTriangleSides, kDefaultArrayValue);
	UserInput(sidesOfTriangle);
	HypotenuseLocator(sidesOfTriangle);
	double expectedHypotenuseLength = ExpectedHypotenuseLength(sidesOfTriangle);
	bool isItRight = IsItRight(sidesOfTriangle, expectedHypotenuseLength);
	DisplayResults(sidesOfTriangle, expectedHypotenuseLength, isItRight);
	return 0;
	//TestCases();
}