#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>  
#include <cctype>
#include <string>
#include <fstream>
#include "textgame.h"
using namespace std;


int main() {
    World world;
    ifstream inFS;
    string fileText;
    int fileInt;
    inFS.open("rooms.txt");
    if (!inFS.is_open()) {
      cout << "Could not open file numFile.txt." << endl;
      return 1;
   }
    while (!inFS.eof()) {
        inFS >> fileText;
        if (fileText == "Room:") {
            Room room;
            world.AddRoom(room);
            inFS >> fileInt;
            room.SetRoomNumber(fileInt);
        }
        else if (fileText == "Desc:") {
            Room* room = world.GetLastRoom();
            getline(inFS, fileText);
            room->SetDescription(fileText);
        }
        else if (fileText == "Option:") {
            Room* room = world.GetLastRoom();
            Option option;
            inFS >> fileText;
            option.SetOptionKeyword(fileText);
            room->AddOption(option);
        }
        else if (fileText == "Stat:") {
            Room* room = world.GetLastRoom();
            Option* option = room->GetLastOption();
            inFS >> fileText;
            option->SetStat(fileText);
        }
        else if (fileText == "Pass:") {
            Room* room = world.GetLastRoom();
            Option* option = room->GetLastOption();
            getline(inFS, fileText);
            option->SetPassText(fileText);
        }
        else if (fileText == "Pexit:") {
            Room* room = world.GetLastRoom();
            Option* option = room->GetLastOption();
            inFS >> fileInt;
            option->SetPexit(fileInt);
        }
        else if (fileText == "Fail:") {
            Room* room = world.GetLastRoom();
            Option* option = room->GetLastOption();
            getline(inFS, fileText);
            option->SetFailText(fileText);
        }
        else if (fileText == "Fexit:") {
            Room* room = world.GetLastRoom();
            Option* option = room->GetLastOption();
            inFS >> fileInt;
            option->SetFexit(fileInt);
        }
        else if (fileText == "Damage:") {
            Room* room = world.GetLastRoom();
            Option* option = room->GetLastOption();
            inFS >> fileText;
            option->SetFailDamage(fileText);
        }
    }
    inFS.close();
    string userInput;
    cout << "Type \"Begin\" to start or anything else to quit." << endl;
    cin >> userInput;
    for (int i = 0; i < userInput.length(); i++) {
        userInput[i] = tolower(userInput[i]);
    }
    if (userInput == "begin") {
        world.Play();
    }
    else {
            cout << "Finish" << endl;
        }
    return 0;
}