/*********************************************************************
** Program name: UseDebris.hpp
** Author: 			 Hillary Miniken
** Date: 				 08/13/2019
** Description:  UseDebris header file - The final space. Determines 
								 if player has required items.
*********************************************************************/
#include "Display.hpp"
#include <iostream>

#ifndef USEDEBRIS_HPP
#define USEDEBRIS_HPP

#include "Space.hpp"

class UseDebris : public Space
{

private:
	void interactSpace(Player* player);

	std::string continueKey;

	bool gameWon = false;

	
public:
	bool isGameOver();

	UseDebris();
	~UseDebris();

	
};

#endif