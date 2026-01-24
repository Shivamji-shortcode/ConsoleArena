#include "../include/Player.h"

Player::Player(std:: string name){
    this->name = name;
    this->hpMax = 100;
    this->hp = hpMax;
    this->damage = 10;
}

Player::~Player(){
    // Empty for now
}

void Player::printStats(){
    std::cout<<"--- Player States ----"<<std::endl;
    std::cout<<"Name: "<<this->name<<std::endl;
    std::cout<<"Hp: "<<this->hp<<std::endl;
    std::cout<<"Damage: "<<this->damage<<std::endl;
    std::cout<<"-----------------"<<std::endl;  
}
bool Player::isAlive(){
    return this-hp > 0;
}
int Player::getDamage(){
    return this->damage;
}
void Player::takeDamage(int dmage){
    this->hp -=damage;
    if (this-hp < 0)
    {
        this->hp = 0;
    }
    std::cout<<"You took "<< damage << " damage!"<<std::endl;
}
int Player::getHp(){
    return this->hp;
}
void Player::heal(int amount){
    this->hp += amount;
    if(this->hp > this->hpMax){
        this->hp = this->hpMax;
    }
}