#include "Home.h"

#include <iostream>

void Home::Enter(Player& player, Dialogue& dialogue)
{

    std::system("cls");
    if(player.homeUnlocked == true){
        std::cout << "You walk into your abode, tired, but ready for the next task\n";
    }else{
        std::cout << "You walk around, looking for your home, but then you realise you just got here and dont have a home yet. Would you like to buy one for 300 gold.\n";
    }

}