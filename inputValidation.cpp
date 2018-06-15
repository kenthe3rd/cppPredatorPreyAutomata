/** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** * ** *** ** *
 *Ken Hall 	3/04/2018	
 *
 *CS 162 400	Project 4
 *:::INPUT VALIDATION IMPLEMENTATION FILE:::
 ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** **/

#include "inputValidation.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


/******************************************************************************
 *ENFORCE_INT: loops until user enters integer, then returns
 *that integer
 *****************************************************************************/

int InputValidation::enforceInt()
{
	validInput = false;
	int output = -1;
	while(!validInput)
	{
		cout << " (Please enter an integer) :";
		cin >> output;
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Invalid entry. Try again." << endl;
		}
		else if(cin.peek() != 10)
		{
			cout << "Invalid entry. Try again." << endl;
		}
		else
		{
			//break out of loop
			validInput = true;
		}
	}
	return output;
}



/******************************************************************************
 *ENFORCE_INT: loops until user enters positive integer below or eqaual
 *to specified upper limit, and below lower limit then returns that integer
 *****************************************************************************/

int InputValidation::enforceInt(int lowerLimit, int upperLimit)
{
	validInput = false;
	int output = -1;
	while(!validInput)
	{
		cout << " (Please enter a positive integer between " 
		<< lowerLimit << " and " << upperLimit << ") :";
		cin >> output;
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Invalid entry. Try again." << endl;
		}
		else if(output < lowerLimit)
		{
			cout << "Entry too small.  Try again." << endl;
		}
		else if(output > upperLimit)
		{
			cout << "Entry too large. Try again." << endl;
		}
		else if(cin.peek() != 10)
		{
			cout << "Invalid entry. Try again." << endl;
		}
		else
		{
			//break out of loop
			validInput = true;
		}
	}
	return output;
}




/******************************************************************************
 *ENFORCE_POSTIVE_INT: loops until user enters positive integer, then returns
 *that integer
 *****************************************************************************/

int InputValidation::enforcePositiveInt()
{
	validInput = false;
	int output = -1;
	while(!validInput)
	{
		cout << " (Please enter a positive integer) :";
		cin >> output;
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Invalid entry. Try again." << endl;
		}
		else if(output < 1)
		{
			cout << "Entry too small.  Try again." << endl;
		}
		else if(cin.peek() != 10)
		{
			cout << "Invalid entry. Try again." << endl;
		}
		else
		{
			//break out of loop
			validInput = true;
		}
	}
	return output;
}




/******************************************************************************
 *ENFORCE_POSTIVE_INT: loops until user enters positive integer below or eqaual
 *to specified limit, then returns that integer
 *****************************************************************************/

int InputValidation::enforcePositiveInt(int upperLimit)
{
	validInput = false;
	int output = -1;
	while(!validInput)
	{
		cout << " (Please enter a positive integer) :";
		cin >> output;
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Invalid entry. Try again." << endl;
		}
		else if(output < 1)
		{
			cout << "Entry too small.  Try again." << endl;
		}
		else if(output > upperLimit)
		{
			cout << "Entry too large. Try again." << endl;
		}
		else if(cin.peek() != 10)
		{
			cout << "Invalid entry. Try again." << endl;
		}
		else
		{
			//break out of loop
			validInput = true;
		}
	}
	return output;
}





/******************************************************************************
 *ENFORCE_POSITIVE_DOUBLE: loops until user enters positive double, then returns
 *that double
 *****************************************************************************/

double InputValidation::enforcePositiveDouble(double upperLimit)
{
	validInput = false;
	double output = -1.1;
	while(!validInput)
	{
		cout << " (Please enter a positive double <= " << upperLimit
		<< " ) : ";
		cin >> output;
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Invalid entry. Try again." << endl;
		}
		else if(output > upperLimit || output < 0)
		{
			cout << "Outside acceptable range. Try again." << endl;
		}
		else if(cin.peek() != 10)
		{
			cout << "Invalid entry. Try again." << endl;
		}
		else
		{
			validInput = true;
		}
	}
	return output;
}
