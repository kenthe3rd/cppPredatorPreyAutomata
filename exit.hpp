/** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** * ** *** ** *
 *Ken Hall	3/21/2018
 *
 *CS 162 400	FINAL PROJECT
 *:::EXIT HEADER FILE:::
 ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** **/

#ifndef EXIT_HPP
#define EXIT_HPP
#include "space.hpp" 
class Exit : public Space
{
	private:
		string name;
		int itemsDeposited;
	public:
		Exit();
		void setAdj(Space*, Space*, Space*, Space*);
		string getName();
		Space* moveTo(int);
		bool winTheGame();
		void depositItem();
};
#endif

