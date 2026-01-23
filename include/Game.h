#pragma once
#include <iostream>
#include <string>
#include "../include/Player.h"
#include<vector>
#include "../include/Enemy.h"


class Game{

    private:
        bool playing;
        Player* player;
        std::vector<Enemy> enemies;    //<---- 3. The container for our enemies.

    public:
    //Constructor and Destructor
        Game();
        virtual ~Game();

    //Functions
    void mainMenu();
    void spawnEnemies(int count);
    void printEnemies();
    bool getPlaying() const;

};