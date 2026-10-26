#pragma once
#include <string>
#include <iostream>
#include "monster.h"
#include "DLinkedList.h"

class Player{
private:
    std::string name;
    std::string race;
    int hp;
    int mp;
    DLinkedList<Monster*> defeatedMonsters;     //pointer of defeated monsters from rooms

public:
    //constructors
    Player();
    Player(const std::string& name, const std::string& race);

    //getters
    std::string getName() const;
    std::string getRace() const;
    int getHP() const;
    int getMP() const;

    //setters
    void setName(const std::string& name);
    void setRace(const std::string& race);
    void setHP(int hp);
    void setMP(int mp);

    //add defeated monsters alhpabetically
    bool addDefeatedMonster(Monster* monster);

    //overload output
    friend std::ostream& operator<<(std::ostream& os, const Player& player);


};