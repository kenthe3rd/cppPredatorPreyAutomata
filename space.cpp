/** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** * ** *** ** *
 *Ken Hall	3/21/2018
 *
 *CS 162 400	FINAL PROJECT
 *:::SPACE IMPLEMENTATION FILE:::
 ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** **/

#include "space.hpp"
#include <string>
using std::string;

Space::~Space(){};
void Space::setAnswer(int){};
void Space::setQuestion(string){};
void Space::getQuestion(){};
bool Space::guessAnswer(int){};
void Space::setItemName(string){};
string Space::getItemName(){};
bool Space::openTheExit(int){};
void Space::setBackpack(bool){};
bool Space::winTheGame(){};
void Space::depositItem(){};
bool Space::backpackTaken(){};
