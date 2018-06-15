/** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** * ** *** ** *
 *Ken Hall 	2/25/2018	
 *
 *CS 162 400	Lab 7	
 *:::MENU IMPLEMENTATION FILE:::
 ** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** * */

#include "menu.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <string>
using std::string;

/*****************************************************************************
 *CONSTRUCTORS
 ****************************************************************************/
Menu::Menu(){}

Menu::Menu(string arg1, string arg2)
{
	item1 = arg1;
	item2 = arg2;
}

Menu::Menu(string arg1, string arg2, string arg3)
{
	item1 = arg1;
	item2 = arg2;
	item3 = arg3;
}

Menu::Menu(string arg1, string arg2, string arg3, string arg4)
{
	item1 = arg1;
	item2 = arg2;
	item3 = arg3;
	item4 = arg4;
}

Menu::Menu(string arg1, string arg2, string arg3, string arg4, string arg5)
{
	item1 = arg1;
	item2 = arg2;
	item3 = arg3;
	item4 = arg4;
	item5 = arg5;
}

Menu::Menu(string arg1, string arg2, string arg3, string arg4, string arg5,
string arg6)
{
	item1 = arg1;
	item2 = arg2;
	item3 = arg3;
	item4 = arg4;
	item5 = arg5;
	item6 = arg6;
}

Menu::Menu(string arg1, string arg2, string arg3, string arg4, string arg5,
string arg6, string arg7)
{
	item1 = arg1;
	item2 = arg2;
	item3 = arg3;
	item4 = arg4;
	item5 = arg5;
	item6 = arg6;
	item7 = arg7;
}

Menu::Menu(string arg1, string arg2, string arg3, string arg4, string arg5,
string arg6, string arg7, string arg8)
{
	item1 = arg1;
	item2 = arg2;
	item3 = arg3;
	item4 = arg4;
	item5 = arg5;
	item6 = arg6;
	item7 = arg7;
	item8 = arg8;
}

Menu::Menu(string arg1, string arg2, string arg3, string arg4, string arg5,
string arg6, string arg7, string arg8, string arg9)
{
	item1 = arg1;
	item2 = arg2;
	item3 = arg3;
	item4 = arg4;
	item5 = arg5;
	item6 = arg6;
	item7 = arg7;
	item8 = arg8;
	item9 = arg9;
}



/*****************************************************************************
 *ENFORCE_VALID_INPUT: checks to see which of the menu member variables are not
 *empty strings, and adjusts range of acceptable inputs based on number of
 *member variables that are not empty strings
 ****************************************************************************/
int Menu::enforceValidInput()
{
	//reset userSelection to default
	userSelection = 0;
	bool acceptableInput = false;
	//min menu size is 2, so we start checking with 3
	validInputs = 2;
	if(item3 != "")
	{
		validInputs++;			// =3
		if(item4 != "")
		{
			validInputs++;		// =4
			if(item5 != "")
			{
				validInputs++;	// =5
				if(item6 != "")
				{
					validInputs++;
					if(item7 != "")
					{
						validInputs++;
						if(item8 != "")
						{
							validInputs++;
							if(item9 != "")
							{
								validInputs++;
							}
						}
					}
				}
			}
		}
	}
	
	while(!acceptableInput)
	{
		cin >> userSelection;
		if(cin.fail())
		{	
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Invalid input. Please try again." << endl;
		}
		else if(userSelection < 1 || userSelection > validInputs)
		{
			cout << "Input outside of acceptable range. " << 
			"Please try again." << endl;
		}
		else if(cin.peek() != 10)
		{
			cout << "Whatever nonsense you entered didn't fit. "
			<< endl;
		}
		else
		{
			acceptableInput = true;
		}
	}
	
	return userSelection;
}



/*****************************************************************************
 *DISPLAY_MENU: displays each item of a menu on a separate line, preceded by
 *the item#
 ****************************************************************************/
void Menu::displayMenu()
{
	cout << endl << endl;
	cout << "1: " << item1 << endl;
	cout << "2: " << item2 << endl;
	if(item3 != "")
	{
		cout << "3: " << item3 << endl;
	}
	if(item4 != "")
	{
		cout << "4: " << item4 << endl;
	}
	if(item5 != "")
	{
		cout << "5: " << item5 << endl;
	}
	if(item6 != "")
	{
		cout << "6: " << item6 << endl;
	}
	if(item7 != "")
	{
		cout << "7: " << item7 << endl;
	}
	if(item8 != "")
	{
		cout << "8: " << item8 << endl;
	}
	if(item9 != "")
	{
		cout << "9: " << item9 << endl;
	}
	cout << endl << endl;
}

/*****************************************************************************
 *SET_ITEMS: resets the items of the Menu
 ****************************************************************************/
void Menu::setItems(string str1, string str2)
{
	item1 = str1;
	item2 = str2;
}

void Menu::setItems(string str1, string str2, string str3)
{
	item1 = str1;
	item2 = str2;
	item3 = str3;
}

void Menu::setItems(string str1, string str2, string str3, string str4)
{
	item1 = str1;
	item2 = str2;
	item3 = str3;
	item4 = str4;
}

void Menu::setItems(string str1, string str2, string str3, string str4,
string str5, string str6)
{
	item1 = str1;
	item2 = str2;
	item3 = str3;
	item4 = str4;
	item5 = str5;
	item6 = str6;
}

void Menu::setItems(string str1, string str2, string str3, string str4,
string str5, string str6, string str7)
{
	item1 = str1;
	item2 = str2;
	item3 = str3;
	item4 = str4;
	item5 = str5;
	item6 = str6;
	item7 = str7;
}

void Menu::setItems(string str1, string str2, string str3, string str4,
string str5, string str6, string str7, string str8)
{
	item1 = str1;
	item2 = str2;
	item3 = str3;
	item4 = str4;
	item5 = str5;
	item6 = str6;
	item7 = str7;
	item8 = str8;
}

void Menu::setItems(string str1, string str2, string str3, string str4,
string str5, string str6, string str7, string str8, string str9)
{
	item1 = str1;
	item2 = str2;
	item3 = str3;
	item4 = str4;
	item5 = str5;
	item6 = str6;
	item7 = str7;
	item8 = str8;
	item9 = str9;
}
