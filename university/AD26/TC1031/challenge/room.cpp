#include "room.h"

//----------------------constructors----------------------
Room::Room(): monster() {}

Room::Room(const Monster& monster): monster(monster){}

//----------------------methods----------------------
Monster* Room::getMonster() {
    return &monster;
}

void Room::setMonster(const Monster& monster) {
    this->monster = monster;
}

//overload printing
std::ostream& operator<<(std::ostream& os, const Room& room) {
    os << "Room with: " << room.monster;
    return os;
}