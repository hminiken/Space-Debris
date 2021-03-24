/*********************************************************************
** Program name: JetpackFuel.cpp
** Author: 			 Hillary Miniken
** Date: 				 08/13/2019
** Description:  JetpackFuel implementation file - gives user extra jetpack 
								 charges
*********************************************************************/

#include "JetpackFuel.hpp"
#include "Player.hpp"


JetpackFuel::JetpackFuel()
{
	boardDisplay = ' '; //blank until event
}

JetpackFuel::~JetpackFuel()
{
	
}

/*********************************************************************
Function: 	interactSpace - does unique interaction for space child object,
						adds extra jetpack use for player.
Arguments:	None
Returns:		None
*********************************************************************/
void JetpackFuel::interactSpace(Player* player)
{
	if (player->playerSpace->boardDisplay == ' ') //already interacted, ignore
	{
		//do nothing	
	}
	else
	{
		std::cout << textMargin << "You found some extra jetpack fuel!" << std::endl;
		std::cout << player->jetpackUses++ << std::endl;
	}
}

