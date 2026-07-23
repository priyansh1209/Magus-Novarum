#pragma once

#include "../Player/Player.h"
#include "../Save/SaveManager.h"
#include "../Dialogue/Dialogue.h"

#include "../Locations/WizardGuild.h"
#include "../Locations/Dungeon.h"
#include "../Locations/Home.h"


class Game
{

private:

    bool gameIsRunning;

    Player player;

    SaveManager saveManager;

    WizardGuild wizardGuild;
    Dialogue dialogue;
    Dungeon dungeon;
    Home home;


    void Menu();

    void NameDecision();

    void LocationNames();

    void TownCommands();


public:

    Game();

    void Start();

};