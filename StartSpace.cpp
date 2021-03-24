/*********************************************************************
** Program name: StartSpace.cpp
** Author: 			 Hillary Miniken
** Date: 				 08/13/2019
** Description:  StartSpace implementaion file - space user starts on, no 
								 special interaction
*********************************************************************/
#include "StartSpace.hpp"
#include "Player.hpp"


StartSpace::StartSpace()
{
	boardDisplay = 'P'; //initialize to player icon
}

StartSpace::~StartSpace()
{
	
}

/*********************************************************************
Function: 	interactSpace - does unique interaction for space child object
						No special interaction
Arguments:	None
Returns:		None
*********************************************************************/
void StartSpace::interactSpace(Player* player)
{

}