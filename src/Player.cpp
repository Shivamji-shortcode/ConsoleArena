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