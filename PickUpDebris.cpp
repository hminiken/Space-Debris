/*********************************************************************
** Program name: PickUpDebris.cpp
** Author: 			 Hillary Miniken
** Date: 				 08/13/2019
** Description:  PickUpDebris implementation file - allows user to
								  add item to inventory
*********************************************************************/

#include "PickUpDebris.hpp"
#include "Player.hpp"

PickUpDebris::PickUpDebris()
{
	boardDisplay = 'D';
}

PickUpDebris::~PickUpDebris()
{

}

/*********************************************************************
Function: 	interactSpace - does unique interaction for space child object,
						checks inventory space, adds items to inventory
Arguments:	None
Returns:		None
*********************************************************************/
void PickUpDebris::interactSpace(Player* player)
{

	if (player->playerSpace->boardDisplay == ' ') //already interacted, ignore
	{
		//do nothing	
	}
	else
	{
		int len = player->inventory.size();
		if (player->playerSpace->boardDisplay == 'R') //required items
		{

			if (len == player->INV_MAX) //check inventory has room
			{
				std::cout << textMargin << "You don't have enough space to pick up the item we need! Throw something" << std::endl;
				std::cout << textMargin << "out to make room. You're wasting valuable time, Private!" << std::endl;

				player->health--; //penalize player for not managing inventory

				for (int i = 0; i < player->INV_MAX; ++i)
				{
					if (player->inventory[i]->requiredItem == false) //find a required item and delete to make room
					{
						player->inventory.erase(player->inventory.begin() + i);
						i = player->INV_MAX; //set i to INV_MAX to stop loop
					}
				}
				std::cout << std::endl;
			}

			player->requiredItems++;			
			std::cout << textMargin << "Great, that's one of the pieces we need! Keep going, we can do this!" << std::endl;
			player->inventory.push_back(new Debris(true, player));	
		}
		else
		{
			if (len == player->INV_MAX)
			{
				std::cout << textMargin << "There's some debris here, but you don't have the capacity for that item, anyway." << std::endl;
				std::cout << textMargin << "We'll get it next time." << std::endl;
			}
			else
			{
				std::cout << textMargin << "You've come across some debris - would you like to pick it up?" << std::endl;
				if (player->inEvent == true)
				{
					std::cout << textMargin << "Note: It will cost you one minute to pick up the debris, but your final score will increase." << std::endl;			
				}

				prompt = textMargin + "Pick up the debris (Y/N)? ";
				acceptableResponses.push_back('y');
				acceptableResponses.push_back('n');
				acceptableResponses.push_back('Y');
				acceptableResponses.push_back('N');

				userInput = inputCharValidation(prompt, acceptableResponses);

				userInput = std::tolower(userInput);

				if (userInput == 'y')
				{
					player->inventory.push_back(new Debris);
					player->health--;
				}
				else
				{
					std::cout << textMargin << "Rodger that, we'll get it next time." << std::endl;
				}
			}
		}
	}
}