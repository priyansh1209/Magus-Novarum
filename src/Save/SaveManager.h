#pragma once

#include <string>

#include "../Player/Player.h"


class SaveManager
{

private:

    std::string savePath = "save.json";


public:

    void Save(
        Player& player
    );


    bool Load(
        Player& player
    );


    void DeleteSave();

};