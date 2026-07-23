#include "Dialogue.h"

#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

#include "../../external/json.hpp"


using json = nlohmann::json;



Dialogue::Dialogue()
{
    player = nullptr;
}



void Dialogue::SetPlayer(
    Player* player
)
{
    this->player = player;
}





std::vector<DialogueLine> Dialogue::LoadDialogue(
    const std::string& id
)
{

    std::vector<DialogueLine> dialogue;


    std::string path =
        "assets/dialogue/" + id + ".json";


    std::ifstream file(path);


    if(!file.is_open())
    {

        std::cout
        << "[ERROR] Could not load dialogue: "
        << path
        << "\n";


        return dialogue;

    }



    json data;

    file >> data;



    for(auto& line : data["lines"])
    {

        DialogueLine dialogueLine;



        // Optional speaker
        if(line.contains("speaker"))
        {
            dialogueLine.speaker =
                line["speaker"];
        }



        // Optional style
        if(line.contains("style"))
        {
            dialogueLine.style =
                line["style"];
        }



        // Required text
        dialogueLine.text =
            line["text"];




        // Optional pause
        if(line.contains("pause"))
        {
            dialogueLine.pause =
                line["pause"];
        }



        // Optional spacing
        if(line.contains("spacing"))
        {
            dialogueLine.spacing =
                line["spacing"];
        }



        dialogue.push_back(dialogueLine);

    }



    return dialogue;

}





std::string Dialogue::ReplaceVariables(
    std::string text
)
{

    if(player == nullptr)
    {
        return text;
    }



    std::string variable =
        "{playerName}";



    size_t position =
        text.find(variable);



    if(position != std::string::npos)
    {

        text.replace(
            position,
            variable.length(),
            player->name
        );

    }



    return text;

}





void Dialogue::PrintLine(
    DialogueLine& line
)
{

    if(line.style == "italic")
    {
        std::cout << "\033[3m";
    }



    if(!line.speaker.empty())
    {

        std::cout
        << ReplaceVariables(line.speaker)
        << ":\n";

    }



    std::cout
    << ReplaceVariables(line.text)
    << "\n";



    if(line.style == "italic")
    {
        std::cout << "\033[23m";
    }



    if(line.spacing)
    {
        std::cout << "\n";
    }



    std::this_thread::sleep_for(
        std::chrono::seconds(line.pause)
    );

}





void Dialogue::Play(
    const std::string& id
)
{

    std::vector<DialogueLine> lines =
        LoadDialogue(id);



    for(DialogueLine& line : lines)
    {

        PrintLine(line);

    }

}