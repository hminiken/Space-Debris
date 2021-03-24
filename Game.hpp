/*********************************************************************
** Program name: Menu.hpp
** Author: 			 Hillary Miniken
** Date: 				 08/13/2019
** Description:  Menu header file - displays menu to user and gets 
								 user input to call the different tasks. 
*********************************************************************/
#include "Space.hpp"
#include "PickUpDebris.hpp"
#include "UseDebris.hpp"
#include "JetpackFuel.hpp"
#include "EnterCode.hpp"
#include "StartSpace.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "Leaderboard.hpp"

#include "Display.hpp"

#include "inputValidation.hpp"

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#ifndef GAME_HPP
#define GAME_HPP

class Game
{

private:

	double min,
				 max;

	int userChoice = 1,
			turnNum = 1; //initialize to 1 to begin;

	std::vector<char> acceptableResponses;
	std::vector<Leaderboard> leaderboard;

	char playerMove;

	bool moveIsValid,
			 gameOver = false,
			 gameWon = false;

	std::string prompt,
							name,
							textMargin = "        ",
							continueKey,
							outputString;

	std::ifstream inputFile;

	Board gameBoard;
	Player player;

	StartSpace space1a;

	PickUpDebris space1b,
							 space2c,
							 space3c,
							 space4a,
							 space4b,
							 space4d,
							 space1c, //required item
							 space3a, //required item
							 space3b; //required item

	JetpackFuel space2b,
							space4e;

	EnterCode space2a,
						space2d,
						space4c;

	UseDebris space5;	

	//initialize leaderboard objects
	Leaderboard leader1, leader2, leader3, leader4, leader5;						 

	void setAllLinks();
	void setGameMap();
	void displayHUD();
	void movePlayer();
	void makeMove(Space* moveDirection);
	void displayEventMessage();
	void updateBoard();
	void finalMessage();
	void startUpGame();
	void gameInstruction();
	void getLeaderboard();
	void addToLeaderboard();
	void calculateScore();
	void moveOrJetpack();
	static bool sortBoard(const Leaderboard &a, const Leaderboard &b);

	// void displayMissionControl();

	bool checkValidMove(Space* move);
	bool testGameWon();

public:
	void runGame(bool skipIntro);
	void showLeaderboard();


	Game();
	~Game();
	
};

#endif