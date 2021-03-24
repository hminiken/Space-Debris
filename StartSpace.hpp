/*********************************************************************
** Program name: StartSpace.hpp
** Author: 			 Hillary Miniken
** Date: 				 08/13/2019
** Description:  StartSpace header file - space user starts on, no 
								 special interaction
*********************************************************************/
#include <iostream>

#ifndef STARTSPACE_HPP
#define STARTSPACE_HPP

#include "Space.hpp"

class StartSpace : public Space
{

private:
	void interactSpace(Player* player);
	
public:
	StartSpace();
	~StartSpace();
	
};

#endif