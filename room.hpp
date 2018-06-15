/** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** * ** *** ** *
 *Ken Hall	3/21/2018
 *
 *CS 162 400	FINAL PROJECT
 *:::ROOM HEADER FILE:::
 ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** **/

#ifndef ROOM_HPP
#define ROOM_HPP
#include <string>
using std::string;
#include "space.hpp"
class Room : public Space
{
	private:
		bool hasItem;
		string name;
		int answer;
		string question;
		string itemName;
	public:
		Room(string);
		void setAdj(Space*, Space*, Space*, Space*);
		void setHasItem(bool);
		string getName();
		Space* moveTo(int);
		void setAnswer(int);
		void setQuestion(string);
		void getQuestion();
		bool guessAnswer(int);
		void setItemName(string);
		string getItemName();
};
#endif

