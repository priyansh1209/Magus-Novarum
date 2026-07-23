#pragma once

#include "../Player/Player.h"
#include "../Dialogue/Dialogue.h"


class Location
{

public:

    virtual void Enter(Player& player, Dialogue& dialogue) = 0;

};