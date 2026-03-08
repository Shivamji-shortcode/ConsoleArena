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
    std::cout<<"7. Save Game"<<std::endl;
    Sleep(100);
    std::cout<<"8. Load Game"<<std::endl;
    Sleep(100);
    std::cout << "0. Exit" << std::endl;
    Sleep(100);
    std::cout << "Choice: ";
    Sleep(100);

    // int choice;
    // std::cin >> choice;
    std::string rawInput;
    std::cin>>rawInput;
    Sleep(300);
    bool isNumber = true;
    //for loop to ASCII check: to every sigle character typed;
    for (int i = 0; i < rawInput.length(); i++)
    {
        // If the ASCII value is less than thenn 48(0) and the greater than the 57(9)
        if (rawInput[i] < 48 || rawInput[i] > 57)
        {
            isNumber = false;
            break;  // Stop the checking we found the bad symbol/lettter;
        }
    }
    // if they typed the wrong alphabet or the symbol blockk them and restart the menu;
    if (isNumber == false)
    {
        std::cout<<"\n[!] INPUT ERROR : You hit wrong button"<<std::endl;
        Sleep(100);
        std::cout<<"    Please type a valid Number that are given in the menu, No letters and the symbols."<<std::endl;
        Sleep(1500);
        return;
    }
    // If we survive the loop, convert the string to an integer;
    int choice = std::stoi(rawInput);
    

    switch (choice) {
        case 0:
        {
            // this->playing = false;
            // Sleep(100);
            // break;
            //New exit warning updated code for the global crash;
            std::cout<<"\n[!] WARNING: Did you remember to Save (Option 7)?"<<std::endl;
            Sleep(50);
            std::cout<<"    Any unsaved changes or progress will be lost forever in the void."<<std::endl;
            Sleep(50);
            std::cout<<"    Are you SURE you want to quit? (Type Y/y for Yes or N/n for No):"<<std::endl;
            Sleep(50);
            std::string confirmRaw;
            std::cin>>confirmRaw;
            if (confirmRaw[0] == 'Y' || confirmRaw[0] == 'y')
            {
                std::cout<<"Shutting down the game......Goodbye!"<<std::endl;
                Sleep(500);
                this->playing = false; // Actually quit the game;
            }
            else
            {
                std::cout<<"Phew! That was close. Returning to main menu...."<<std::endl;
            }
            Sleep(100);
            break;
        }    
        case 6:{        // Show staes;
            if (this->player != nullptr)
            {
                this->player->printStats();
            }
            else
            {
                std::cout<<"\n[!] System Error: No Stats Availble."<<std::endl;
                std::cout<<" -> Plaese Select option 1 (Cretae New)"<<std::endl;
                std::cout<<"-> OR Select Option 8 (load Game) to load previous character if you had played."<<std::endl;
                Sleep(3000);
            }
            break;
        }
        case 1:{
            if (this->player != nullptr)
            {
                std::cout<<"\n[!] WARNING: A character is already exists!"<<std::endl;
                std::cout<<" Creating a new  character will DELETE your current progress. "<<std::endl;
                std::cout<<" Are you sure type Y- for Yes and N- for No"<<std::endl;
                char confirm;
                std::cin>>confirm;

                if (confirm == 'n' || confirm == 'N')
                {
                    std::cout<<"Cancelled! Returning to main Menu...."<<std::endl;
                    Sleep(1000);
                    break;
                }
                // If they typed 'y' we proceed to delete the old one
                delete this->player;
            }
             // Ask for name
             std::cout << "Enter Name: ";
             std::string name;
             std::cin >> name;
             this->player = new Player(name);
             // -----------------------------------------Cinematic  Delays Windows version-----------------------------------------//
             std::cout<<"\n Creating Character!!!!!!....."<<std::endl;
             Sleep(1000);
             std::cout<<"Loading world asset...."<<std::endl;
             Sleep(1000);
             std::cout<<"Welcome, "<< name<<"! "  <<std::endl;
             this->player->printStats();
             // Prove it worked
             // Wait for user to to read stats;
             std::cout<<"\n Press Enter to Continue..."<<std::endl;
             std::cin.ignore();
             std::cin.get();
             break;
        }
        case 2: // <--- New Logic for Spawning
            if (this->player != nullptr)
            {
                this->spawnEnemies(3);
            }
            else
            {
                std::cout<<"\n[!] System Error: No Player Found."<<std::endl;
                std::cout<<" -> Plaese Select option 1 (Cretae New)"<<std::endl;
                std::cout<<"-> OR Select Option 8 (load Game) to load previous character if you had played."<<std::endl;
                Sleep(3000);
            }
            break;
        case 3: // <--- New Logic for Printing
            if (this->player != nullptr)
            {
                this->printEnemies();
            }
            else
            {
                std::cout<<"\n[!] System Error: No Player Found."<<std::endl;
                std::cout<<" -> Plaese Select option 1 (Cretae New)"<<std::endl;
                std::cout<<"-> OR Select Option 8 (load Game) to load previous character if you had played."<<std::endl;
                Sleep(3000);
            }            
            break;
        case 4: // Fight logic
        {
            // 1. SAFETY CHECK: Does the player exist?
            if (this->player != nullptr)
            {
                // Player exists, so proceed with fight logic

                // Check if there are enemies left to fight
                if (!this->enemies.empty())
                {
                    // Fight the first enemy (Index 0)
                    this->combat(this->enemies[0]);

                    // If the enemy we just fought is dead, remove them
                    if (!this->enemies[0].isAlive())
                    {
                        this->enemies.erase(this->enemies.begin());
                        std::cout << "The enemy has been removed from the list." << std::endl;
                    }
                }
                else
                {
                    std::cout << "No Enemies to fight! Spawn them first (Option 2)." << std::endl;
                    Sleep(1000);
                }
            }
            else
            {
                // Player is NULL -> Print Error & Suggest Load/Create
                std::cout << "\n[!] System Error: You cannot fight without a body!" << std::endl;
                std::cout << "   -> Please select Option 1 (Create New)" << std::endl;
                std::cout << "   -> OR select Option 8 (Load Game)" << std::endl;
                Sleep(2000);
            }
            break;
        }
        case 5:     // ----------------------------------------------Go to Shop Menu--------------------------------------------------
            if (this->player != nullptr)
            {
                this->shopMenu();
            }
            else
            {
                std::cout<<"\n[!] Shopkeeper: No Player Found,'I don't Serve Ghost!'."<<std::endl;
                std::cout<<" -> Plaese Select option 1 (Cretae New)"<<std::endl;
                std::cout<<"-> OR Select Option 8 (load Game) to load previous character if you had played."<<std::endl;
                Sleep(3000);
            }
            break;
        case 7:
            if (this->player != nullptr)
            {
                this->player->saveCharacter();
                Sleep(1000);        // Wait 1 sec so user can see Saved Successfully;
            }
            else
            {
                std::cout<<"\n[!] System Error: Nothing to Save."<<std::endl;
                std::cout<<" -> Plaese Select option 1 (Cretae New)"<<std::endl;
                std::cout<<"-> OR Select Option 8 (load Game) to load previous character if you had played."<<std::endl;
                Sleep(3000);
            }
            break;
        case 8:
            // If we dont have a player yet create a temporary one so we can use the load function
            if (this->player == nullptr)
            {
                this->player = new Player("Temp");
            }
            this->player->loadCharacter();
            Sleep(1000);
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
                // Check If we have enought potions first;
                if (this->player->getPotions() > 0)
                {
                    this->player->consumePotion(); // removes One potions;
                    int healAmount = rand() % 21 + 10;
                    this->player->heal(healAmount);
                    std::cout<<"You Used a Potion. ("<< this->player->getPotions()<< " left)"<<std::endl;
                }
                else
                {
                    std::cout<<"You reached your bag... but you have No Potions! "<<std::endl;
                    std::cout<<"You wasted your turn looking for one! "<<std::endl;
                }
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
                Sleep(3000);
                break;
            } 
        }   
    }
    if (this->player->isAlive())
    {
        Sleep(2000);
        std::cout<<"\n---VICTORY---"<<std::endl;
        std::cout<<"You defeated the "<<enemy.getStatus()<<" enemy!"<<std::endl;
        Sleep(2000);
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
// ----------------------------------------------------SHOP MENU --------------------------------------------------------------------------
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
        std::cout<<"4. Buy Health Potions - 20 Gold "<<std::endl;
        Sleep(50);
        std::cout<<"5. Leave Shop"<<std::endl;
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
                this->player->healMax();    
                Sleep(2000);
            }
            break;
        case 2:     // Damage upgrade 
            if (this->player->getGold() >= 50)
            {
                this->player->payGold(50);
                // We need a way to upgrade stats directly;
                this->player->upgradeStat(0, 2);       
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
        case 4:  //-----------------------Potion Buy options---------------------------
            if (this->player->getGold() >= 20)
            {
                this->player->payGold(20);
                this->player->gainPotion(1);
                std::cout<<"You Bought a potion! "<<std::endl;
                Sleep(1000);
            }
            else
            {
                std::cout<<"Not Enought Gold! earn more gold first"<<std::endl;
            }
            break;
        case 5:     //Exit
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