#include "game.h"
#include <iostream>
using namespace std;

//character implementation, other implementations are on different files

//Constructor for characters (either player or monster) with name, health, and attack values
Character::Character(string n, int h, int atk) : name(n), hp(h), attack(atk) {}

//virtual destructor for derived classes
Character::~Character() {}

//returns  character's name, either player's or monster's
string Character::getName() {
    return name;
}

//character's health, get
int Character::getHp() {
    return hp;
}

//get char's attack value
int Character::getAttack() {
    return attack;
}

//set character's name, either entered one or monster's
void Character::setName(string n) {
    name = n;
}

//sets character's health
void Character::setHp(int h) {
    hp = h;
}

//set character's attack val
void Character::setAttack(int atk) {
    attack = atk;
}

//reduce health
void Character::takeDamage(int damage) {
    hp -= damage; //take health
    if (hp < 0) hp = 0; //make sure health doesn't become negative. defeat condition is checked later
}

//is the player still alive?
bool Character::isAlive() {
    return hp > 0;
}

//display name, health and attack value. initial procedure
void Character::displayStats() {
    cout << name << " - health points: " << hp << ", attack: " << attack << endl;
}