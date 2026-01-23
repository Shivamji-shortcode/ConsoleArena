#pragma once
#include <iostream>
#include <string>
#include "../include/Player.h"

class Game{

    private:
        bool playing;
        Player* player;

    public:
    //Constructor and Destructor
        Game();
        virtual ~Game();

    //Functions
    void mainMenu();
    bool getPlaying() const;

};