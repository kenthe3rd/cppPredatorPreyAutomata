/** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** * ** *** ** *
 *Ken Hall	3/21/2018
 *
 *CS 162 400	FINAL PROJECT
 *:::SPACE HEADER FILE:::
 ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** **/

#ifndef SPACE_HPP
#define SPACE_HPP
#include <string>
using std::string;
class Space
{
	protected:
		Space* top;
		Space* right;
		Space* bottom;
		Space* left;
	public:
		virtual ~Space();
		virtual void setAdj(Space*, Space*, Space*, Space*) = 0;
		virtual string getName() = 0;
		virtual Space* moveTo(int) = 0;
		virtual void setAnswer(int);
		virtual void setQuestion(string);
		virtual void getQuestion();
		virtual bool guessAnswer(int);
		virtual void setItemName(string);
		virtual string getItemName();
		virtual void setBackpack(bool);
		virtual bool openTheExit(int);
		virtual bool winTheGame();
		virtual void depositItem();
		virtual bool backpackTaken();
};
#endif
