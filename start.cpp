/** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** * ** *** ** *
 *Ken Hall	3/21/2018
 *
 *CS 162 400	FINAL PROJECT
 *:::START IMPLEMENTATION FILE:::
 ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** **/

#include "start.hpp"
#include <string>
using std::string;
#include "space.hpp"
/*****************************************************************************
 *CONSTRUCTOR
 ****************************************************************************/

Start::Start()
{
	name = "START";
	pickedUpBackpack = false;
}


/*****************************************************************************
 *SET_ADJ: builds the room's neighborhood
 ****************************************************************************/

void Start::setAdj(Space* up, Space* r, Space* d, Space* l)
{
	top = up;
	right = r;
	bottom = d;
	left = l;
}



/*****************************************************************************
 *GET_NAME: returns the name of the room
 ****************************************************************************/

string Start::getName()
{
	return name;
}



/*****************************************************************************
 *MOVE_TO: moves to the linked Space as indicated by the passed argument
 ****************************************************************************/

Space* Start::moveTo(int direction)
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
 *SET_BACKPACK: sets the state of backpack being picked up
 ****************************************************************************/

void Start::setBackpack(bool setter)
{
	pickedUpBackpack = setter;
}



/*****************************************************************************
 *BACKPACK_TAKEN: returns whether or not the backpack has been picked up
 ****************************************************************************/

bool Start::backpackTaken()
{
	return pickedUpBackpack;
}
