#include <iostream>
#include "include/Game.h"

int main(){

    // Initialize of Game engine;
    Game game;
    // Game loop;
    // This keeps the playing window open until playing become false;
    while(game.getPlaying()){
        game.mainMenu();
    }
    return 0;
}
