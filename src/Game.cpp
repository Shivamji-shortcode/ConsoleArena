#include "../include/Game.h"

// Constructo : Intialize Variables

Game::Game(){

    this->playing = true;
    this->player = nullptr;
}
Game::~Game(){
    //Free the memory if player exists
    if (this->player != nullptr)
    {
        delete this->player;
    }
    

}
//Logic show the menu

void Game::mainMenu(){
    std::cout<<"---Main Menu---"<<std::endl;
    std::cout<<"1. Start"<<std::endl;
    std::cout<<"0. Exit"<<std::endl;
    std::cout<<"Choice:";

    int choice;
    std::cin>>choice;

    switch (choice)
    {
    case 0:
        this->playing = false;
        break;
    case 1:
    {
        // Ask for  name;
        std::cout<<"Name:"<<std::endl;
        std::string name;
        std::cin>>name;

        //Dynamic allocation : create the player on the Heap
        if (this->player != nullptr)
        {
            delete this->player; // Safety: delete old player if one exists;
        }
        this->player = new Player(name);
        
        // Prove it worked;
        this->player->printStats();
        break;
    }
    default:
        break;
    }
}
bool Game::getPlaying() const{
    return this->playing;
}