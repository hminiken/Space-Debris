/*********************************************************************
** Program name: Board.cpp
** Author: 			 Hillary Miniken
** Date: 				 08/13/2019
** Description:  Board implementation file - updates and displays HUD
*********************************************************************/


#include "Board.hpp"

Board::Board()
{
	healthType = "OXYGEN";

	//initialize inventory display to blank
	for (int i = 0; i < INV_LIMIT; i++)
		{
			inventoryDisplay.push_back( "         ");
		}	
}

Board::~Board()
{}


/*********************************************************************
Function: 	printBoard - print out HUD to console
Arguments:	None
Returns:		None
*********************************************************************/
void Board::printBoard(Player player)
{

	//update all the variables
	displayJetpackUses(player);
	displayFlightMap(player);
	displayHealth(player);
	displayInventoryList(player);

	remHealth =  (player.health/15.0) * 100;

	if (player.inEvent == true)
	{
		healthType = "MINUTES";
	}

 
std::cout << "       _____________________________________________________________________________________________________ " << std::endl;
std::cout << "      |   \\  LOAD :                                                                                     /   | " << std::endl;
std::cout << "      |    \\     "<< std::setw(9) << inventoryDisplay[0] << " | "<< std::setw(9) << inventoryDisplay[1] << " | "<< std::setw(9) << inventoryDisplay[2];
std::cout << " | "<< std::setw(9) << inventoryDisplay[3] << " | "<< std::setw(9) << inventoryDisplay[4] << " | "<< std::setw(9) << inventoryDisplay[5] << " | " << std::setw(9) << inventoryDisplay[6] << "     /    | " << std::endl;
std::cout << "      |     \\_________________________________________________________________________________________/     | " << std::endl;
std::cout << "      |                                                                                                     | " << std::endl;
std::cout << "      |                                                                                              _______| " << std::endl;
std::cout << "      |                                ################|-------|-------|-------|                    |JETPACK| " << std::endl;
std::cout << "      |                                ################|       |       |       |                    |  USES | " << std::endl;
std::cout << "      |                                ################|   "<< s1a << "   |   "<< s1b << "   |   "<< s1c << "   |                    |  ("<<player.jetpackUses<<")  | " << std::endl;
std::cout << "      |                                ################|       |       |       |                    |       | " << std::endl;
std::cout << "      |                                |-------|-------|-------|-------|-------|                    |   "<< j1 << "   | " << std::endl;
std::cout << "      |                                |       |       |       |#######|       |                    |   "<< j2 << "   | " << std::endl;
std::cout << "      |                                |   "<< s2a << "   |   "<< s2b << "   |   "<< s2c << "   |#######|   "<< s2d << "   |                    |   "<< j3 << "   | " << std::endl;
std::cout << "      |                                |       |       |       |#######|       |                    |   "<< j4 << "   | " << std::endl;
std::cout << "      |                                |-------|-------|-------|#######|-------|                    |   "<< j5 << "   | " << std::endl;
std::cout << "      |                                |       |#######|       |#######|       |                    |  (j)  | " << std::endl;
std::cout << "      |                                |   "<< s3a << "   |#######|   "<< s3b << "   |#######|   "<< s3c << "   |                    |______ | " << std::endl;
std::cout << "      |                                |       |#######|       |#######|       |                            | " << std::endl;
std::cout << "      |                                |-------|-------|-------|-------|-------|                            | " << std::endl;
std::cout << "      |                                |       |       |       |       |       |                            | " << std::endl;
std::cout << "      |                                |   "<< s4a << "   |  "<< s4b << "    |   "<< s4c << "   |   "<< s4d << "   |   "<< s4e << "   |                            | " << std::endl;
std::cout << "      |                                |       |       |       |       |       |                            | " << std::endl;
std::cout << "      |                                |-------|-------|-------|-------|-------|                            | " << std::endl;
std::cout << "      |                                ################|       |################                            | " << std::endl;
std::cout << "      |----------------                ################|   "<< s5 << "   |################             ---------------| " << std::endl;
std::cout << "      |     " << std::setw(7) << healthType << "    |               ################|       |################            |    FLIGHT     | " << std::endl;
std::cout << "      |                |               ################|-------|################            |    CONTROLS   | " << std::endl;
std::cout << "      |   " << healthStringTop << "   |                                                                    |       w       | " << std::endl;
std::cout << "      |   " << healthStringBot << "   |                                                                    |       ↑       | " << std::endl;
std::cout << "      |                |  ________________________________________________________________  |   a ← ○ → d   | " << std::endl;
std::cout << "      |     ("<< std::setw(3) << remHealth << "% )    | |                          	FLIGHT MAP                        | |       ↓       | " << std::endl;
std::cout << "      |                | | P - You | D - Debris " << flightMap << " | |       s       | " << std::endl;
std::cout << "      ------------------------------------------------------------------------------------------------------- " << std::endl;


}

/*********************************************************************
Function: 	displayJetpackUses - updates jetpack uses on right side 
            of HUD
Arguments:	None
Returns:		None
*********************************************************************/
void Board::displayJetpackUses(Player player)
{
	if (player.jetpackUses == 0)
	{
		j1 = j2 = j3 = j4 = j5 = ' ';
	}
	else if (player.jetpackUses == 1)
	{
		j1 = 'O';
		j2 = j3 = j4 = j5 = ' ';
	}
	else if (player.jetpackUses == 2)
	{
		j1 = j2 = 'O';
		j3 = j4 = j5 = ' ';
	}
	else if (player.jetpackUses == 3)
	{
		j1 = j2 = j3 = 'O';
		 j4 = j5 = ' ';
	}
	else if (player.jetpackUses == 4)
	{
		j1 = j2 = j3 = j4 =  'O';
		j5 = ' ';
	}
	else if (player.jetpackUses == 5)
	{
		j1 = j2 = j3 = j4 = j5 = 'O';
	}
}

/*********************************************************************
Function: 	displayFlightMap - update map key at bottom of HUD
Arguments:	None
Returns:		None
*********************************************************************/
void Board::displayFlightMap(Player player)
{
	if (player.inEvent == true)
	{
		flightMap = "| R - Req'd  | J - Fuel | ! - Rendevous  " ;
	}
	else
	{
		flightMap = "                                         ";
	}
}

/*********************************************************************
Function: 	displayHealth - updates health squares on left side of HUD
Arguments:	None
Returns:		None
*********************************************************************/
void Board::displayHealth(Player player)
{
  
  healthStringTop="";
  healthStringBot="";


	if (player.health <= 10)
	{
		healthStringTop = "     ▫▫▫▫▫";
		for (int i = 0; i < 10 - player.health; i++)
		{
			healthStringBot += "▫";
		}
		for (int i = 0; i < player.health; i++)
		{
			healthStringBot += "□";
		}
	}
	else
	{
	    healthStringBot = "□□□□□□□□□□";
	    healthStringTop = "     ";
	   for (int i = 0; i < 5 - (player.health - 10); i++)
		{
			healthStringTop += "▫";
		}
		for (int i = 0; i < player.health - 10; i++)
		{
			healthStringTop += "□";
		}	
	}

}

/*********************************************************************
Function: 	displayInventoryList - updateinventory vector with names
Arguments:	None
Returns:		None
*********************************************************************/
void Board::displayInventoryList(Player player)
{
	int len = player.inventory.size();
	for (int i = 0; i < len; i++)
	{
		inventoryDisplay[i] = player.inventory[i]->debrisName;
	}	
}









 
// std::cout << "       _____________________________________________________________________________________________________ " << std::endl;
// std::cout << "      |   \\  LOAD :                                                                                     /   | " << std::endl;
// std::cout << "      |    \\         |       |       |       |       |       |       |       |       |       |         /    | " << std::endl;
// std::cout << "      |     \\_________________________________________________________________________________________/     | " << std::endl;
// std::cout << "      |                                                                                                     | " << std::endl;
// std::cout << "      |                                                                                              _______| " << std::endl;
// std::cout << "      |                                          ################|-------|-------|-------|          |JETPACK| " << std::endl;
// std::cout << "      |   ------- MISSION CONTROL -------        ################|       |       |       |          |  USES | " << std::endl;
// std::cout << "      |  |                               |       ################|   P   |   x   |   x   |          |  (5)  | " << std::endl;
// std::cout << "      |  |                               |       ################|       |       |       |          |       | " << std::endl;
// std::cout << "      |  |                               |       |-------|-------|-------|-------|-------|          |   O   | " << std::endl;
// std::cout << "      |  |                               |       |       |       |       |#######|       |          |   O   | " << std::endl;
// std::cout << "      |  |                               |       |   x   |   x   |   x   |#######|   x   |          |   O   | " << std::endl;
// std::cout << "      |  |                               |       |       |       |       |#######|       |          |   O   | " << std::endl;
// std::cout << "      |  |                               |       |-------|-------|-------|#######|-------|          |   O   | " << std::endl;
// std::cout << "      |  |                               |       |       |#######|       |#######|       |          |______ | " << std::endl;
// std::cout << "      |  |                               |       |   x   |#######|   x   |#######|   x   |                  | " << std::endl;
// std::cout << "      |  |                               |       |       |#######|       |#######|       |                  | " << std::endl;
// std::cout << "      |  |                               |       |-------|-------|-------|-------|-------|                  | " << std::endl;
// std::cout << "      |  |                               |       |       |       |       |       |       |                  | " << std::endl;
// std::cout << "      |  |                               |       |   x   |  x    |   x   |   x   |   x   |                  | " << std::endl;
// std::cout << "      |  |_______________________________|       |       |       |       |       |       |                  | " << std::endl;
// std::cout << "      |                                          |-------|-------|-------|-------|-------|                  | " << std::endl;
// std::cout << "      |                                          ################|       |################                  | " << std::endl;
// std::cout << "      |----------------                          ################|   x   |################   ---------------| " << std::endl;
// std::cout << "      |     OXYGEN     |                         ################|       |################  |    FLIGHT     | " << std::endl;
// std::cout << "      |                |                         ################|-------|################  |    CONTROLS   | " << std::endl;
// std::cout << "      |   □□□□□□□□□□   |                                                                    |       w       | " << std::endl;
// std::cout << "      |   □□□□□□□□□□   |                                                                    |       ↑       | " << std::endl;
// std::cout << "      |                |  ________________________________________________________________  |   a ← ○ → d   | " << std::endl;
// std::cout << "      |     (98%)      | |                   	FLIGHT MAP                                  | |       ↓       | " << std::endl;
// std::cout << "      |                | | P - You | D - Debris | R - Req'd Item | J - Fuel | × - Rendevous  | |       s       | " << std::endl;
// std::cout << "      ------------------------------------------------------------------------------------------------------- " << std::endl;






















	// std::cout << " ################|-------|-------|-------| " std::endl;
	// std::cout << " ################|       |       |       | " std::endl;
	// std::cout << " ################|   x   |   x   |   x   | " std::endl;
	// std::cout << " ################|       |       |       | " std::endl;
	// std::cout << " |-------|-------|-------|-------|-------| " std::endl;
	// std::cout << " |       |       |       |#######|       | " std::endl;
	// std::cout << " |   x   |   x   |   x   |#######|   x   | " std::endl;
	// std::cout << " |       |       |       |#######|       | " std::endl;
	// std::cout << " |-------|-------|-------|#######|-------| " std::endl;
	// std::cout << " |       |#######|       |#######|       | " std::endl;
	// std::cout << " |   x   |#######|   x   |#######|   x   | " std::endl;
	// std::cout << " |       |#######|       |#######|       | " std::endl;
	// std::cout << " |-------|-------|-------|-------|-------| " std::endl;
	// std::cout << " |       |       |       |       |       | " std::endl;
	// std::cout << " |   x   |  x    |   x   |   x   |   x   | " std::endl;
	// std::cout << " |       |       |       |       |       | " std::endl;
	// std::cout << " |-------|-------|-------|-------|-------| " std::endl;
	// std::cout << " ################|       |################ " std::endl;
	// std::cout << " ################|   x   |################ " std::endl;
	// std::cout << " ################|       |################ " std::endl;
	// std::cout << " ################|-------|################ " std::endl;
