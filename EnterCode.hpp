/*********************************************************************
** Program name: EnterCode.hpp
** Author: 			 Hillary Miniken
** Date: 				 08/13/2019
** Description:  EnterCode header file - Space for entering a certain 
								 string to dodge debris
*********************************************************************/
#include <iostream>



#ifndef ENTERCODE_HPP
#define ENTERCODE_HPP

#include "Space.hpp"

class EnterCode : public Space
{

private:
	void interactSpace(Player* player);

	std::string userInput,
							codeString,
							returnLetter;

  int letterNum;
  void createRandomCode();
  std::string getLetter();

	
public:
	EnterCode();
	~EnterCode();
	
};

#endif