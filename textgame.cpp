#include "textgame.h"
#include <iostream>
#include <string>
using namespace std;

//World functions

void World::AddRoom(Room room) {
    roomList.push_back(room);
}
void World::SetCurrentRoom(int index) {
    this->currentRoom = roomsList.at(index);
}
void World::Play(int currentHealth) {
    string userInput;
    while(currentHealth > 0) {
        cout << currentRoom.GetDescription() << endl;
        cin >> userInput;
        bool valid = false;
        Option t; 
        while(!valid) {
            for (Option o : currentRoom.GetOptions()) {
                if (o.GetOptionKeyword() == userInput) {
                    valid = true;
                    t = o;
                }
                else {
                    cout << "Invalid input, try again" << endl;
                    cin >> userInput;
                }
            }
        }
        int roll = rand() % 6 + 1;
        bool pass = stat > roll;

        if(pass) {
            this->SetCurrentRoom(t.pexit);
        }
        else {
            this->SetCurrentRoom(t.fexit);
        }   
    }
    
    

}

//Room functions

Room::Room() {
    roomNumber = -1;
    description = "";
}
Room::Room(int roomNumber, string description) {
    this->roomNumber = roomNumber;
    this->description = description;
}
Room* Room::GetLast() {
    return &roomList.at(roomList.size() - 1);
}
void Room::SetRoomNumber(int roomNumber) {
    this->roomNumber = roomNumber;
}
void Room::SetDescription(string description) {
    this->description = description;
}
void Room::GetRoomNumber() {
    return roomNumber;
}
void Room::GetDescription() {
    return description;
}
void Room::AddOption(Option option) {
    optionsList.push_back(option);
}
vector<Option> GetOptions() {
    return optionsList;
}
//Option functions

Option::Option() {
    optionKeyword = "";
    stat = "";
    fexit = -1;
    pexit = -1;
    passText = "";
    failText = "";
    failDamage = "";
}
Option::Option(string optionKeyword, string stat, string passText, int pexit, int fexit, string failText, string failDamage) {
    this->optionKeyword = optionKeyword;
    this->stat = stat; 
    this->passText = passText;
    this->pexit = pexit;
    this->fexit = fexit;
    this->failText = failText;
    this->failDamage = failDamage;
}
void Option::SetOptionKeyword(string optionKeyword) {
    this->optionKeyword = optionKeyword;
}
void Option::SetStat(string stat) {
    this->stat = stat; 
}
void Option::SetPassText(string passText) {
    this->passText = passText;
}
void Option::SetPexit(int pexit) {
    this->pexit = pexit;
}
void Option::SetFexit(int fexit) {
    this->fexit = fexit;
}
void Option::SetFailText(string failText) {
    this->failText = failText;
}
void Option::SetFailDamage(string failDamage) {
    this->failDamage = failDamage;
}
void Option::GetOptionKeyword() {
    return optionKeyword;
}
void Option::GetStat() {
    return stat;
}
void Option::GetPassText() {
    return passText;
}
void Option::GetPexit() {
    return pexit;
}
void Option::GetFexit() {
    return fexit;
}
void Option::GetFailText() {
    return failText;
}
void Option::GetFailDamage() {
    return failDamage;
}