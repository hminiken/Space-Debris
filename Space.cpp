/*********************************************************************
** Program name: Space.cpp
** Author: 			 Hillary Miniken
** Date: 				 08/13/2019
** Description:  Space header file - Space abstract class with interactSpace
*********************************************************************/

#include "Space.hpp"
#include "Player.hpp"

Space::Space()
{
}

Space::~Space()
{

}

/*********************************************************************
Function: 	linkSpaces - sets all the pointers to the top, right, 
						bottom, and left spaces
Arguments:	None
Returns:		None
*********************************************************************/
void Space::linkSpaces(Space* t, Space* l, Space* b, Space* r)
{
	top = t;
	right = r;
	bottom = b;
	left = l;
}