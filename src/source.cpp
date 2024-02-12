#include <ctime>
#include <stdlib.h>
#include <iostream>
#include "GuessingGame.h"
#include "GuessingGame.cpp"

int main()
{
	// Different target value every time
	srand(static_cast<unsigned int>(time(nullptr)));

	// Get the constraints of the target value
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Number Guessing Game" << std::endl;
	std::cout << "------------------------------------" << std::endl;
	std::cout << "Enter the largest possible number: ";
	int largestPossibleTargetValue;
	std::cin >> largestPossibleTargetValue;

	// Play a game
	GuessingGame game(largestPossibleTargetValue);
	
	// Game state of  0 means a victory
	// Game state of -1 means last guess was too low
	// Game state of +1 means last guess was too high
	int gameState;
	
	do
	{
		// Get guess
		std::cout << std::endl << "Enter your guess [1 - ";
		std::cout << largestPossibleTargetValue << "]: ";
		int guess;
		std::cin >> guess;
		
		// Give guess data to game object
		// Game state has changed
		gameState = game.MakeGuess(guess);

		// But to what...?
		if (gameState == -1)
		{
			std::cout << "Too low... Try again!" << std::endl;
		}
		else if (gameState == +1)
		{
			std::cout << "Too high... Try again!" << std::endl;
		}
	} while (gameState != 0);
	
	// Celebrate a job well done
	std::cout << std::endl;
	std::cout << "You got it!  Phew!" << std::endl;
	std::cout << "See?  Best game of the year!" << std::endl;
	std::cout << std::endl;

	// Clean up and quit
	system("PAUSE");
	return 0;
}