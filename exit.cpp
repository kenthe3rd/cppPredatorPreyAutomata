/** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** * ** *** ** *
 *Ken Hall	3/21/2018
 *
 *CS 162 400	FINAL PROJECT
 *:::EXIT IMPLEMENTATION FILE:::
 ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** **/

#include "exit.hpp"
#include "space.hpp"
#include <string>
using std::string;


/*****************************************************************************
 *CONSTRUCTOR
 ****************************************************************************/

Exit::Exit()
{
	name = "EXIT";
	itemsDeposited = 0;
}


/*****************************************************************************
 *SET_ADJ: builds the room's neighborhood
 ****************************************************************************/

void Exit::setAdj(Space* up, Space* r, Space* d, Space* l)
{
	top = up;
	right = r;
	bottom = d;
	left = l;
}



/*****************************************************************************
 *GET_NAME: returns the name of the room
 ****************************************************************************/

string Exit::getName()
{
	return name;
}



/*****************************************************************************
 *MOVE_TO: moves to the linked Space as indicated by the passed argument
 ****************************************************************************/

Space* Exit::moveTo(int direction)
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
 *WIN_THE_GAME:Checks to see if the player wins the game
 ****************************************************************************/

bool Exit::winTheGame()
{
	if(itemsDeposited >= 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}



/*****************************************************************************
 *DEPOSIT_ITEM: adds an item to the exit's item counter
 ****************************************************************************/

void Exit::depositItem()
{
	itemsDeposited++;
}
