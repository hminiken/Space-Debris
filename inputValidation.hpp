/*********************************************************************
** Program name: inputValidaiton.hpp
** Author: Hillary Miniken
** Date: 08/04/2019
** Description: Function header - functions validates user 
								input as an integer or double within a given range.  
*********************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

#ifndef INPUT_VALIDATION_HPP
#define INPUT_VALIDATION_HPP 

double inputDoubleValidation(std::string prompt, double min, double max);
int inputIntegerValidation(std::string prompt,double min,double max);
char inputCharValidation(std::string prompt, std::vector<char> acceptableResponses);

 //to be implemented if need specific string (yes, no, cancel, etc.)
// std::string inputStringValidation(std::string prompt, std::vector<std::string> acceptableResponses);

#endif
