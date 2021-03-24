/*********************************************************************
** Program name: Menu.cpp
** Author: 			 Hillary Miniken
** Date: 				 08/13/2019
** Description:  Menu header file - displays menu to user and gets 
								 user input to call the different tasks. 
*********************************************************************/

#include "Menu.hpp"


//Default constructor and destructor. 
Menu::Menu()
{
}

Menu::~Menu()
{

}


/*********************************************************************
Function: 	displayMenu - gives the options of the program to the user
Arguments:	None
Returns:		None
*********************************************************************/
void Menu::displayMenu()
{
	std::cout << "     What would you like to do?" << std::endl;
	std::cout << "     -------------------------------------------------------" << std::endl;
	std::cout << "      1. Play game" << std::endl;
	std::cout << "      2. Tell me more about this game" << std::endl;
	std::cout << "      3. Play game - skip intro (for testing)" << std::endl;
	std::cout << "      4. Show leaderboard" << std::endl;
	std::cout << "      5. Exit the program" << std::endl;
	std::cout << std::endl;
}

/*********************************************************************
Function: 	runProgram - the main function the program is ran from, 
						gets user input to run one of several possible options
Arguments:	None
Returns:		None
*********************************************************************/
void Menu::runProgram()
{
	printOpening();
	std::cout << std::endl;

	while(userChoice != 5)
	{
		std::cout << std::endl;		
		displayMenu();
		min = 1;
		max = 5;
		prompt = "Select an option: ";
		userChoice = inputIntegerValidation(prompt, min, max);
   	Game game; //create new instance every menu output
		
		switch(userChoice)
		{
			case 1:
				game.runGame(skipIntro);
				break;
			case 2:
				aboutGame();
				break;
			case 3:
				skipIntro = true;
				game.runGame(skipIntro);
				break;
			case 4:
				game.showLeaderboard();
				break;
			case 5:
				std::cout << "Exiting the program, goodbye." << std::endl;
				break;
		}
	}
	
	
}

/*********************************************************************
Function: 	aboutGame - displays game information to user stores in a 
						text file
Arguments:	None
Returns:		None
*********************************************************************/
void Menu::aboutGame()
{
	std::cout << std::endl;

	//Test to make sure file opened properly
	std::ifstream inputFile;

	std::string fileName = "about.txt";

	inputFile.open(fileName);

	std::string line;
	while (std::getline(inputFile, line))
	{
		std::cout << line << std::endl;
	}

	inputFile.close();

	std::cout << std::endl;
	std::cout << std::endl;
}