/*********************************************************************
** Program name: PickUpDebris.hpp
** Author: 			 Hillary Miniken
** Date: 				 08/13/2019
** Description:  PickUpDebris header file - allows user to add item to 
								 inventory
*********************************************************************/
#include <iostream>
#include <vector>

#ifndef PICKUPDEBRIS_HPP
#define PICKUPDEBRIS_HPP

#include "Space.hpp"
#include "Debris.hpp"

class PickUpDebris : public Space
{

private:
	void interactSpace(Player* player);

	std::vector<char> acceptableResponses;

	char userInput;
	
public:
	PickUpDebris();
	~PickUpDebris();

	
};

#endif