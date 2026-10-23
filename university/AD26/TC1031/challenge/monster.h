#pragma once
#include <string>
#include <iostream>

class Monster{
private:
	std::string name;
	double cr;
	std::string type;
	std::string size;
	int ac;
	int hp;
	std::string align;
	
public:
	//constructors
	Monster();
	Monster(const std::string& name, double cr, const std::string& type, const std::string& size, int ac, int hp, const std::string& align);
	
	//setters
	void setHP(int newHp);
	
	//getters
	std::string getName() const;
	double getCr() const;
	std::string getType() const;
	std::string getSize() const;
	int getAc() const;
	int getHp() const;
	std::string getAlign() const;
	
	//operator overload
	bool operator< (const Monster& other) const;
	bool operator<= (const Monster& other) const;
	bool operator> (const Monster& other) const;
	bool operator>= (const Monster& other) const;
	bool operator== (const Monster& other) const;
	bool operator!= (const Monster& other) const;
	
	//operator overload for ostream
	friend std::ostream& operator<< (std::ostream& os, const Monster &monster);
};
