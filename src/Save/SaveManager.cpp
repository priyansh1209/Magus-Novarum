#include "SaveManager.h"

#include <iostream>
#include <fstream>
#include <cstdio>

#include "../../external/json.hpp"


using json = nlohmann::json;



void SaveManager::Save(Player& player)
{

    json saveData;


    saveData["player"]["name"] =
        player.name;


    saveData["player"]["homeUnlocked"] =
        player.homeUnlocked;


    saveData["player"]["wizardID"] =
        player.wizardID;



    saveData["dialogue"]["wizardGuildScene1"] =
        player.wizardGuildScene1;


    saveData["dialogue"]["dungeonScene1"] =
        player.dungeonScene1;



    std::ofstream saveFile(savePath);


    if(saveFile.is_open())
    {

        saveFile << saveData.dump(4);

        saveFile.close();


        std::cout
        << "[SUCCESS] Game saved!\n";

    }

}



bool SaveManager::Load(Player& player)
{

    std::ifstream saveFile(savePath);



    if(!saveFile.is_open())
    {

        std::cout
        << "[NOTICE] No save found. Starting new game.\n";

        return false;

    }



    json saveData;


    saveFile >> saveData;


    saveFile.close();



    player.name =
        saveData["player"]["name"];


    player.homeUnlocked =
        saveData["player"]["homeUnlocked"];


    player.wizardID =
        saveData["player"]["wizardID"];



    player.wizardGuildScene1 =
        saveData["dialogue"]["wizardGuildScene1"];


    player.dungeonScene1 =
        saveData["dialogue"]["dungeonScene1"];



    std::cout
    << "[SUCCESS] Save loaded!\n";


    return true;

}





void SaveManager::DeleteSave()
{

    if(std::remove(savePath.c_str()) == 0)
    {

        std::cout
        << "[SUCCESS] Save deleted.\n";

    }
    else
    {

        std::cout
        << "[NOTICE] No save file found.\n";

    }

}