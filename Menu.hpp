/*********************************************************************
** Program name: Menu.hpp
** Author: 			 Hillary Miniken
** Date: 				 08/13/2019
** Description:  Menu header file - displays menu to user and gets 
								 user input to call the different tasks. 
*********************************************************************/
#include "Game.hpp"
#include "inputValidation.hpp"

#include <iostream>
#include <vector>

#ifndef MENU_HPP
#define MENU_HPP

class Menu
{

private:

	double min,
				 max;

	int userChoice = 1;

	std::string prompt;

	bool skipIntro = false;

	void aboutGame();
	void displayMenu();


public:
	void runProgram();

	Menu();
	~Menu();
	
};

#endif