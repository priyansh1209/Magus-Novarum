#pragma once

#include <string>


struct DialogueLine
{

    std::string speaker = "";

    std::string text = "";

    std::string style = "";

    int pause = 3;

    bool spacing = true;


};