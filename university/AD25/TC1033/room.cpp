#include "game.h"
#include "messages.h"
using namespace std; //not a header file
//room class implementation

//constructor for the room with a monster with random stats (attack from 1-8, health 10-40
Room::Room() : cleared(false), monster(generateRandomNumber(1, 8), generateRandomNumber(10, 40)) {}

//destructor, though there is no dynamic memory to clean up
Room::~Room() {}

//pointer to the monster in the room in which we are
Monster* Room::getMonster() {
    return &monster;  //returh the adress of the monster object
}

//has the room been cleared?
bool Room::isCleared() {
    return cleared;
}

//mark the room as cleared
void Room::setClear() {
    cleared = true;
}