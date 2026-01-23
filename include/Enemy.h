#pragma once 
#include <string>
#include <iostream>
#include<vector>

class Enemy{

    private:
        int level;
        int hp;
        int hpMax;
        int damage;
        int defense;
    public:
        // constructor trakes the level to determine how strong the enemy is;
        Enemy(int level);
        ~Enemy();

        //Accessors
        bool isAlive();
        std::string getStatus();
        int getDamage() const;
        
        //Modifiers;
        void takeDamage(int damage);
};

