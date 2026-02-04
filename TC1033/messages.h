#pragma once //header protector

#include "game.h"
#include <string>

//util functions for the game, their implementation are at game.cpp

//random number for generating monsters
int generateRandomNumber(int min, int max);

//display the start of the game
void displayGameHeader();

//display the message of victory and final stats of the player after combats, if still alive
void displayVictory(Player* player);

//defeate message
void displayDefeat(std::string playerName, int roomNumber);

//room entry msg
void displayRoomEntry(int roomNumber);