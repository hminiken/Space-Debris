/*********************************************************************
** Program name: EnterCode.cpp
** Author: 			 Hillary Miniken
** Date: 				 08/13/2019
** Description:  EnterCode implmentation file - Space for entering a certain 
								 string to dodge debris
*********************************************************************/
#include "EnterCode.hpp"
#include "Player.hpp"


EnterCode::EnterCode()
{
	boardDisplay = ' '; //initially blank until event is revealed

}

EnterCode::~EnterCode()
{

}

/*********************************************************************
Function: 	interactSpace - does unique interaction for space child object
						Generates a random code the user much match in order to 
						dodge debris. If not, then user loses "health" (a turn)
Arguments:	None
Returns:		None
*********************************************************************/
void EnterCode::interactSpace(Player* player)
{
	std::cout << textMargin <<  "Some stray debris is coming right at you! "<< std::endl;
	std::cout << textMargin <<  "Press the following keys in the correct order to dodge (without spaces)!" << std::endl;
	
	createRandomCode();

	std::cout << textMargin;
	for (int i = 0; i < 5; ++i)
	{
		std::cout << codeString[i] << " ";
	}

	std::cout << std::endl;
	std::cout << textMargin <<  "Enter Code: ";
	getline(std::cin, userInput);

	if (codeString == userInput) //user survived
	{
		std::cout << textMargin <<  "Phew, that was close! Be careful out there." << std::endl;
	}
	else //user messed up, loses time
	{
		std::cout << textMargin <<  "Shoot, you hit the wrong controls and got knocked off course!" << std::endl;
		std::cout << textMargin <<  "You lost some time getting back on course." << std::endl;
		player->health--;

	}
}

/*********************************************************************
Function: 	createRandomCode - randomly generate code for user to match
Arguments:	None
Returns:		None
*********************************************************************/
void EnterCode::createRandomCode()
{
	codeString = ""; //clear string
	for (int i = 0; i < 5; ++i)
	{
		codeString += getLetter();
	}
}

/*********************************************************************
Function: 	getLetter - choose random letter for code
Arguments:	None
Returns:		returnLetter as string - the next letter
*********************************************************************/
std::string EnterCode::getLetter()
{
	letterNum = (rand() % 4) + 1; //choose a random letter

	switch(letterNum)
	{
		case 1:
			returnLetter = "a";
			break;
		case 2:
			returnLetter = "w";
			break;
		case 3:
			returnLetter = "d";
			break;
		case 4:
			returnLetter = "s";
			break;
	}

	return returnLetter;
}