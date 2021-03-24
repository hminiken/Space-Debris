/*********************************************************************
** Program name: Display.cpp
** Author: 			 Hillary Miniken
** Date: 				 08/13/2019
** Description:  Display implementation file - displays various text and art 
								 to user
*********************************************************************/

#include "Display.hpp"

/*********************************************************************
Function: 	printOpening - print title art and Planetes monologue
Arguments:	None
Returns:		None
*********************************************************************/
void printOpening()
{


std::cout << "          _______..______      ___       ______  _______     _______   _______ .______   .______       __       _______. " << std::endl;
std::cout << "         /       ||   _  \\    /   \\     /      ||   ____|   |       \\ |   ____||   _  \\  |   _  \\     |  |     /       | " << std::endl;
std::cout << "        |   (----`|  |_)  |  /  ^  \\   |  ,----'|  |__      |  .--.  ||  |__   |  |_)  | |  |_)  |    |  |    |   (----` " << std::endl;
std::cout << "         \\   \\    |   ___/  /  /_\\  \\  |  |     |   __|     |  |  |  ||   __|  |   _  <  |      /     |  |     \\   \\     " << std::endl;
std::cout << "     .----)   |   |  |     /  _____  \\ |  `----.|  |____    |  '--'  ||  |____ |  |_)  | |  |\\  \\----.|  | .----)   |    " << std::endl;
std::cout << "     |_______/    | _|    /__/     \\__\\ \\______||_______|   |_______/ |_______||______/  | _| `._____||__| |_______/     " << std::endl;
std::cout << "    =======================================================================================================================" << std::endl; 
std::cout << std::endl;


std::cout << "     Abandoned artificial satellites. Tanks jettisoned from shuttles. Refuse generated during space station construction." << std::endl;
std::cout << std::endl;


std::cout << "     This vast amount of junk floating in space, SPACE DEBRIS, is a very serious threat. This is a story of 2075, a time" << std::endl;
std::cout << "     in which this space garbage has become a problem. - Planetes, 2003" << std::endl;

std::cout << std::endl;
std::cout << "       Welcome to Space Debris, a garbage collecting game - in space!" << std::endl;


}

/*********************************************************************
Function: 	printSpaceStation - outputs space station art from text file
Arguments:	None
Returns:		None
*********************************************************************/
void printSpaceStation()
{


//Test to make sure file opened properly
	std::ifstream inputFile;

	std::string fileName = "spaceStation.txt";

	inputFile.open(fileName);

	std::string line;
	while (std::getline(inputFile, line))
	{
		std::cout << line << std::endl;
		usleep(100000);

    // process pair (a,b)
	}

	inputFile.close();

	std::cout << std::endl;
	std::cout << std::endl;


}

/*********************************************************************
Function: 	displayMissionControl - display mission control header
Arguments:	None
Returns:		None
*********************************************************************/
void displayMissionControl()
{
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "       ======================================================================================================" << std::endl;
	std::cout << "       ===============================            MISSION CONTROL            ================================" << std::endl;
	std::cout << "       ======================================================================================================" << std::endl;

}

/*********************************************************************
Function: 	displaySatellite - output satellite ascii art
Arguments:	None
Returns:		None
*********************************************************************/
void displaySatellite()
{

               
std::cout << "          	          }--O--{                  " << std::endl;
std::cout << "                            [^]                    " << std::endl;
std::cout << "                           /ooo\\                   " << std::endl;
std::cout << "           ______________:/o   o\\:______________   " << std::endl;
std::cout << "          |=|=|=|=|=|=|:A|\":|||:\"|A:|=|=|=|=|=|=|  " << std::endl;
std::cout << "          ^\"\"\"\"\"\"\"\"\"\"\"\"\"\"!::{o}::!\"\"\"\"\"\"\"\"\"\"\"\"\"\"^ " << std::endl;
std::cout << "                          \\     /                  " << std::endl;
std::cout << "                           \\.../                   " << std::endl;
std::cout << "                ____       \"---\"       ____        " << std::endl;
std::cout << "               |\\/\\/|=======|*|=======|\\/\\/|       " << std::endl;
std::cout << "               :----\"       /-\\       \"----:       " << std::endl;
std::cout << "                           /ooo\\                   " << std::endl;
std::cout << "                          #|ooo|#                  " << std::endl;
std::cout << "                           \\___/                   " << std::endl;



}

void displayLoseGame()
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "         No! You missed the rendevous! Oh hell..." << std::endl;
	std::cout << "         *Faintly through the radio, you hear klaxons.*" << std::endl;
	std::cout <<std::endl;
	std::cout <<std::endl;
		usleep(4000000);

// Art by lgbeard

	std::cout << "                              *    *                                                   " << std::endl;
	std::cout << "                  *         '       *       .  *   '     .           * *               " << std::endl;
	std::cout << "                                                                              '     " << std::endl;
	std::cout << "                      *                *'          *          *        '            " << std::endl;
	std::cout << "                  .           *               |               /                          " << std::endl;
	std::cout << "                              '.         |    |      '       |   '     *                 " << std::endl;
	std::cout << "                                \\*        \\   \\             /                         " << std::endl;
	std::cout << "                      '          \\     '* |    |  *        |*                *  *      " << std::endl;
	std::cout << "                           *      `.       \\   |     *     /    *      '               " << std::endl;
	std::cout << "                 .                  \\      |   \\          /               *           " << std::endl;
	std::cout << "                    *'  *     '      \\      \\   '.       |                            " << std::endl;
	std::cout << "                       -._            `                  /         *                    " << std::endl;
	std::cout << "                 ' '      ``._   *                           '          .      '        " << std::endl;
	std::cout << "                  *           *\\*          * .   .      *                              " << std::endl;
	std::cout << "               *  '        *    `-._                       .         _..:='        *    " << std::endl;
	std::cout << "                            .  '      *       *    *   .       _.:--'                   " << std::endl;
	std::cout << "                         *           .     .     *         .-'         *                " << std::endl;
	std::cout << "                  .               '             . '   *           *         .           " << std::endl;
	std::cout << "                 *       ___.-=--..-._     *                '               '             " << std::endl;
	std::cout << "                                                 *       *                                   " << std::endl;
	std::cout << "                               *        _.'  .'       `.        '  *             *          " << std::endl;
	std::cout << "                    *              *_.-'   .'            `.               *                " << std::endl;
	std::cout << "                                  .'                       `._             *  '                " << std::endl;
	std::cout << "                  '       '                        .       .  `.     .                       " << std::endl;
	std::cout << "                      .                      *                  `                            " << std::endl;
	std::cout << "                              *        '             '                          .           " << std::endl;
	std::cout << "                    .                          *        .           *  *                     " << std::endl;
	std::cout << "                            *        .                                    '                 " << std::endl;


	std::cout <<std::endl;
	std::cout <<std::endl;
	std::cout <<std::endl;
		usleep(2000000);

	std::cout << "          * .... You decide to return to base.*" << std::endl;
		usleep(2000000);

	std::cout <<std::endl;

	std::cout <<std::endl;

}