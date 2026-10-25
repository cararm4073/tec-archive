#include <iostream>
#include "monster.h"

//default constructor
Monster::Monster() 
	: name(""), cr(0.0), type(""), size(""), ac(0), hp(0), align("") {}

//parametrized constructor
Monster::Monster(const std::string& name, double cr, const std::string& type, const std::string& size, int ac, int hp, const std::string& align) 
	: name(name), cr(cr), type(type), size(size), ac(ac), hp(hp), align(align) {}

//setter
void Monster::setHP(int newHp){
	hp = newHp;
}

//getters
std::string Monster::getName() const{
	return name;
}

double Monster::getCr() const{
	return cr;
}

std::string Monster::getType() const{
	return type;
}

std::string Monster::getSize() const{
	return size;
}

int Monster::getAc() const{
	return ac;
}

int Monster::getHp() const{
	return hp;
}

std::string Monster::getAlign() const{
	return align;
}

//comparators overload
bool Monster::operator< (const Monster &other) const{
	if((this->name) < (other.name)) return true;
	else return false;
}

bool Monster::operator<= (const Monster &other) const{
	if((this->name) <= (other.name)) return true;
	else return false;
}
bool Monster::operator> (const Monster &other) const{
	if((this->name) > (other.name)) return true;
	else return false;
}

bool Monster::operator>= (const Monster &other) const{
	if((this->name) >= (other.name)) return true;
	else return false;
}

bool Monster::operator== (const Monster &other) const{
	if((this->name) == (other.name)) return true;
	else return false;
}

bool Monster::operator!= (const Monster &other) const{
	if((this->name) != (other.name)) return true;
	else return false;
}

//overload ostream
std::ostream& operator<< (std::ostream& os, const Monster &monster){
	os << monster.name << " [hp: " << monster.hp << ", ac: " << monster.ac << "]";
	return os;
}
