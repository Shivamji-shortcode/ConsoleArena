#include "../include/Game.h"
// Constructor : Intialize Variables
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
void Game::mainMenu() {
    std::cout << "--- MAIN MENU ---" << std::endl;
    std::cout << "1. Create Player" << std::endl;
    std::cout << "2. Spawn Enemies (Debug)" << std::endl; // <--- New Option
    std::cout << "3. Show Enemies (Debug)" << std::endl;  // <--- New Option
    std::cout << "4. Fight First Enemy (Debug)" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Choice: ";
    
    int choice;
    std::cin >> choice;

    switch (choice) {
        case 0:
            this->playing = false;
            break;
        case 1:
        {
            // Ask for name
            std::cout << "Enter Name: ";
            std::string name;
            std::cin >> name;
            // DYNAMIC ALLOCATION: Create the player on the Heap
            if (this->player != nullptr) { 
                delete this->player; // Safety: delete old player if one exists
            }
            this->player = new Player(name);
            // Prove it worked
            this->player->printStats();
            break;
        }
        case 2: // <--- New Logic for Spawning
            this->spawnEnemies(3); // Adds 3 enemies to the vector
            break;
        case 3: // <--- New Logic for Printing
            this->printEnemies(); // Loops through vector and prints stats
            break;
        case 4: // Fight logic
            // Check if there are enemies left to fight
            if (!this->enemies.empty())
            {
                //Fight the first enemy(Index 0)
                this->combat(this->enemies[0]);
                // if the we just fought is dead
                if (!this->enemies[0].isAlive())
                {
                    this->enemies.erase(this->enemies.begin());
                    std::cout<<"The enemy has been removed from the list."<<std::endl;
                }
            }
            else
            {
                std::cout<<" No Enemies too fight! spawn them first. "<<std::endl;
            }
            break;
        default:
            break;
    }
}
bool Game::getPlaying() const{
    return this->playing;
}
void Game::spawnEnemies(int count){
    for(int i = 0; i < count; i++){
        //create a new enemy level(Level 1 for now)
        //push_back adds it to the end of the vector
        this->enemies.push_back(Enemy(1));
    }
    std::cout<<"Spawned "<<count<<" enemies! " <<std::endl;
}
void Game::printEnemies(){
    std::cout<<"-----CURRENT ENEMIES-----" <<std::endl;
    // e is a reference to each enemy inside the vector;
    int index = 0;
    for(auto& e : this->enemies){
        std::cout<< index <<"; "<<e.getStatus() <<std::endl;
        index++;
    }
    std::cout<<"----------------" <<std::endl;
}
void Game::combat(Enemy& enemy){
    // Start the battle loop 
    // We fight as long as Player and enemy are both alive
    while (this->player->isAlive() && enemy.isAlive())
    {
        std::cout<<"\n---Battle---"<<std::endl;
        std::cout<<"Player Hp: "<<this->player->getHp()<<std::endl;
        std::cout<<"Enemy: "<<enemy.getStatus()<<std::endl;

        std::cout<<"1. Attack" <<std::endl;
        std::cout<<"2. Heal" <<std::endl;
        std::cout<<"Choice: ";
        int Choice;
        std::cin>>Choice;
        //Switch case 
        switch (Choice)
        {
        case 1:
            //attack
            enemy.takeDamage(this->player->getDamage());
            break;
        case 2:
            // heal
            std::cout<<"You braced yourself! "<<std::endl;
            break;
        default:
            break;
        }
        // Enemy turn(counter- attack)
        if (enemy.isAlive())
        {
            std::cout<<"Enemy attacks back! "<<std::endl;
            //Now this works too
            this->player->takeDamage(enemy.getDamage());
        }   
    }
    if (this->player->isAlive())
    {
        std::cout<<"\n---VICTORY---"<<std::endl;
        std::cout<<"You defeated the "<<enemy.getStatus()<<" enemy!"<<std::endl;
    }
    else
    {
        std::cout<<"\n----Game over----"<<std::endl;
        std::cout<<"You have lost the battle...."<<std::endl;
    }
}
