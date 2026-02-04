#include "game.h"
#include <iostream>
using namespace std;

//combat function implementation for the game from header game.h

//execute combat between player (human player) and monster
void combat(Player* player, Monster* monster) {
    cout << "\n    Combat Start " << endl;
    
    //combat loop: continues for a room the combat until either the human-player or monster dies
    while (player->isAlive() && monster->isAlive()) {
        
        //player's turn
        int playerDamage = player->getAttack(); //get attack value
        monster->takeDamage(playerDamage); //make/take damage to/from monster
        cout << player->getName() << " attacks for " << playerDamage << " damage. Remaining monster's health: " << monster->getHp() << endl;
        
        //check if monster died after player's attack
        if (!monster->isAlive()) {
            cout << "Monster defeated!" << endl;
            return; //exits this function rather than the whole code
        }
        
        //monster's turn 
        int monsterDamage = monster->getAttack(); //get attack value
        player->takeDamage(monsterDamage); //make/take damage to/from player
        cout << "Monster counter-attacks for " << monsterDamage << " damage. " << player->getName() << " Reamining player's health: " << player->getHp() << endl;
            
        // Check if player died from monster's attack
        if (!player->isAlive()) {
            cout << player->getName() << " has been defeated!" << endl;
            return;  //end combat/function loop
        }
    } //end of while loop
    
    cout << "End of the combat.\n" << endl;

} //end of combat function