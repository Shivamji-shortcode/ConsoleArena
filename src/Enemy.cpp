#include "../include/Enemy.h"

Enemy::Enemy(int level){
    this->level = level;
    this->hpMax = level*10; //Level 1 = level 10 hp; level 5 = 50 hp;
    this->hp = this->hpMax;
    this->damage = level*2; // level 1 = 2 damage
    this->defense = level*1;
}

Enemy::~Enemy(){

}
bool Enemy::isAlive(){
    return this->hp > 0;
}
std::string Enemy::getStatus(){
    return "level: "+ std::to_string(this->level)+
    " | HP: " + std::to_string(this->hp) + 
    " | Dmg: " + std::to_string(this->damage);
}
int Enemy::getDamage() const{
    return this->damage;
}
void Enemy::takeDamage(int damage){
    int actualdamage = damage - this->defense;
    if (actualdamage < 0)
    {
        actualdamage = 0;
    }
    this->hp -= actualdamage;
    if (this->hp <= 0)
    {
        this->hp = 0; // Keeps hp to 0 not in minus representation;
        std::cout<<" You dealt "<<actualdamage<<" damage "<<std::endl;
        std::cout<<" -> The enemy has been DEFEATED! Congrats."<<std::endl;
    }
    else
    {
        std::cout<<" You dealt "<<actualdamage<<" damage. "<<std::endl;
        std::cout<<" -> Enemy HP: "<<this->hp<<"/"<<this->hpMax<<std::endl;
    }
    
}
