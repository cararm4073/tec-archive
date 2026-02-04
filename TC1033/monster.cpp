#include "game.h"
#include <iostream>
using namespace std;

//monster class implementation

//constructor for monster with health and attack values
Monster::Monster(int atk, int h) : Character("Monster", h, atk) {}

//monster's stats
void Monster::displayStats() {
    cout << "Monster - health: " << hp << ", attack: " << attack << endl;
}