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
    this->gold = 0;  // Start Poor hahahahahah;
    this->potions = 1;       
}

Player::~Player(){
    // Empty for now
}
//-------------------------------------------------Player Stats---------------------------------------------------------------------
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
    std::cout<<"Potions: "<<this->potions<<" G"<<std::endl;
    Sleep(100);
    std::cout<<"-----------------"<<std::endl;  
    Sleep(300);
}
bool Player::isAlive(){         // -------------------------Checking if player is alive or not -------------------------
    return this->hp > 0;
}
int Player::getDamage(){        // -----------------------Getting the damage to enemy----------------------------------
    return this->damage;
}
void Player::takeDamage(int damage){        // Taking the damage from enemy
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
void Player::heal(int amount){      //---------Option 2 between the battle to heal options-------------------------
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
void Player::gainExp(int exp){      // --------------------------------Gainign Experties while killing enemies-------------------
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
            Sleep(100);
        }
        else if (choice == 2)
        {
            this->hpMax += 20;
            std::cout<<"Woww, You feel Stronger and tougher got +20 max Hp, Yahooooo!"<<std::endl;
            Sleep(100);
        }
        else
        {
            std::cout<<"Not bad, You chhose to Just heal up.hahahahaha!"<<std::endl;
            Sleep(100);
        }
        // Always heal up the full on next level or level up;
        this->hp = this->hpMax;
        std::cout<<"-> Healt Fully Recovered to "<<hpMax<<" !"<<std::endl;
        Sleep(100);
        // Pause so you can actually see the result;
        std::cout<<"Press enter to continue! "<<std::endl;
        Sleep(100);
        std::cin.ignore();
        std::cin.get();
    }
}
int Player::getLevel() { //----------------------------leveling up the player-----------------
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
int Player::getPotions(){
    return this->potions;
}
void Player::gainPotion(int amount){
    this->potions += amount;
}
void Player::consumePotion(){
    this->potions--;
}
//-------We need to write the character's stats to a text file so user can come back tomorrow and continue the adventure--------
void Player::saveCharacter(){
    std::cout<<"Saving game data"<<std::endl;
    Sleep(500);
    std::ofstream outFile("save.txt");      //'ofstream' = output file system;
    if (outFile.is_open())
    {
        // Write the data in specific order;
        outFile<<this->name<<"\n";
        outFile<<this->level<<"\n";
        outFile<<this->exp<<"\n";
        outFile<<this->expNext<<"\n";
        outFile<<this->hp<<"\n";
        outFile<<this->hpMax<<"\n";
        outFile<<this->damage<<"\n";
        outFile<<this->gold<<"\n";
        outFile<<this->potions<<"\n";
        outFile.close();
        Sleep(300);
        std::cout<<"Game saved successfully"<<std::endl;
    }
    else
    {
        std::cout<<"Could not save the game."<<std::endl;
    }  
}
void Player::loadCharacter(){
    std::cout<<"Searching for save files...."<<std::endl;
    Sleep(500);
    std::ifstream inFile("save.txt");       // 'ifstream' means Input File System
    if (inFile.is_open())
    {
        // We must read in exact order as we wrote;
        std::string line;
        inFile>>this->name;
        inFile>>this->level;
        inFile>>this->exp;
        inFile>>this->expNext;
        inFile>>this->hp;
        inFile>>this->hpMax;
        inFile>>this->damage;
        inFile>>this->gold;
        inFile>>this->potions;

        inFile.close();
        Sleep(300);
        std::cout<<"Game Loaded! Welcome Back, "<< this->name <<std::endl;
    }
    else
    {
        Sleep(300);
        std::cout<<"No Saved File found!!!!"<<std::endl;
    }
}
// void Player::healMax(){
//     this->hp = this->hpMax;
// }