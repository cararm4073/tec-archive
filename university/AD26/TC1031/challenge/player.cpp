#include "player.h"

//----------------------constructors----------------------
Player::Player(): name(""), race("human"), hp(100), mp(100) {}

Player::Player(const std::string& name, const std::string& race)
    : name(name), race(race), hp(100), mp(100) {}

//----------------------getters----------------------
std::string Player::getName() const{
    return name;
}

std::string Player::getRace() const{
    return race;
}

int Player::getHP() const {
    return hp;
}

int Player::getMP() const {
    return mp;
}

//----------------------setters----------------------
void Player::setName(const std::string& name){
    this->name = name;
}

void Player::setRace(const std::string& race){
    this->race = race;
}

void Player::setHP(int hp){
    this->hp = hp;
}

void Player::setMP(int mp){
    //as specified in the instructions
    if(mp>999){
        this->mp = 999;
    } else if (mp<0){
        this->mp = 0;
    } else {
        this->mp = mp;
    }
}

//----------------------defeated monster----------------------

bool Player::addDefeatedMonster(Monster* monster){
    if(!monster) return false;

    //insert defeated monsters alphabetically, storing their address

    //if list is empty, add at front
    if (defeatedMonsters.isEmpty()) {
        return defeatedMonsters.addFront(monster);
    }

    //if its name is lower than the first one, add to the front
    Monster** firstMonster = defeatedMonsters.getValue(0);
    if (firstMonster and *monster < **firstMonster){
        return defeatedMonsters.addFront(monster);
    }

    //compare with last element, deciding whether it goes first or before it in the back
    int listSize = defeatedMonsters.getSize();
    Monster** lastMonster = defeatedMonsters.getValue(listSize-1);
    if(lastMonster and *monster >= **lastMonster){
        return defeatedMonsters.addBack(monster);
    }

    
    return defeatedMonsters.addBack(monster);
}

//----------------------output overload----------------------
std::ostream& operator<<(std::ostream& os, const Player& player) {
    os << player.name << " (" << player.race << ") hp: " << player.hp << " mp: " << player.mp;
    return os;
}