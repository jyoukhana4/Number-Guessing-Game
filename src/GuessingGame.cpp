#include "GuessingGame.h"
#include <cstdlib>

GuessingGame::GuessingGame(int LargestTargetGuessValue) 
    : TargetGuessValue(1+ (rand() % LargestTargetGuessValue)){} //nothing

int GuessingGame::MakeGuess(int Guess) {
    if (Guess < TargetGuessValue) {
        return -1;
    }
    else if (Guess > TargetGuessValue) {
        return 1;
    }
    else {
        return 0;
    }
}