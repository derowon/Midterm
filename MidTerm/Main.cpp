#include "Game.h"

using namespace std;
void clearConsole();

int main() {
	Game game = Game();
	game.splashScreen();
	clearConsole();
	game.requestName();

	return 0;
}
/*
credits //This function is used to display your name and what the program does
menu // This function is used to display the menu with various options
validateUserResponse // This function is used to validate user input from the menu
validateUserAnswer // This function is used to validate user input and ensure that ONLY numeric answers are entered by the user.
checkUserAnswer // given a math problem, this function is used to check if the answer the user entered is correct or incorrect
updateStats // This function is used to keep a running total of game statistics (in RAM)
displayStats // This function is used to display statistics on screen
retireveStats //  This function is used to retrieve player statistics from external txt file when the game starts, assuming the player is a returning player, else create a text file to store the stats.
saveStats //  This function is used to save player statistics on an external txt file.
You may also want to consider the following four functions: generateAddition, generateSubtraction, generateMultiplication and generateDivision // use these to generate a problem of the appropriate type.
*/

//Clear the console!
void clearConsole() {
	system("cls");
}