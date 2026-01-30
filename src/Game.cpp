#include "../include/Game.h"
#include <windows.h>        // Allows the program to sleep (pause)
#include<ctime> // we need this fot the random numbers;
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
//-----------------------------------------------------Logic show the Main Menu-----------------------------------------------------------------
void Game::mainMenu() {
    std::cout << "--- MAIN MENU ---" << std::endl;
    Sleep(100);
    std::cout << "1. Create Player" << std::endl;
    Sleep(100);
    std::cout << "2. Spawn Enemies (Debug)" << std::endl; // <--- New Option
    Sleep(100);
    std::cout << "3. Show Enemies (Debug)" << std::endl;  // <--- New Option
    Sleep(100);
    std::cout << "4. Fight First Enemy (Debug)" << std::endl;
    Sleep(100);
    std::cout << "5. Visit Shop" << std::endl;
    Sleep(100);
    std::cout << "6. Show Player's Stats" << std::endl;
    Sleep(100);
    std::cout << "0. Exit" << std::endl;
    Sleep(100);
    std::cout << "Choice: ";
    Sleep(100);

    int choice;
    std::cin >> choice;
    Sleep(300);

    switch (choice) {
        case 0:
            this->playing = false;
            Sleep(100);
            break;
        case 6:{        // Show staes;
            if (this->player != nullptr)
            {
                this->player->printStats();
            }
            else
            {
                std::cout<<"Create a Player first! "<<std::endl;
            }
            break;
        }
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
                // -----------------------------------------Cinematic  Delays Windows version-----------------------------------------//
                std::cout<<"\n Creating Character!!!!!!....."<<std::endl;
                Sleep(1000);
                std::cout<<"Loading world asset...."<<std::endl;
                Sleep(1000);
                std::cout<<"Welcome, "<< name<<"! "  <<std::endl;
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
            //security check that if the player rellly exist that user created the palyer or not if not he shloud create the player first;
            if (this->player == nullptr)
            {
                std::cout<<" Error! You must create player first(Option 1), because you have not created one"<<std::endl;
            }
            
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
        case 5:     // ----------------------------------------------Shop Menu--------------------------------------------------
            if (this->player == nullptr)
            {
                std::cout<<"Create a Character First! "<<std::endl;     
            }
            else
            {
                this->shopMenu();   // Jump to the shop menu;
            }
            break;
        default:
            break;
    }
}
bool Game::getPlaying() const{
    return this->playing;
}
void Game::spawnEnemies(int amount){
    for(int i = 0; i < amount; i++){
        Sleep(300);
        //create a new enemy level(Level 1 for now)
        //push_back adds it to the end of the vector
        this->enemies.push_back(Enemy(this->player->getLevel()));
        std::cout<<"Entity "<< i+1 <<" materialized...."<<std::endl;
    }
    Sleep(500);
    std::cout << "Spawned " << amount << " enemies at Level " << this->player->getLevel() << "!" << std::endl;
    Sleep(1200);
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
// --------------------------------------------------------Combat Function ----------------------------------------------------------
void Game::combat(Enemy& enemy){
    // Start the battle loop 
    // We fight as long as Player and enemy are both alive
    while (this->player->isAlive() && enemy.isAlive())
    {
        std::cout<<"\n---Battle---"<<std::endl;
        Sleep(100);
        std::cout<<"Player Hp: "<<this->player->getHp()<<std::endl;
        Sleep(100);
        std::cout<<"Enemy: "<<enemy.getStatus()<<std::endl;
        Sleep(100);
        std::cout<<"1. Attack" <<std::endl;
        Sleep(50);
        std::cout<<"2. Heal" <<std::endl;
        Sleep(50);
        std::cout<<"Choice: ";
        int Choice;
        std::cin>>Choice;
        Sleep(200);
        //Switch case 
        switch (Choice)
        {
        case 1:
        {
            //attack
            int damage = this->player->getDamage();
            if ((rand() % 100) < 20)
            {
                damage =    damage*2;
                std::cout<<"Critical hit";
                Sleep(200);
            }
            // Apply the potentially doubled damge
            enemy.takeDamage(damage);
            Sleep(200);
            break;
        }           
        case 2:
        {
            // heal
            //rand()%21 geerates 0-20. + 10 makes it 10-30;
            int healAmount = rand() % 21 + 10;
            this->player->heal(healAmount);
            Sleep(500);
            break;
        }    
        default:
            break;
        }
        // Enemy turn(counter- attack)
        if (enemy.isAlive())
        {
            // Pause for the Suspese before the enemy attackks;
            std::cout<<"\n Enemy is preapring to attack......."<<std::endl;
            Sleep(200);
            std::cout<<"Enemy attacks back! "<<std::endl;
            int enemyDmg = enemy.getDamage();
            // Crit Roll : 20% chance for enemy too
            if ((rand() % 100) < 20)
            {
                enemyDmg = enemyDmg*2;
                std::cout<<"Enemy landed a critical hit"<<std::endl;
                Sleep(200);
            }
            this->player->takeDamage(enemyDmg);
            Sleep(400);
            //safety check;
            if(!this->player->isAlive())
            {
                std::cout<<"You collapsed from the damage! "<<std::endl;
                break;
            } 
        }   
    }
    if (this->player->isAlive())
    {
        std::cout<<"\n---VICTORY---"<<std::endl;
        std::cout<<"You defeated the "<<enemy.getStatus()<<" enemy!"<<std::endl;
        Sleep(100);
        // --- Reward the player --- //
        this->player->gainExp(40);
        // Gold Reward (Random 10-20 gold per kill)
        int golddrop = rand() % 11 +10;
        this->player->gainGold(golddrop);
        // -----------------------//
        std::cout<<"------------------\n"<<std::endl;
    }
    else
    {
        Sleep(100);
        std::cout<<"\n----Game over----"<<std::endl;
        Sleep(100);
        std::cout<<"You have lost the battle...."<<std::endl;
        Sleep(100);
    }
}
void Game::shopMenu(){
    bool shopping = true;
    while (shopping)
    {
        system("cls");
        std::cout<<"-------Town Shop--------"<<std::endl;
        Sleep(100);
        std::cout<<"Your Gold: "<<this->player->getGold()<< std::endl;
        Sleep(100);
        std::cout<<"------------------"<<std::endl;
        std::cout<<"1. Rest at Inn (Full Heal) - (10 gold))"<<std::endl;
        Sleep(100);
        std::cout<<"2. sharpen Sword (+2 damage) - (50 Gold)"<<std::endl;
        Sleep(100);
        std::cout<<"3. Buy Heavy Armor (+10 Hp) - (50 Gold)"<<std::endl;
        Sleep(100);
        std::cout<<"4. Leave Shop. "<<std::endl;
        Sleep(50);
        std::cout<<"Chooice: ";
        int choice;
        std::cin>>choice;
        Sleep(300);     // Processing Delay;   

        switch (choice)
        {
        case 1:
            if (this->player->getGold() >= 10)
            {
                this->player->payGold(10);
                this->player->healMax();    // we need to addd this function in the player class ------------------
                Sleep(1000);
            }
            break;
        case 2:     // Damage upgrade 
            if (this->player->getGold() >= 50)
            {
                this->player->payGold(50);
                // We need a way to upgrade stats directly;
                this->player->upgradeStat(0, 2);       // We also need to add this function ---------------
                Sleep(1000);
            }
            else
            {
                std::cout<<"Too Expensive You need 50 gold! "<<std::endl;
                Sleep(1000);
            }
            break;
        case 3:     // HP upgrade---------------
            if (this->player->getGold() >= 50)
            {
                this->player->payGold(50);
                this->player->upgradeStat(10, 0);      // +10 hp, 0 dmg;
                Sleep(1000);
            }
            else
            {
                std::cout<<"Too Expensive you need 50 gold!"<<std::endl;
                Sleep(1000);
            }
            break;
        case 4:     //Exit
            shopping = false;
            std::cout<<"Come Back Soon...."<<std::endl;
            Sleep(800);
            break;
        default:
            std::cout<<"Invalid choice!"<<std::endl;
            Sleep(500);
            break;
        }
    }
}