#include "game.h"
#include <iostream>
using namespace std;

//player class implementation

//constructor for a player with health 100 and attack value of 10
Player::Player(string n) : Character(n, 100, 10) {}

//displayer stats
void Player::displayStats() {
    cout << "Player " << name << " - heath: " << hp << ", attack: " << attack << endl;
}