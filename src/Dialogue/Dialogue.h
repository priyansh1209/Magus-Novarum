#pragma once

#include <string>
#include <vector>

#include "../Player/Player.h"
#include "DialogueData.h"


class Dialogue
{

private:

    Player* player;


    std::vector<DialogueLine> LoadDialogue(
        const std::string& id
    );


    void PrintLine(
        DialogueLine& line
    );


    std::string ReplaceVariables(
        std::string text
    );


public:

    Dialogue();


    void SetPlayer(
        Player* player
    );


    void Play(
        const std::string& id
    );

};