/** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** * ** *** ** *
 *Ken Hall	3/21/2018
 *
 *CS 162 400	FINAL PROJECT
 *:::ROOM IMPLEMENTATION FILE:::
 ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** **/
#include <iostream>
using std::cout;
using std::endl;
#include "room.hpp"
#include <string>
using std::string;
#include "space.hpp"
/*****************************************************************************
 *CONSTRUCTOR
 ****************************************************************************/

Room::Room(string roomName)
{
	hasItem = true;
	name = roomName;
}


/*****************************************************************************
 *SET_ADJ: builds the room's neighborhood
 ****************************************************************************/

void Room::setAdj(Space* up, Space* r, Space* d, Space* l)
{
	top = up;
	right = r;
	bottom = d;
	left = l;
}



/*****************************************************************************
 *SET_HAS_ITEM: mutator for flag dictating whether or not room has an item
 ****************************************************************************/

void Room::setHasItem(bool setter)
{
	hasItem = setter;
}



/*****************************************************************************
 *GET_NAME: returns the name of the room
 ****************************************************************************/

string Room::getName()
{
	return name;
}



/*****************************************************************************
 *MOVE_TO: moves to the linked Space as indicated by the passed argument
 ****************************************************************************/

Space* Room::moveTo(int direction)
{
	if(direction == 1)
	{
		return top;
	}
	else if(direction == 2)
	{
		return right;
	}
	else if(direction == 3)
	{
		return bottom;
	}
	else if(direction == 4)
	{
		return left;
	}
	else
	{
		return nullptr;
	}
}



/*****************************************************************************
 *SET_ANSWER: mutator for answer member variable
 ****************************************************************************/

void Room::setAnswer(int ans)
{
	answer = ans;
}



/*****************************************************************************
 *SET_QUESTION: mutator for question member variable
 ****************************************************************************/

void Room::setQuestion(string Q)
{
	question = Q;
}



/*****************************************************************************
 *GUESS_ANSWER: checks argument against answer member variable for match
 ****************************************************************************/

bool Room::guessAnswer(int guess)
{
	if(hasItem)
	{
		if(guess == answer)
		{
			cout << "Correct!" << endl;
			hasItem = false;
			return true;
		}
		else
		{
			
			cout << "Wrong!" << endl;
			return false;
		}
	}
	else
	{
		cout << "What are you doing? You already solved this room."
		<< endl;

		return false;
	}
}



/*****************************************************************************
 *GET_QUESTION: prints the room's question
 ****************************************************************************/

void Room::getQuestion()
{
	if(hasItem)
	{
		cout << endl << endl <<  "You read the following text from " 
		<< "the wall:" << endl << question << endl << endl;
	}
	else
	{
		cout << endl << "The writing on the wall is mysteriously "
		<< "absent." << endl;
	}
}



/*****************************************************************************
 *SET_ITEM_NAME: sets the name of the room's item
 ****************************************************************************/

void Room::setItemName(string iName)
{
	itemName = iName;
}



/*****************************************************************************
 *GET_ITEM_NAME: returns the name of the room's item
 ****************************************************************************/

string Room::getItemName()
{
	return itemName;
}
