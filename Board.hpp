/*********************************************************************
** Program name: Board.hpp
** Author: 			 Hillary Miniken
** Date: 				 08/13/2019
** Description:  Board header file - updates and displays HUD
*********************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP 
#include <iostream>
#include <iomanip>

#include "Player.hpp"

class Board
{

private: 
		void displayJetpackUses(Player player);
	void displayFlightMap(Player player);
	void displayHealth(Player player);
	void displayInventoryList(Player player);
public:


 char s1a,
			s1b,
			s1c,
			//row 2
			s2a,
			s2b,
			s2c,
			s2d,
			//row 3
			s3a,
			s3b,
			s3c,
			//row 4
			s4a,
			s4b,
			s4c,
			s4d,
			s4e,
			//row 5
			s5;


	std::string healthStringTop,
							healthStringBot,
							healthType,
							flightMap;


	std::vector<std::string> inventoryDisplay;

	int INV_LIMIT = 7;
	int remHealth;
	char j1,
			j2,
			j3,
			j4,
			j5;

	void printBoard(Player player);

	Board();
	~Board();
	
};

#endif