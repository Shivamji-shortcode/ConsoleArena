#include "../include/Player.h"
#include <windows.h>

Player::Player(std:: string name){
    this->name = name;
    this->hpMax = 100;
    this->hp = hpMax;
    this->damage = 10;
    this->level = 1;
    this->exp = 0;
    this->expNext = 100; // need the 100 Exp to reach next level like form level 1 to 2;
    this->gold = 0;         // Start Poor hahahahahah;
}

Player::~Player(){
    // Empty for now
}

void Player::printStats(){
    std::cout<<"--- Player States ----"<<std::endl;
    Sleep(100);
    std::cout<<"Name: "<<this->name<<std::endl;
    Sleep(100);
    std::cout<<"level: "<<this->level<<std::endl;
    Sleep(100);
    std::cout<<"Hp: "<<this->hp<<std::endl;
    Sleep(100);
    std::cout<<"Exp: "<<this->exp<<std::endl;
    Sleep(100);
    std::cout<<"Damage: "<<this->damage<<std::endl;
    Sleep(100);
    std::cout<<"Gold: "<<this->gold<<" G"<<std::endl; // added the gold gain line;
    Sleep(100);
    std::cout<<"-----------------"<<std::endl;  
    Sleep(300);
}
bool Player::isAlive(){
    return this->hp > 0;
}
int Player::getDamage(){
    return this->damage;
}
void Player::takeDamage(int damage){
    this->hp -=damage;
    if (this->hp < 0)
    {
        this->hp = 0;
    }
    std::cout<<"You took "<< damage << " damage!"<<std::endl;
}
int Player::getHp(){
    return this->hp;
}
void Player::heal(int amount){
    int originalHp = this->hp;      // Remember the hp before healing;
    //add the heal amount;
    this->hp += amount;
    //
    if (this->hp > this->hpMax)
    {
        this->hp = this->hpMax;
    }
    // calculate actually how we trully heal;
    int trueHeal = this->hp - originalHp;
    std::cout<<" You healed for "<< trueHeal <<" HP! "<<std::endl;
    Sleep(100);
    // Optional : print Print the status so you can see the 100/100
    std::cout<<" Current HP! "<< this->hp <<"/"<<this->hpMax<<std::endl;
    Sleep(100);
}
void Player::gainExp(int exp){
    this->exp +=exp;
    std::cout<<" You gained "<< exp <<" XP!"<<std::endl;
    // level up check;
    while (this->exp >= this->expNext)
    {
        this->exp -= this->expNext;     // keeps extra xp;
        this->level++;
        this->expNext += 50;    // Next level is harder (100 - > 150 - > 200)
        //Reward : star increase;
        // this->hpMax += 20;
        // this->damage += 5;
        // this->hp = this->hpMax;     // Full heal on level up;
        // std::cout<<"Level UP! You are no level "<<this->level<<"!"<<std::endl;
        // std::cout<<"Stats Increased: HP -> "<<hpMax<<" | Dmg -> "<<this->damage<<std::endl;    Previous code now upgrading the code;
        system("cls");
        Sleep(1000);
        std::cout<<"==================="<<std::endl;
        Sleep(100);
        std::cout<<"Level UP! You are at level "<<this->level<<std::endl;
        Sleep(100);
        std::cout<<"You have 1 skill point"<<std::endl;
        Sleep(100);
        std::cout<<"1. Strength(+5 damage)"<<std::endl;
        Sleep(100);
        std::cout<<"2. Vitality(+20 MaxHp)"<<std::endl;
        Sleep(100);
        std::cout<<"3. Full Heal only(Save Point)"<<std::endl;
        Sleep(100);
        std::cout<<"Chosse Your Upgrade !!!!!!"<<std::endl;
        Sleep(100);
        int choice;
        std::cin>>choice;
        //Applying the upgrade--------------
        if (choice == 1)
        {
            this->damage += 5;
            std::cout<<"Nice Choice, You feel Stronger got, +5 damages! Yahoooooo!"<<std::endl;
        }
        else if (choice == 2)
        {
            this->hpMax += 20;
            std::cout<<"Woww, You feel Stronger and tougher got +20 max Hp, Yahooooo!"<<std::endl;
        }
        else
        {
            std::cout<<"Not bad, You chhose to Just heal up.hahahahaha!"<<std::endl;
        }
        // Always heal up the full on next level or level up;
        this->hp = this->hpMax;
        std::cout<<"-> Healt Fully Recovered to "<<hpMax<<" !"<<std::endl;
        // Pause so you can actually see the result;
        std::cout<<"Press enter to continue! "<<std::endl;
        std::cin.ignore();
        std::cin.get();
    }
}
int Player::getLevel() {
    return this->level;
}
int Player::getGold(){
    return this->gold;
}
void Player::gainGold(int amount){
    this->gold += amount;
    std::cout<<"you found "<<amount <<" Gold! "<<std::endl;
    Sleep(100);
}
void Player::payGold(int amount){
    this->gold -= amount;
    std::cout<<"You paid "<<amount <<"Gold! "<<std::endl;
    Sleep(100);
}
void Player::healMax(){
    this->hp = this->hpMax;
    std::cout<<"You have taken rest HP restored to "<< this->hp <<"!"<<std::endl;
    Sleep(1000);
}
void Player::upgradeStat(int hp, int dmg){
    this->hp += hp;
    this->damage += dmg;
    this->hp = this->hpMax;     // Optional : heal when upgraded HP
    std::cout<<" UGRADE SUCCESSFUL!"<<std::endl;
    std::cout<<"New Max HP: "<< this->hpMax <<" | New Damage: "<< this->damage <<std::endl;
    Sleep(1000);
}