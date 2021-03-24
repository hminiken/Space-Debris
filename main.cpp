/*********************************************************************
** Program name: main.cpp
** Author:      Hillary Miniken
** Date:        08/13/2019
** Description: main file for CS162 Final Project. Creates a game object which 
                contains all the functionality of the program. Game 
                object determines if program is exiting.
*********************************************************************/

#include "Menu.hpp"
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()

int main()
{
	srand(time(0));  // Initialize random number generator.	
	
	Menu menu;
	menu.runProgram();

	return 0;


}