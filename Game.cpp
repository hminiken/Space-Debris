/*********************************************************************
** Program name: Menu.cpp
** Author: 			 Hillary Miniken
** Date: 				 08/13/2019
** Description:  Menu header file - displays menu to user and gets 
								 user input to call the different tasks. 
*********************************************************************/

#include "Game.hpp"


//Default constructor and destructor. 
Game::Game()
{

	leaderboard.push_back(leader1);
	leaderboard.push_back(leader2);
	leaderboard.push_back(leader3);
	leaderboard.push_back(leader4);
	leaderboard.push_back(leader5);
}

Game::~Game()
{
	//free up memory
	int len = player.inventory.size();
	for( int i = 0 ; i < len ; i++) 
	{
		delete player.inventory[i];
	}

}

/*********************************************************************
Function: 	setAllLinks - connects all "tiles" together
Arguments:	None
Returns:		None
*********************************************************************/
void Game::setAllLinks()
{

	//space##.linkSpaces(top    , left   , bottom , right)
	space1a.linkSpaces(nullptr, nullptr, &space2c, &space1b);
	space1b.linkSpaces(nullptr, &space1a, nullptr, &space1c);
	space1c.linkSpaces(nullptr, &space1b, &space2d, nullptr);
	space2a.linkSpaces(nullptr, nullptr, &space3a, &space2b);
	space2b.linkSpaces(nullptr, &space2a, nullptr, &space2c);
	space2c.linkSpaces(&space1a, &space2b, &space3b, nullptr);
	space2d.linkSpaces(&space1c, nullptr, &space3c, nullptr);
	space3a.linkSpaces(&space2a, nullptr, &space4a, nullptr);
	space3b.linkSpaces(&space2c, nullptr, &space4c, nullptr);
	space3c.linkSpaces(&space2d, nullptr, &space4e, nullptr);
	space4a.linkSpaces(&space3a, nullptr, nullptr, &space4b);
	space4b.linkSpaces(nullptr, &space4a, nullptr, &space4c);
	space4c.linkSpaces(&space3b, &space4b, &space5, &space4d);
	space4d.linkSpaces(nullptr, &space4c, nullptr, &space4e);
	space4e.linkSpaces(&space3c, &space4d, nullptr, nullptr);
	space5.linkSpaces(&space4c, nullptr, nullptr, nullptr);
}

/*********************************************************************
Function: 	setGameMap - update Board with correct output display
Arguments:	None
Returns:		None
*********************************************************************/
void Game::setGameMap()
{
	//row 1
	gameBoard.s1a = space1a.boardDisplay;
	gameBoard.s1b = space1b.boardDisplay;
	gameBoard.s1c = space1c.boardDisplay;

	//row 2
	gameBoard.s2a = space2a.boardDisplay;
	gameBoard.s2b = space2b.boardDisplay;
	gameBoard.s2c = space2c.boardDisplay;
	gameBoard.s2d = space2d.boardDisplay;

	//row 3
	gameBoard.s3a = space3a.boardDisplay;
	gameBoard.s3b = space3b.boardDisplay;
	gameBoard.s3c = space3c.boardDisplay;

	//row 4
	gameBoard.s4a = space4a.boardDisplay;
	gameBoard.s4b = space4b.boardDisplay;
	gameBoard.s4c = space4c.boardDisplay;
	gameBoard.s4d = space4d.boardDisplay;
	gameBoard.s4e = space4e.boardDisplay;

	//row 5
	gameBoard.s5 = space5.boardDisplay;
}

/*********************************************************************
Function: 	displayHud - print out HUD in Board class
Arguments:	None
Returns:		None
*********************************************************************/
void Game::displayHUD()
{
	gameBoard.printBoard(player);

}

/*********************************************************************
Function: 	runGame - the main function the game is ran from, it
						controls taking the turn and determining game over/win
Arguments:	None
Returns:		None
*********************************************************************/
void Game::runGame(bool skipIntro)
{
	setAllLinks();
	setGameMap();

	player.playerSpace = &space1a; //iniitialize player location

	if (skipIntro == false) //only show if not skipping intro
	{
		startUpGame();
		gameInstruction();
	}
	else
	{
		player.name = "\"24601\""; //default player name for skip intro
	}

		displayHUD();

	
	while (gameOver == false)
	{

		if (turnNum == 2) //space station appears
		{
			player.inEvent = true;
			displayEventMessage();
			updateBoard();
			setGameMap();
			displayHUD(); //update HUD
		}

		moveOrJetpack();

		gameWon = testGameWon();

		if (gameWon == true) //you won, game over
		{
			gameOver = true;
		}
		if (gameWon == false && player.health == 0) //you lost, game over
		{
			displayLoseGame();
			gameOver = true;
		}
		turnNum++;
	}

	finalMessage();

}

void Game::moveOrJetpack()
{

	std::cout << std::endl;
	prompt = textMargin + " Enter direction to move: ";
	acceptableResponses.push_back('w');
	acceptableResponses.push_back('a');
	acceptableResponses.push_back('s');
	acceptableResponses.push_back('d');
	acceptableResponses.push_back('j');

	playerMove = inputCharValidation(prompt, acceptableResponses);

	if (playerMove == 'j') //get two movements for price of one
	{
		player.jetpackUses--;
		playerMove = inputCharValidation(prompt, acceptableResponses);
		displayMissionControl();

		movePlayer();
		setGameMap();		
		displayHUD();

		playerMove = inputCharValidation(prompt, acceptableResponses);
		displayMissionControl();

		movePlayer();
		player.health--; //decrement time

		setGameMap();
		displayHUD();
	}
	else
	{
		displayMissionControl();
		movePlayer();
		player.health--; //decrement time
		setGameMap();
		displayHUD();
	}

}

/*********************************************************************
Function: 	movePlayer - gets user input on direction to move, updates 
						turn counter (health) and displays HUD.
Arguments:	None
Returns:		None
*********************************************************************/
void Game::movePlayer()
{

	switch(playerMove)
	{
		case 'w': 
			makeMove(player.playerSpace->top);
			break; 
		case 'd':
			makeMove(player.playerSpace->right);
			break;
		case 's':
			makeMove(player.playerSpace->bottom);
			break;
		case 'a':
			makeMove(player.playerSpace->left);
			break;
		}
}


/*********************************************************************
Function: 	testGameWon - check space5 (final space) for game won
Arguments:	None
Returns:		bool - true if game won, otherwise false
*********************************************************************/
bool Game::testGameWon()
{
	//check last space for status of game
	return space5.isGameOver();

}

/*********************************************************************
Function: 	checkValidMove - verifies move is valid
Arguments:	None
Returns:		moveIsValid as bool - returns if move was valid or not
*********************************************************************/
bool Game::checkValidMove(Space* move)
{
	if (move == nullptr)
	{
		moveIsValid = false;
	}
	else
	{
		moveIsValid = true;
	}

	return moveIsValid;
}

/*********************************************************************
Function: 	makeMove - moves player based on result of checkValidMove
Arguments:	None
Returns:		None
*********************************************************************/
void Game::makeMove(Space* playerMoveDirection)
{
	if(checkValidMove(playerMoveDirection))
	{
		player.playerSpace->boardDisplay = ' '; //update current space to blank

		player.playerSpace = playerMoveDirection;
		player.playerSpace->interactSpace(&player);

		player.playerSpace->boardDisplay = 'P';
	}
	else
	{
		std::cout << textMargin << "Don't go that way, it's too dangerous! Your mistake cost you time." <<std::endl;
	}
}

/*********************************************************************
Function: 	updateBoard - after event, update map with new icons
Arguments:	None
Returns:		None
*********************************************************************/
void Game::updateBoard()
{
	//show required items
	space1c.boardDisplay = 'R';
	space3a.boardDisplay = 'R';
	space3b.boardDisplay = 'R';

	//show jet pack 
	space2b.boardDisplay = 'J';
	space4e.boardDisplay = 'J';

	//show final square
	space5.boardDisplay = '!';

	player.playerSpace->boardDisplay = 'P';


}



/*********************************************************************
Function: 	calculateScore - get users score after end of game.
Arguments:	None
Returns:		None
*********************************************************************/
void Game::calculateScore()
{
	//reset score to 0
	player.score = 0;
	int len = player.inventory.size();

	for (int i = 0; i < len; ++i)
	{
		if (player.inventory[i]->requiredItem == false) //required items don't count towards final score
		{
			player.score += 15;
		}
	}

	std::cout << textMargin << "Score from debris collected: " << player.score << std::endl;

	if (gameWon == true) //50 points if you won the game
	{
		std::cout << textMargin << "Score from saving the station: 50" << std::endl;

		player.score += 50;
	}
	std::cout << std::endl;
	std::cout << textMargin << "Your Total Score : " << player.score << std::endl;
	std::cout << std::endl;

	addToLeaderboard();

}

/*********************************************************************
Function: 	getLeaderBoard - update leaderboard vector with data from 
						text file
Arguments:	None
Returns:		None
*********************************************************************/
void Game::getLeaderboard()
{


	std::string fileName = "LeaderBoard.txt";

	inputFile.open(fileName);

	std::string line;
	int i = 0;
	while (std::getline(inputFile, line)) //from https://stackoverflow.com/a/3910610
	{
    std::stringstream   linestream(line);
    std::string         data;
    std::string val1;
    int val2;

    // Read the integers using the operator >>
    linestream >> val1 >> val2;
    leaderboard[i].leaderName = val1;

    leaderboard[i].leaderScore = val2;
    i++;

	}

	inputFile.close();
}

/*********************************************************************
Function: 	showLeaderBoard - display leaderboard info from text file
Arguments:	None
Returns:		None
*********************************************************************/
void Game::showLeaderboard()
{
	getLeaderboard();
	std::cout << textMargin << "====== LEADER BOARD ========" << std::endl;
	std::cout << textMargin << "   NAME                 SCORE  " << std::endl;
	std::cout << textMargin << "   ----------------    --------" << std::endl;

	for (int i = 0; i < 5; ++i)
	{
		std::cout << textMargin << i+1 << ". " << std::setw(20) << std::left << leaderboard[i].leaderName << " " << leaderboard[i].leaderScore << std::endl;
	}

}

/*********************************************************************
Function: 	addToLeaderboard - determine if user made it on to the 
						leader board
Arguments:	None
Returns:		None
*********************************************************************/
void Game::addToLeaderboard()
{
	getLeaderboard();
	std::sort(leaderboard.begin(), leaderboard.end(), sortBoard);
	if (player.score < leaderboard[4].leaderScore) //did not make it onto leaderboard
	{
	}
	else
	{
		//replace lowest score and reshuffle
		leaderboard[4].leaderScore = player.score;
		leaderboard[4].leaderName = player.name;
		std::sort(leaderboard.begin(), leaderboard.end(), sortBoard);
	}

	//updaate leaderboard file
	std::ofstream outputFile("LeaderBoard.txt");
	for (int i = 0; i < 5; ++i)
	{
		outputString = leaderboard[i].leaderName + " "  + std::to_string(leaderboard[i].leaderScore) + "\n";
		outputFile << outputString;
	}

	outputFile.close();

	//get updated file and print
	showLeaderboard();
}

/*********************************************************************
Function: 	sortBoard - sort leader board
Arguments:	None
Returns:		None
*********************************************************************/
bool Game::sortBoard(const Leaderboard &a, const Leaderboard &b)
{
	 return a.leaderScore > b.leaderScore; 

}


/*********************************************************************
Function: 	displayEventMessage - display event (ISS collision) to user
Arguments:	None
Returns:		None
*********************************************************************/
void Game::displayEventMessage()
{
	displayMissionControl();
	std::cout << textMargin << "Nicely done, you're a natural. Only a couple hours of this to go!" << std::endl;
	usleep(100000);
	std::cout << textMargin << "Hold on... " << std::endl;
	usleep(1000000);
	
	std::cout << textMargin << "Private, we're picking something up on radar. We've confirmed it's ISS-1." << std::endl;

	std::cout << std::endl;
	
	std::cout << textMargin << "The ISS-1 was a joint project between five participating space agencies launched in 1998. Communication with the " << std::endl;
	std::cout << textMargin << "station was lost in 2036 when it was thought to be destroyed. How did it get here..." << std::endl;
	std::cout << std::endl;

	std::cout << textMargin << "..." << std::endl;
	std::cout << std::endl;

	std::cout << textMargin << "It doesn't matter. Private, the old satellite is on a direct collision course with the station." << std::endl;
	std::cout << textMargin << "No one else is out in the field right now, so we need you to intercept it and prevent it from hitting us." << std::endl;
	std::cout << std::endl;


	std::cout << textMargin << "You don't really have the tools you need, but I've ID'd some debris that we can use to make do. There's also" << std::endl; 
	std::cout << textMargin << "some stuff out there you can use to add extra juice to your jetpack." << std::endl;
	std::cout << std::endl;
	
	std::cout << textMargin << "I've updated your map with these and the station rendevous point. You have " << player.health << " minutes. Good luck." << std::endl; 

}



/*********************************************************************
Function: 	startupGame - display beginning dialouge to user
Arguments:	None
Returns:		None
*********************************************************************/
void Game::startUpGame()
{
	std::cout << std::endl;
	std::cout << "       ======================================================================================================" << std::endl;
	std::cout << std::endl;
	std::cout << textMargin << "*You step off the shuttle and into the station. The docking bay	interior has a retro look" << std::endl;
	std::cout << textMargin << " to it and is done in colors that remind you of a beautiful sunset.*" << std::endl;
	std::cout << textMargin << "*Your supervisor approaches you*" << std::endl;
	std::cout << std::endl;
	std::cout << textMargin << "Welcome to the station, Private. I hope you had a pleasant trip. There was a slight mixup, and" << std::endl;
	std::cout << textMargin << "HR lost your file. Could you remind me what your name was?" << std::endl;
	std::cout << std::endl;

	std::cout << textMargin << "Please enter your name: ";
	getline(std::cin, player.name);

	std::cout << std::endl;

	std::cout << textMargin << "Excellent, excellent. Private " << player.name << ", let me just pull up your file, and we will" << std::endl;
	std::cout << textMargin << "be on our way." << std::endl;
	std::cout << std::endl;

	std::cout << textMargin << "There it is! Follow me over to the elevator, and we'll head to your station." << std::endl;
	std::cout << textMargin << "Are you ready?" << std::endl;

	std::cout << std::endl;
	std::cout << textMargin << "Press any key to continue ";
	getline(std::cin, continueKey);


	std::cout << std::endl;
	printSpaceStation();

	std::cout << std::endl;

	std::cout << textMargin << "Here we are, level 30. You'll be working in debris collection. It's a very important job, if you're" << std::endl;
	std::cout << textMargin << "up for it." << std::endl;
	std::cout << std::endl;

	std::cout << textMargin << "" << std::endl;
	std::cout << textMargin << "And the best way to learn that is on the job! Let's get you suited up and out there!" << std::endl;
		std::cout << std::endl;


	std::cout << textMargin << "*You are given no opportunity to protest as you are fitted into a suit and put into the airlock*" << std::endl;
	std::cout << std::endl;
	usleep(2000000);
}

/*********************************************************************
Function: 	gameInstruction - display how to play to user
Arguments:	None
Returns:		None
*********************************************************************/
void Game::gameInstruction()
{
	displayMissionControl();

	std::cout << textMargin << "Alright Private " << player.name << ", from now on we’ll be talking over the radio, so if you’ve got any questions," << std::endl;
	std::cout << textMargin << "address me as mission control. " << std::endl;
	std::cout << std::endl;
	
	std::cout << textMargin << "Your job is to go out there and collect space debris. You can only carry so much, so keep an eye on your " << std::endl;
	std::cout << textMargin << "inventory at the top of your HUD." << std::endl;
	std::cout << std::endl;
	
	std::cout << textMargin << "You’ve got plenty of oxygen – if you must, you can track it in the left corner of your HUD." << std::endl;
	std::cout << std::endl;
	
	std::cout << textMargin << "Your suit is equipped with three jetpack uses, which will let you travel twice the normal distance, so " << std::endl;
	std::cout << textMargin << "use them wisely. Press j to use the jetpack." << std::endl;
	std::cout << std::endl;
	
	std::cout << textMargin << "Stay out of the areas I’ve marked on your map. There’s too much small debris there that can damage " << std::endl;
	std::cout << textMargin << "your suit. If you try to move into one of those areas, you risk your oxygen being punctured. " << std::endl;
	std::cout << std::endl;
	
	std::cout << textMargin << "Your suit is pretty easy to control – just press w for forward, s for backwards, a for left, and d for right." << std::endl;
	std::cout << textMargin << "The controls of your suit on in the bottom right corner of your HUD if you forget. " << std::endl;
	std::cout << std::endl;
	
	std::cout << textMargin << "I’ve marked our target pieces of garbage on your map. The key at the bottom of your HUD is there to " << std::endl;
	std::cout << textMargin << "remind you what the symbols mean. " << std::endl;
	std::cout << std::endl;

	displayHUD();
	
	std::cout << textMargin << "Ready to go?" << std::endl;
	std::cout << std::endl;
	
	std::cout << textMargin << "*You are shot out of the airlock before you can respond.*" << std::endl;

}


/*********************************************************************
Function: 	finalMessage - dispaly final message to user based on game 
						result (win or lose)
Arguments:	None
Returns:		None
*********************************************************************/
void Game::finalMessage()
{
	if (gameWon == true) //you won
	{
	std::cout << std::endl;

		std::cout << textMargin << "Nicely done, you saved the day!" << std::endl;
	std::cout << std::endl;

	}
	else
	{
		std::cout << textMargin << "Well, you didn't quite pull it off, but don't feel bad." << std::endl;
		std::cout << textMargin << "It was your first day, and we evacuated the section before the collision." << std::endl;
		std::cout << textMargin << "Unfortunately, the collision created a lot of new space debris, so we'll be" << std::endl;
		std::cout << textMargin << "at this for a long while now. See you tomorrow, Private." << std::endl;
		std::cout << textMargin << "" << std::endl;
	}

	calculateScore();

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << textMargin << "  THANK YOU FOR PLAYING" << std::endl;
	std::cout << std::endl;

}