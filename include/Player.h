#pragma once   
#include <string>
#include<iostream>

class Player{

    private:
        std::string name;
        int hp;
        int hpMax;
        int damage;
    public:
    //constructor take a name for the character

    Player(std::string name);
    ~Player();

    //Functions;
    void printStats();
    bool isAlive();
    int getDamage();
    int getHp();
    void heal(int amount);
    void takeDamage(int damage);

};