#pragma once //header guard

#include <string>
//using namespace std;
//no namespace std for header

//original/base class for characters (player and monster)
class Character {
protected:
    std::string name; //name
    int hp; //current health
    int attack; //damage value

public:
    //constructor for a character with name, health , and attack value
    Character(std::string n, int h, int atk);
    //destructor (virtual) for cleaning in other classes
    virtual ~Character();
    
    //getter methods
    std::string getName(); //returns character's name (either monster n, or player's name)
    int getHp(); //current health
    int getAttack(); //attack val
    
    //setter methods ( modification of character attributes)
    void setName(std::string n); //set character's name
    void setHp(int h); //sets current health, either initial or after a combat
    void setAttack(int atk); //set attack value for player and monster
    
    //general mechanics of game
    void takeDamage(int damage); //reduce player's health based on monster's attack
    bool isAlive(); //check if player is still alive
    virtual void displayStats();  //show player stats
};



//player or human-controlled class
class Player : public Character {
public:
    //constructor with default stats
    Player(std::string n);
    //call displayStats to show player stats
    void displayStats();
};



//monster class for each room
class Monster : public Character {
public:
    //constructor for monsters with ranges of health and attack
    Monster(int atk, int h);
    //call displayStats to show monster  stats
    void displayStats();
};



//room class with one monster
class Room {
private:
    Monster monster; //monster in this room is an object
    bool cleared; //has the room been cleared? true or false

public:
    //constructor for room with a random monster
    Room();
    //destructor of such room
    ~Room();
    
    //getter methods used
    Monster* getMonster(); //pointer to the respective monster of that room
    bool isCleared(); //just check if the room has already been cleared
    
    //setter method, only mark room as cleared
    void setClear();
};



//combat between player and monster
void combat(Player* player, Monster* monster);