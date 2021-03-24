/*********************************************************************
** Program name: Space.cpp
** Author: 			 Hillary Miniken
** Date: 				 08/13/2019
** Description:  Space header file - Space abstract class with interactSpace
*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP 

#include <vector>
#include <string>
#include <iostream>
#include <cctype>
#include <vector>

#include "Debris.hpp"
#include "inputValidation.hpp"
// class Player;

class Space
{

protected:
	std::string name,
						  prompt,
						  codeString,
							textMargin = "        ";


std::vector<std::string> outputStrings;

void display();

public:

	Space *top, 
				*left, 
				*right, 
				*bottom; //links to rooms'

	char boardDisplay;

	virtual void interactSpace(Player *player) = 0;

	void linkSpaces(Space* t, Space* l, Space* b, Space* r);

	Space();
	~Space();
	
};


#endif