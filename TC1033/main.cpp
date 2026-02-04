//Code made by:
// ##### ####### ########## ######
// 

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "game.h"
#include "messages.h"

using namespace std;

int main(){
    //random number generator using time (still "pseudo")
    srand(time(NULL));
    
    //game header
    displayGameHeader();
    
    //create an array, size 6, for the room
    Room dungeon[6];
    
    //player's name
    string playerName;
    cout << "\nEnter player name: ";
    cin >> playerName;
    
    //create player object with name "player"
    Player player(playerName);
    cout << "\nPlayer created! Your stats are:" << endl;
    player.displayStats(); //display initial player stats
    
    //loop for each room of the dungeon, once completed, it will exit, and if the code did nut return 0 (quit), will consider that player won
    for (int i = 0; i < 6; i++) {
        //display that you entered to a room
        displayRoomEntry(i + 1);
        
        //get the monster assigned to the entered room 
        Monster* currentMonster = dungeon[i].getMonster();
        currentMonster->displayStats(); //monster stats for that specific room in which the player is in
        
        //combat between player and monster
        combat(&player, currentMonster);
        
        //is player still alive? if not, defeat msg
        if (!player.isAlive()) {
            displayDefeat(playerName, i + 1);
            return 0; //End program
        }
        
        //mark current room as cleared/completed
        dungeon[i].setClear();
        cout << "\nRoom #" << (i + 1) << " cleared!" << endl;
        cout << "Current stats: ";
        player.displayStats(); //new player stats
    }
    
    //clear all rooms by calling player
    displayVictory(&player);
    
    return 0; //End program 
}