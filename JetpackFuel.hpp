/*********************************************************************
** Program name: JetpackFuel.hpp
** Author: 			 Hillary Miniken
** Date: 				 08/13/2019
** Description:  JetpackFuel header file - gives user extra jetpack 
								 charges
*********************************************************************/
#include <iostream>

#ifndef JETPACKFUEL_HPP
#define JETPACKFUEL_HPP

#include "Space.hpp"

class JetpackFuel : public Space
{

private:
	void interactSpace(Player* player);


public:
	JetpackFuel();	
	~JetpackFuel();
	
};

#endif