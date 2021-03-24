/*********************************************************************
** Program name: UseDebris.cpp
** Author: 			 Hillary Miniken
** Date: 				 08/13/2019
** Description:  UseDebris implementation file - The final space.  
								 Determines if player has required items.
*********************************************************************/

#include "UseDebris.hpp"
#include "Player.hpp"

UseDebris::UseDebris()
{
	boardDisplay = ' '; //initially is blank, until event is revealed
}

UseDebris::~UseDebris()
{
	
}

/*********************************************************************
Function: 	interactSpace - does unique interaction for space child object,
						Determines if user has enough of required items
Arguments:	player as Player*
Returns:		None
*********************************************************************/
void UseDebris::interactSpace(Player* player)
{

	if (player->requiredItems < 2)
	{
		std::cout << textMargin <<  "Not enough items, go back and find the ones I marked on the map." << std::endl;
		gameWon = false;
	}
	else
	{
		std::cout << std::endl;

		std::cout << textMargin <<  "You made it to the rendevous. Good job," << player->name << "." << std::endl;
		displaySatellite();
		std::cout << std::endl;

		std::cout << textMargin <<  "Now, one of the items you got was a crow bar, use that to pry open the hatch." << std::endl;
		std::cout << textMargin <<  "...." << std::endl;
		std::cout << textMargin <<  "Nicely done! You also have an old battery. Hot wire it to the station, power up" << std::endl;
		std::cout << textMargin <<  "the computer, and enter the command to come to a stop! Easy as 123, right?" << std::endl;
		std::cout << textMargin <<  "Easy as?:  ";
		getline(std::cin, continueKey);

		if (continueKey == "123")
		{
			std::cout << std::endl;

			std::cout << textMargin <<  "...." << std::endl;
			std::cout << std::endl;

			std::cout << textMargin <<  "See that wasn't so bad!" << std::endl;
			std::cout << std::endl;

			std::cout << textMargin <<  "Excellent job, and on your first day! We all owe you a debt of gratitude, Private." << std::endl;
			std::cout << textMargin <<  "Go on and come back to base, that's enough excitement for today." << std::endl;
			std::cout << std::endl;

			std::cout << textMargin << "Press any key to continue ";
			getline(std::cin, continueKey);
			gameWon = true;
		}
		else
		{
			gameWon = true;
			std::cout << "Oh come on, you know how to do this. No? Fine, I'll walk you through it." << std::endl;
			player->score -= 10; //lose 10 points for needing to be walked through.
		}

	}
}

/*********************************************************************
Function: 	isGameOver - determines if game is won
Arguments:	player as Player*
Returns:		None
*********************************************************************/
bool UseDebris::isGameOver()
{
	return gameWon;
}