/*********************************************************************
** Program name: Player.hpp
** Author: 			 Hillary Miniken
** Date: 				 08/13/2019
** Description:  Player header file - keeps track of player health, 
								 jetpack, inventory, and score 
*********************************************************************/

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Space.hpp"
#include "Debris.hpp"

class Player
{
public:

	int health = 15,
			jetpackUses = 3,
			requiredItems = 0,
			itemNum = 0,
			score = 0;

	int INV_MAX = 7;

	Space* playerSpace;

	std::vector<Debris*> inventory;

	std::string healthString,
							healthType,
							name;

	bool inEvent = false;

	Player();
	~Player();
	
};

#endif