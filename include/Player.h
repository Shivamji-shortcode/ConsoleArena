#pragma once   
#include <string>
#include<iostream>

class Player{

    private:
        std::string name;
        int hp;
        int hpMax;
        int damage;
        int exp;
        int expNext;
        int level;
        int gold;
    public:
    //constructor take a name for the character

    Player(std::string name);
    ~Player();

    //Functions;
    void printStats();
    bool isAlive();
    int getDamage();
    int getHp();
    int getLevel();
    void heal(int amount);
    void takeDamage(int damage);
    void gainExp(int exp);
    int getGold();
    void gainGold(int amount);
    void payGold(int amount);

};