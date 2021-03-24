/*********************************************************************
** Program name: Debris.cpp
** Author: 			 Hillary Miniken
** Date: 				 08/13/2019
** Description:  Debris implementation file - keep track of debris items for 
								 inventory
*********************************************************************/

#include "Debris.hpp"
#include "Player.hpp"

//default constructor
Debris::Debris()
{
	requiredItem = false;
	debrisName = pickName();
}

//overload constructor for required items.
Debris::Debris(bool isRequired, Player* player)
{
	requiredItem = isRequired;
	debrisName = pickRequiredName(player);
}


Debris::~Debris()
{

}

/*********************************************************************
Function: 	pickName - randomly picks a name for debris user collects
Arguments:	None
Returns:		debrisName as std::string - name of debris
*********************************************************************/
std::string Debris::pickName()
{
	//actual items taken from https://en.wikipedia.org/wiki/Space_debris
	debrisNumber = (rand() % 10) + 1;
	switch(debrisNumber)
	{
		case 1:
			debrisName = "Camera";
			break;
		case 2:
			debrisName = "Wrench";
			break;
		case 3:
			debrisName = "Glove";
			break;
		case 4:
			debrisName = "Toothbrus";
			break;
		case 5:
			debrisName = "Pliers";
			break;
		case 6:
			debrisName = "Garbage";
			break;
		case 7:
			debrisName = "Hammer";
			break;
		case 8:
			debrisName = "Blanket";
			break;
		case 9:
			debrisName = "Reactor";
			break;
		case 10:
			debrisName = "Booster";
			break;
	}

	return debrisName;
}


/*********************************************************************
Function: 	pickName - assigns a name for required debris user collects
Arguments:	None
Returns:		debrisName as std::string - name of debris
*********************************************************************/
std::string Debris::pickRequiredName(Player* player)
{
	switch(player->requiredItems)
	{
		case 1:
			debrisName = "Crowbar*";
			break;
		case 2:
			debrisName = "Battery*";
			break;
		case 3:
			debrisName = "Cables*";
			break;
	}

	return debrisName;
}