/*********************************************************************
** Program name: Leaderboard.hpp
** Author: 			 Hillary Miniken
** Date: 				 08/13/2019
** Description:  Leaderboard header file - creates leaderboard objects 
								 to track name and score. 
*********************************************************************/

#ifndef LEADERBOARD_HPP
#define LEADERBOARD_HPP

#include <string>
class Leaderboard
{
public:

	std::string leaderName;
	int leaderScore;
	Leaderboard();
	~Leaderboard();
	
};

#endif