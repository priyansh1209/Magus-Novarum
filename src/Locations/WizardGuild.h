#pragma once

#include "Location.h"
#include "../Dialogue/Dialogue.h"


class WizardGuild : public Location
{

public:

    void Enter(Player& player, Dialogue& dialogue);

};