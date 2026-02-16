#include "messages.h"
#include <iostream>
#include <cstdlib>
using namespace std;

//game functions (messages) implementation

//generate a number between min and max (inclusive vals). pseudo-random. used for generating the monster's stats "randomly" for each room of the dungeon
//inputs are defined when calling the function, but mainly are 1-8, 10-40, for the stats of the monster
int generateRandomNumber(int min, int max) {
    return min + (rand() % (max - min + 1));
}

//game title when code is ran
void displayGameHeader() {
    cout << "\n     DUNGEON GAME" << endl;
}

//message for when player wins the whole game
void displayVictory(Player* player) {
    cout << "\n          VICTORY!" << endl;
    cout << player->getName() << " has completed all rooms!" << endl;
    cout << "Final HP: " << player->getHp() << endl;
}

//defeat message
void displayDefeat(string playerName, int roomNumber) {
    cout << "\n          DEFEAT!" << endl;
    cout << playerName << " has died in room " << roomNumber << endl;
}

//room message
void displayRoomEntry(int roomNumber) {
    cout << "   Entering Room #" << roomNumber << endl;
}