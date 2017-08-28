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
	double userInput[3];
	InitializeArray(userInput, kNumberOfTriangleSides, kDefaultArrayValue);
	UserInput(userInput);
	return 0;
}