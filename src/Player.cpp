#include "../include/Player.h"

Player::Player(std:: string name){
    this->name = name;
    this->hpMax = 100;
    this->hp = hpMax;
    this->damage = 10;
    this->level = 1;
    this->exp = 0;
    this->expNext = 100; // need the 100 Exp to reach next level like form level 1 to 2;
}

Player::~Player(){
    // Empty for now
}

void Player::printStats(){
    std::cout<<"--- Player States ----"<<std::endl;
    std::cout<<"Name: "<<this->name<<std::endl;
    std::cout<<"level: "<<this->level<<std::endl;
    std::cout<<"Hp: "<<this->hp<<std::endl;
    std::cout<<"Exp: "<<this->exp<<std::endl;
    std::cout<<"Damage: "<<this->damage<<std::endl;
    std::cout<<"-----------------"<<std::endl;  
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
    // Optional : print Print the status so you can see the 100/100
    std::cout<<" Current HP! "<< this->hp <<"/"<<this->hpMax<<std::endl;
}
void Player::gainExp(int exp){
    this->exp +=exp;
    std::cout<<" You gained "<< exp <<"XP!"<<std::endl;
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
        std::cout<<"==================="<<std::endl;
        std::cout<<"Level UP! You are at level "<<this->level<<std::endl;
        std::cout<<"You have 1 skill point"<<std::endl;
        std::cout<<"1. Strength(+5 damage)"<<std::endl;
        std::cout<<"2. Vitality(+20 MaxHp)"<<std::endl;
        std::cout<<"3. Full Heal only(Save Point)"<<std::endl;
        std::cout<<"Chosse Your Upgrade !!!!!!"<<std::endl;
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