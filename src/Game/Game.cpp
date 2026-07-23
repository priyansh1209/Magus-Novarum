#include "Game.h"

#include <iostream>
#include <cstdlib>


Game::Game()
{
    gameIsRunning = true;
    dialogue.SetPlayer(&player);
}


void Game::Start()
{
    Menu();

    while(gameIsRunning)
    {
        TownCommands();
    }
}


void Game::Menu()
{
    system("cls");


    std::cout 
        << "Reincarnated as a mage!\n";


    std::cout
        << "/Play to play\n"
        << "/Options for options\n"
        << "/Delete to delete save\n"
        << "/Exit to exit\n";


    while(true)
    {

        std::string command;
        std::getline(std::cin, command);


        if(command == "/Play")
        {

            saveManager.Load(player);
            NameDecision();
            break;

        }


        else if(command == "/Delete")
        {

            saveManager.DeleteSave();
            player.Reset();
            Menu();
            break;

        }


        else if(command == "/Exit")
        {

            saveManager.Save(player);
            exit(0);

        }


        else
        {
            std::cout 
                << "Incorrect Command\n";
        }

    }

}



void Game::NameDecision()
{

    system("cls");


    if(player.name == "")
    {

        std::cout 
            << "Welcome to the humble magic town of Ignisgate.\n";


        std::cout
            << "What is your name young mage?\n";


        std::getline(std::cin, player.name);

        std::cout << "Well " << player.name << " I hope Ignisgate treats you well, I'd recommend taking a look at the Wizards Guild by typing /Navigate(Wizards_Guild). Good Luck out there!\n";


    }

    else
    {

        std::cout
            << "Welcome back to Ignisgate, young "
            << player.name
            << "\n";

    }

}

void Game::LocationNames(){
    std::cout 
        << "Dungeon\n"
        <<"Wizards_guild\n"
        <<"Magic_Academy\n"
        <<"Grand_Library\n"
        <<"Home\n";
}



void Game::TownCommands()
{

    std::cout
        << "\nWhat would you like to do now? (/Help for a list of options)\n";


    std::string command;

    std::getline(
        std::cin,
        command
    );


    if(command == "/Save")
    {

        saveManager.Save(player);

    }


    else if(command == "/Exit")
    {

        saveManager.Save(player);

        gameIsRunning = false;

    }

    else if(command == "/Help")
    {

        std::cout 
            << "/Save to save current state\n"
            << "/Menue to go back to the main menue\n"
            << "/Exit to close the game (auto saves)\n"
            << "/Navigate(location)\n"
            << "/locations for list of locations\n";
    
    }

    else if(command == "/Locations")
    {

        LocationNames();

    }

    else if(command == "/Navigate(Wizards_Guild)")
    {

        wizardGuild.Enter(player, dialogue);

    }

    else if(command == "/Navigate(Dungeon)")
    {

        dungeon.Enter(player, dialogue);

    }

    else if(command == "/Navigate(Home)")
    {

        home.Enter(player, dialogue);

    }

    else if(command == "/Menue")
    {

        Menu();

    }


}