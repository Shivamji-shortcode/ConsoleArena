#pragma once   
#include <string>
#include<iostream>
#include <fstream>      // Allows reading/writing files



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
        int potions;
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
    void healMax();
    void upgradeStat(int hp, int dmg);
    int getPotions();
    void gainPotion(int amount);
    void consumePotion();
    void saveCharacter();
    void loadCharacter();

};