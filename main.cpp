/** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** * ** *** ** *
 *Ken Hall	3/21/2018
 *
 *CS 162 400	FINAL PROJECT
 *:::MAIN IMPLEMENTATION FILE:::
 ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** ** ** ** *** **/

#include "exit.hpp"
#include "space.hpp"
#include "menu.hpp"
#include <string>
using std::string;
#include "room.hpp"
#include "start.hpp"
#include <iostream>
using std::cout;
using std::endl;
#include <unistd.h>
#include <queue>
using std::queue;

void lookAround(Space*);
void intro();

int main()
{
	
	Menu moveMenu("Up", "Right", "Down", "Left", "Interact/Answer",
	 "Check pack");
	Menu mainMenu("Start game", "Quit");
	bool gameEnd = false;
	int moveChoice = 0;
	int menuChoice = 0;
	int playerHealth = 10;
	int stepsRemaining = 25;
	bool isCorrect = false;
	bool hasBackpack = false;
	int itemsInBackpack = -1;
	queue<string> backpackContents;
	//choose between play/quit
	cout << "---------------------------" << endl;
	cout << "---CS 162: THE ADVENTURE---" << endl;
	cout << "---------------------------" << endl;
	mainMenu.displayMenu();
	menuChoice = mainMenu.enforceValidInput();
	if(menuChoice == 2)
	{
		gameEnd = true;
	}
	while(!gameEnd)
	{
		//SETUP THE GAME
		playerHealth = 10;
		stepsRemaining = 25;
		hasBackpack = false;	
		itemsInBackpack = 0;
		while(!backpackContents.empty())
		{
			backpackContents.pop();
		}
		//greet player and provide instructions
		intro();

		//make spaces
		Space* startArea = new Start;
		Space* doodleRoom = new Room("Doodlebug Room");
		Space* zooRoom = new Room("Zoo Room");
		Space* fCombatRoom = new Room("Fantasy Combat Room");
		Space* langtRoom = new Room("Langton's Ant Room");
		Space* stlRoom = new Room("STL Room");
		Space* exitArea = new Exit;

		//link spaces together
		Space* current = startArea;
		startArea->setAdj(doodleRoom, fCombatRoom, exitArea, nullptr);
		doodleRoom->setAdj(nullptr, zooRoom, startArea, nullptr);
		zooRoom->setAdj(nullptr, langtRoom, fCombatRoom, doodleRoom);
		fCombatRoom->setAdj(zooRoom, stlRoom, nullptr, startArea);
		langtRoom->setAdj(nullptr, nullptr, stlRoom, zooRoom);
		stlRoom->setAdj(langtRoom, nullptr, nullptr, fCombatRoom);
		exitArea->setAdj(startArea, nullptr, nullptr, nullptr);

		//set questions + answers for rooms
		string doodleQ = "After how many steps does a doodlebug breed?";
		string zooQ = "A tiger costs how much money?";
		string combQ = "What is Medusa's special ability?";
		string langtQ = "What structure emerges after a few thousand steps?";
		string stlQ = "Which of the following is not a container found in the STL?";

		doodleRoom->setQuestion(doodleQ);
		zooRoom->setQuestion(zooQ);
		fCombatRoom->setQuestion(combQ);
		langtRoom->setQuestion(langtQ);
		stlRoom->setQuestion(stlQ);

		Menu doodleMenu("Three steps", "Eight steps", "One step", "Never");
		Menu zooMenu("$1", "$100", "$10000", "$1000000");
		Menu combMenu("Glare", "Spawn doodlebug", "Deadly Kiss", "Charm");
		Menu langtMenu("Balloon", "Highway", "Duplex", "None");
		Menu stlMenu("Queue", "Stack", "List", "Tupperware");

		doodleRoom->setAnswer(2);
		zooRoom->setAnswer(3);
		fCombatRoom->setAnswer(1);
		langtRoom->setAnswer(2);
		stlRoom->setAnswer(4);

		//set item names
		doodleRoom->setItemName("Doodlebug Larvae");
		zooRoom->setItemName("Turtle Egg");
		fCombatRoom->setItemName("Snake Skin");
		langtRoom->setItemName("Traffic Cone");
		stlRoom->setItemName("Stack of Plates");

		//begin playing
		while(!gameEnd)
		{
			cout << endl<< "HEALTH: " << playerHealth << endl;
			cout << "TIME LEFT: " << stepsRemaining << endl << endl;
			lookAround(current);
			moveMenu.displayMenu();
			moveChoice = moveMenu.enforceValidInput();
			if(current->moveTo(moveChoice) != nullptr)
			{
				if(startArea->backpackTaken())
				{
					//change rooms
					current = current->moveTo(moveChoice);
					cout << "You are now in the " 
					<< current->getName() << endl << endl;

					current->getQuestion();
				}
				else
				{
					cout << "Wait! Don't forget your "
					<< "backpack!" << endl;
				}

			}
			else if(moveChoice != 5 && moveChoice !=6)
			{
				//lol whoops
				cout << "You run into the wall, dealing 1 "
				<< "damage to yourself." << endl;
				playerHealth--;
			}
			else if(moveChoice == 6)
			{
				if(hasBackpack)
				{
					queue<string> copy;
					for(int i=0; i < itemsInBackpack; i++)
					{
						cout << backpackContents.front();
						copy.push(backpackContents.front());
						backpackContents.pop();
						backpackContents.push(copy.front());
						copy.pop();
						cout << ", "; 
					}
					cout << endl << endl;
				}
				else
				{
					cout << "You don't have a backpack."
					<< endl;
				}
			}
			else
			{
				//player selected interact
				if(current == exitArea)
				{
					if(!backpackContents.empty())
					{
						cout << "You place the "
						<< backpackContents.front()
						<< " in the exit chamber."
						<< endl;
						backpackContents.pop();
						itemsInBackpack--;
						current->depositItem();
						if(current->winTheGame())
						{
							//prevent player from losing due to last step
							stepsRemaining++;
							gameEnd = true;
							cout << "You did it! You won!" << endl;
						}
					}
					else
					{
						cout << "You don't have anything"
						<< " to deposit." << endl;
					}
					
				}
				if(current == startArea)
				{
					if(hasBackpack)
					{
						cout << "There is no question to "
						<< "answer here." << endl;
					}
					else
					{
						cout << "You pick up the "
						<< "backpack." << endl;
						hasBackpack = true;
						current->setBackpack(true);
					}
				}
				if(current == doodleRoom)
				{
					doodleMenu.displayMenu();
					menuChoice = doodleMenu.enforceValidInput();
					isCorrect = current->guessAnswer(menuChoice);
					if(isCorrect && hasBackpack)
					{
						if(itemsInBackpack < 2)
						{
							cout << "You got the "
							<< current->getItemName()
							<< endl;
							backpackContents.push(current->getItemName());
							itemsInBackpack++;

							
						}
						else
						{
							cout << "You become "
							<< "overencumbered, "
							<< "killing you "
							<< "instantly." << endl;
							playerHealth = 0;
						}
					}
					else
					{
						cout << "A doodlebug drops from"
						<< " the ceiling and bites you "
						<< "causing 1 damage." << endl;
						playerHealth--;
					}
				}
				if(current == zooRoom)
				{
					zooMenu.displayMenu();
					menuChoice = zooMenu.enforceValidInput();
					isCorrect = current->guessAnswer(menuChoice);
					if(isCorrect && hasBackpack)
					{
						if(itemsInBackpack < 2)
						{
							cout << "You got the "
							<< current->getItemName()
							<< endl;
							backpackContents.push(current->getItemName());
							itemsInBackpack++;
						}
						else
						{
							cout << "You become "
							<< "overencumbered, "
							<< "killing you "
							<< "instantly." << endl;
							playerHealth = 0;
						}
					}
					else
					{
						cout << "A tiger drops from"
						<< " the ceiling and mauls you "
						<< "causing 1 damage." << endl;
						playerHealth--;
					}
				}
				if(current == fCombatRoom)
				{
					combMenu.displayMenu();
					menuChoice = combMenu.enforceValidInput();
					isCorrect = current->guessAnswer(menuChoice);
					if(isCorrect && hasBackpack)
					{
						if(itemsInBackpack < 2)
						{
							cout << "You got the "
							<< current->getItemName()
							<< endl;
							backpackContents.push(current->getItemName());
							itemsInBackpack++;

						}
						else
						{
							cout << "You become "
							<< "overencumbered, "
							<< "killing you "
							<< "instantly." << endl;
							playerHealth = 0;
						}
					}
					else
					{
						cout << "A Medusa drops from"
						<< " the ceiling and makes eye "
						<< "contact with you, killing "
						<< "you instantly." << endl;
						playerHealth = 0;
					}				
				}
				if(current == langtRoom)
				{
					langtMenu.displayMenu();
					menuChoice = langtMenu.enforceValidInput();
					isCorrect = current->guessAnswer(menuChoice);
					if(isCorrect && hasBackpack)
					{
						if(itemsInBackpack < 2)
						{
							cout << "You got the "
							<< current->getItemName()
							<< endl;
							backpackContents.push(current->getItemName());
							itemsInBackpack++;
						}
						else
						{
							cout << "You become "
							<< "overencumbered, "
							<< "killing you "
							<< "instantly." << endl;
							playerHealth = 0;
						}
					}
					else
					{
						cout << "An ant drops from"
						<< " the ceiling and lands on "
						<< "your forehead.  You run "
						<< "into the wall thinking it "
						<< "is a doodlebug, causing 1 " 
						<< "damage."<< endl;
						playerHealth--;
					}
				}
				if(current == stlRoom)
				{
					stlMenu.displayMenu();
					menuChoice = stlMenu.enforceValidInput();
					isCorrect = current->guessAnswer(menuChoice);
					if(isCorrect && hasBackpack)
					{
						if(itemsInBackpack < 2)
						{
							cout << "You got the "
							<< current->getItemName()
							<< endl;
							backpackContents.push(current->getItemName());
							itemsInBackpack++;
						}
						else
						{
							cout << "You become "
							<< "overencumbered, "
							<< "killing you "
							<< "instantly." << endl;
							playerHealth = 0;
						}
					}
					else
					{
						cout << "A container object "
						<< "drops from the ceiling, "
						<< "causing you to segfault "
						<< "and die instantly." << endl;
						playerHealth = 0;
					}
				}
			}


			if(playerHealth <= 0)
			{
				cout << "GAME OVER! YOU DIED." << endl;
				cout << "Rebooting" << endl;
				for(int i=0; i < 10; i++)
				{
					usleep(250000);
					cout << "......" << endl;
				}
				cout << endl;
				gameEnd = true;
			}
			else
			{
				stepsRemaining--;
				if(stepsRemaining == 0)
				{
					gameEnd = true;
					cout << "GAME OVER! YOU TOOK TOO LONG!"
					<< endl;
					cout << "Rebooting" << endl;
					for(int i=0; i < 10; i++)
					{
						usleep(250000);
						cout << "......" << endl;
					}	
				}
			}
			
		}
		
		//free memory
		delete startArea;
		delete doodleRoom;
		delete zooRoom;
		delete fCombatRoom;
		delete langtRoom;
		delete stlRoom;
		delete exitArea;

		//ask to play again before quitting
		gameEnd = false;
		cout << "---------------------------" << endl;
		cout << "---CS 162: THE ADVENTURE---" << endl;
		cout << "---------------------------" << endl;
		mainMenu.displayMenu();
		menuChoice = mainMenu.enforceValidInput();
		if(menuChoice == 2)
		{
			gameEnd = true;
		}
	}
	return 0;
}




/*****************************************************************************
 *MORE FUNCTIONS
 ****************************************************************************/


//the player looks at the adjacent rooms
void lookAround(Space* here)
{
	if(here->moveTo(1) != nullptr)
	{
		cout << "Upstairs is the " 
		<< here->moveTo(1)->getName() 
		<< endl;
	}
	if(here->moveTo(2) != nullptr)
	{
		cout << "On your right is the " 
		<< here->moveTo(2)->getName() 
		<< endl;

	}
	if(here->moveTo(3) != nullptr)
	{
		cout << "Downstairs is the " 
		<< here->moveTo(3)->getName() 
		<< endl;

	}
	if(here->moveTo(4) != nullptr)
	{
		cout << "On your left is the " 
		<< here->moveTo(4)->getName() 
		<< endl;

	}
}

//greet player and provide how to play information
void intro()
{
	cout << "Welcome to CS 162: The Adventure" << endl << endl;

	cout << "In this game, you answer trivia questions about "
	<< "projects and assignments from this term." << endl
	<< "Move to a room to reveal its question." << endl << endl;

	cout << "Choose the correct answer to the question, and receive an "
	<< "item that will help you escape." << endl 
	<< "Choose the wrong answer, and lose health points." << endl << endl;

	cout << "You need exactly two items to escape through the exit." << endl
	<< "Try to pick up more than two items, you will lose." << endl << endl;

	cout << "After collecting one or two items, make your way to the exit and deposit them." << endl;
	cout << "If you try to walk out of bounds, you will take damage. "
	<< endl << endl;

	cout << "If you run out of health points, you lose." << endl << endl;

	cout << "If you wander around for too long, you will lose." << endl
	<< endl;

	cout << "Time left and health points are displayed after every "
	<< "action." << endl << endl;

	cout << "You see a backpack on the ground in the starting area."
	<< " Pick it up.  You will need it to carry items." << endl
	<< "(select '5' from the menu to pick up the backpack)" << endl;

	cout << "Good luck!" << endl << endl;
}
