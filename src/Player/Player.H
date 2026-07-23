#pragma once

#include <string>


class Player
{

public:

    std::string name;


    bool homeUnlocked = false;

    bool wizardID = false;

    bool wizardGuildScene1 = true;

    bool dungeonScene1 = true;



public:

    Player();

    void Reset();
};