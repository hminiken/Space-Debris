/*********************************************************************
** Program name: Debris.hpp
** Author: 			 Hillary Miniken
** Date: 				 08/13/2019
** Description:  Debris header file - keep track of debris items for 
								 inventory
*********************************************************************/

#ifndef DEBRIS_HPP
#define DEBRIS_HPP 

#include <string>
class Player; //forward declare
class Debris
{
private:
		std::string pickRequiredName(Player* player);
		std::string pickName();
public:

	std::string debrisName;
	bool requiredItem;

	int debrisNumber;

	Debris();
	Debris(bool isRequired, Player* player);
	~Debris();
	
};




#endif