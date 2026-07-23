#include "WizardGuild.h"

#include <iostream>
#include <thread>
#include <chrono>

void WizardGuild::Enter(Player& player, Dialogue& dialogue)
{

    std::system("cls");
    if(player.wizardID == true){
        std::cout << "Feature WIP";
    }else{
        if(player.wizardGuildScene1 == true){
            
            dialogue.Play("Aveline_First_Meeting");
            player.wizardGuildScene1 = false;
        }
        while(true){
            std::cout << "\nAveline:" << std::endl;
            std::cout << "Would you like to register with our guild today? (/Yes, /No)" << std::endl;
            std::string command;
            std::getline(std::cin,command);
            if(command == "/Yes"){
                std::cout << "...Updating Database" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(4));
                std::cout << "...Getting User Data From Database" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(4));
                std::cout << "...Writing Data To ID Card" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(4));
                std::cout << "...Finalising Details" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(4));
                std::cout << "\nAveline:" << std::endl;
                std::cout << "Ok Sir, here is you ID card, you can view this card at anytime you visit the guild by typing /ID. \nHope you have a good day and make sure to check out the dungeon if your looking for quick cash, or check the quest board (/Quests) for extra jobs" << std::endl;
                std::this_thread::sleep_for(std::chrono::seconds(8));
                player.wizardID = true;
                break;
            }else if(command == "/No"){
                std::cout << "\nAveline:" << std::endl;
                std::cout << "Ok sir, have a good day, come back to the guild when you are ready to make your ID, or need information!" << std::endl;
                std::system("cls");
                break;
            }else{
                std::cout << "Incorrect Command, Please Try Again!";
            }
        }
        
        
    }   

}