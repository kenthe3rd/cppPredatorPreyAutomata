/** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** * ** *** ** *
 *Ken Hall	3/21/2018
 *
 *CS 162 400	FINAL PROJECT
 *:::START HEADER FILE:::
 ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** **/

#ifndef START_HPP
#define START_HPP
#include <string>
using std::string;
#include "space.hpp"
class Start : public Space
{
	private:
		string name;
		bool pickedUpBackpack;		
	public:
		Start();
		void setAdj(Space*, Space*, Space*, Space*);
		string getName();
		Space* moveTo(int);
		void setBackpack(bool);
		bool backpackTaken();
};
#endif

