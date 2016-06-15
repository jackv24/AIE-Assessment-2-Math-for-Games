// BitShifting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	//Signed bit-shifting
	int input;

	cout << "Enter an integer (signed): ";
	cin >> input;
	cout << endl;

	cout << "Divided by two: " << (input >> 1) << endl;
	cout << "Multiplied by two: " << (input << 1) << endl;
	cout << endl;

	//Unisgned bit-shifting
	unsigned int uinput;

	cout << "Enter an integer (unsigned): ";
	cin >> uinput;
	cout << endl;

	cout << "Divided by two: " << (uinput >> 1) << endl;
	cout << "Multiplied by two: " << (uinput << 1) << endl;


	system("PAUSE");

    return 0;
}

