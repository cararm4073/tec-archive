#pragma once
#include <iostream>
#include "monster.h"

class Room{
private:
    Monster monster; //each room has a copy of any monster from catalog

public:
    //constructors
    Room();
    Room(const Monster& monster);

    //methods
    void setMonster(const Monster& monster);
    Monster* getMonster();       //change monster's health during a fight

    //overload printing/output
    friend std::ostream& operator<<(std::ostream& os, const Room& room);
};
