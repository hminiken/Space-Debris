/*********************************************************************
** Program name: inputValidaiton.cpp
** Author: Hillary Miniken
** Date: 08/04/2019
** Description: Function implementations - functions validates user 
								input as an integer or double within a given range.  
*********************************************************************/

#include "inputValidation.hpp"

/*********************************************************************
Function: 	inputIntegerValidation - used to validate user input as an 
					  integer within a given range. Loops until valid input is 
					  received
Arguments:	userChoice as String, min and max of range as double
Returns:		inputInt as integer - the integer after it has been validated
*********************************************************************/
int inputIntegerValidation(std::string prompt, double min, double max)
{
	// adapted from Piazza post @81
	bool validInput = false;
	int inputInt;

	std::string userChoice;

	do
	{
		std::cout << prompt;

		getline(std::cin, userChoice);

		if (userChoice.find(".") != std::string::npos) //found decimal point
		{
	    validInput =  false;
		}
		//adapted from answer at https://stackoverflow.com/a/8889045
		else if (userChoice.find_first_not_of("0123456789-") != std::string::npos) //found a letter
		{
	    validInput =  false;
		}
		else if (userChoice.find("-", 1) != std::string::npos) //found a dash not at the start (i.e negative number)
		{
	    validInput =  false;
		}
		else if (userChoice.find(" ", 0) != std::string::npos) //found a space
		{
	    validInput =  false;
		}
		else if (userChoice.length() == 0) //user entered nothing
		{
	    validInput =  false;
		}
		else
		{
			validInput = true;
		}

		//if a number, then test if in range
		if (validInput == true)
		{
		 inputInt = std::stoi(userChoice);
		 if (inputInt < min || inputInt > max) //not in range
		 {
		 	validInput =  false;
		 }
		 else
		 {
		 	validInput =  true;
		 }
		}

		if (validInput == false)
		{
			std::cout << "That is not a valid input, please try again. " << std::endl;
			// std::cin.clear();
			// std::cin.ignore();

		}
	} while(validInput == false);

	return inputInt;

}


/*********************************************************************
Function: 	inputValinputDoubleValidationidation - used to validate user 
					  input as an double within a given range. Loops until valid 
					  input is received
Arguments:	userChoice as String, min and max of range as double
Returns:		inputDouble as double - the double after it has been 
						validated
*********************************************************************/
double inputDoubleValidation(std::string prompt, double min, double max)
{
	// adapted from Piazza post @81
	bool validInput = false;
	double inputDouble;

	std::string userChoice;

	do
	{
		std::cout << prompt;

		getline(std::cin, userChoice);

		//adapted from answer at https://stackoverflow.com/a/8889045
		if (userChoice.find_first_not_of("0123456789.") != std::string::npos) //found a letter
		{
	    validInput =  false;
		}
		else if (userChoice.find(" ", 0) != std::string::npos) //found a space
		{
	    validInput =  false;
		}
		else if (userChoice.length() == 0) //user entered nothing
		{
	    validInput =  false;
		}
		else
		{
			validInput = true;
		}

		//if a number, then test if in range
		if (validInput == true)
		{
		 inputDouble = std::stod(userChoice);
		 if (inputDouble < min || inputDouble > max) //not in range
		 {
		 	validInput =  false;
		 }
		 else
		 {
		 	validInput =  true;
		 }
		}

		if (validInput == false)
		{
			std::cout << "That is not a valid input, please try again. " << std::endl;
			// std::cin.clear();
			// std::cin.ignore();

		}
	} while(validInput == false);

	return inputDouble;

}



char inputCharValidation(std::string prompt, std::vector<char> acceptableResponses)
{
	// adapted from Piazza post @81
	bool validInput = false;
	char charInput;
	std::string userChoice;

	do
	{
		std::cout << prompt;

		getline(std::cin, userChoice);

		charInput = userChoice[0];


		if(std::find(acceptableResponses.begin(), acceptableResponses.end(), charInput) != acceptableResponses.end())
		{
			validInput = true;
		}
		else
		{
			validInput = false;
		}




		if (validInput == false)
		{
			std::cout << "That is not a valid input, please try again. " << std::endl;
			// std::cin.clear();
			// std::cin.ignore();

		}
	} while(validInput == false);

	return charInput;
}