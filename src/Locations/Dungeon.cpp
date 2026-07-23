#include "Dungeon.h"
#include <chrono> 
#include <thread>
#include <iostream>

int dialogueWaitTimeDungeon = 6;

void Dungeon::Enter(Player& player, Dialogue& dialogue)
{

    std::system("cls");
    if(player.wizardID){
        if(player.dungeonScene1){
            // std::cout << "????:" << std::endl;
            // std::cout << "Hey! Can I see your ID." << std::endl;
            // std::this_thread::sleep_for(std::chrono::seconds(dialogueWaitTimeDungeon));
            // std::cout << "Ah, Welcome to the dungeon {playerName}" << player.name << std::endl;
            // std::this_thread::sleep_for(std::chrono::seconds(dialogueWaitTimeDungeon));
            // std::cout << "the names Thorten! I am the keeper of this here dungeon." << player.name << std::endl;
            // std::this_thread::sleep_for(std::chrono::seconds(dialogueWaitTimeDungeon));
            // std::cout << "\nYou:" << std::endl;
            // std::cout << "Um could you please tell me more about the dungeon." << std::endl;
            // std::this_thread::sleep_for(std::chrono::seconds(dialogueWaitTimeDungeon - 2));
            // std::cout << "you see, I am new and never been in a dungeon before." << std::endl;
            // std::this_thread::sleep_for(std::chrono::seconds(dialogueWaitTimeDungeon));
            // std::cout << "\nThorten:" << std::endl;
            // std::cout << "AH a newbie are ya? Well yer came to the right place, as the keeper I know all there is to know about this dungeon" << std::endl;
            // std::this_thread::sleep_for(std::chrono::seconds(dialogueWaitTimeDungeon));
            // std::cout << "Basically, ya go in there, kill all the monsters, take thier loot, sell thier loot, and then ya repeat." << std::endl;
            // std::this_thread::sleep_for(std::chrono::seconds(dialogueWaitTimeDungeon));
            // std::cout << "There be rest sites every 3 floors, you can use it regen mana and health. You can progress a floor by killing the floor boss, it appears after 5 combats." << std::endl;
            // std::this_thread::sleep_for(std::chrono::seconds(dialogueWaitTimeDungeon));
            // std::cout << "And thats about it. Good luck out there kid." << std::endl;
            dialogue.Play("Thorten_First_Meeting");
            player.dungeonScene1 = false;
        }

        while(true){
            std::cout << "Would you like to enter the dungeon? (/Yes,/No)" << std::endl;
            std::string command;
            std::getline(std::cin,command);
            if(command == "/Yes"){
                std::system("cls");
                break;
            }else if(command == "/No"){
                std::system("cls");
                break;
            }else{
                std::cout << "Incorrect Command, Please Try Again!";
            }

        }
        
    }else{
        std::cout << "????:" << std::endl;
        std::cout << "Hey, the dungeon is off limits to non-guild-members. Go to the wizards guild to make your ID then come back here." << std::endl;
    }

}