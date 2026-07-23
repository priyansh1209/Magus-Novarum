#pragma once

#include "Location.h"
#include "../Dialogue/Dialogue.h"


class Dungeon : public Location
{

public:

    void Enter(Player& player, Dialogue& dialogue) override;

};