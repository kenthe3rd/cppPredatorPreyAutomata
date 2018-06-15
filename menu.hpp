/** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** * ** *** ** *
 *Ken Hall 	2/25/2018	
 *
 *CS 162 400	Lab 7
 *:::MENU HEADER FILE:::
 ** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** * */

#ifndef MENU_HPP
#define MENU_HPP

#include <string>
using std::string;

class Menu
{
	private:
		string item1 = "";	//
		string item2 = "";	////
		string item3 = "";	////menu items//
		string item4 = "";	////
		string item5 = "";	//
		string item6 = "";	//
		string item7 = "";	//
		string item8 = "";	//
		string item9 = "";	//

		int validInputs = 0;	//used in input 
		int userSelection = 0;	//validation
	public:
		Menu();
		Menu(string, string);
		Menu(string, string, string);
		Menu(string, string, string, string);
		Menu(string, string, string, string, string);
		Menu(string, string, string, string, string, string);
		Menu(string, string, string, string, string, string, string);
		Menu(string, string, string, string, string, string, string,
		string);
		Menu(string, string, string, string, string, string, string,
		string, string);
		int enforceValidInput();
		void displayMenu();
		void setItems(string, string);
		void setItems(string, string, string);
		void setItems(string, string, string, string);
		void setItems(string, string, string, string, string);
		void setItems(string, string, string, string, string, string);
		void setItems(string, string, string, string, string, string,
		string);
		void setItems(string, string, string, string, string, string,
		string, string);
		void setItems(string, string, string, string, string, string,
		string, string, string);


};
#endif
