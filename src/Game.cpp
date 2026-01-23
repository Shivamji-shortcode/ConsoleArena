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
void Game::mainMenu() {
    std::cout << "--- MAIN MENU ---" << std::endl;
    std::cout << "1. Create Player" << std::endl;
    std::cout << "2. Spawn Enemies (Debug)" << std::endl; // <--- New Option
    std::cout << "3. Show Enemies (Debug)" << std::endl;  // <--- New Option
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