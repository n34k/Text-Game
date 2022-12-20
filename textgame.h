#ifndef TEXTGAME_H
#define TEXTGAME_H
#include <string>
#include <vector>
using namespace std;

class Option {
    public:
       void SetOptionKeyword(string optionKeyword);
       void SetStat(string stat);
       void SetPassText(string passText);
       void SetFailText(string failText);
       void SetPexit(int pexit);
       void SetFexit(int fexit);
       void SetFailDamage(string failDamage);
       string GetOptionKeyword();
       string GetStat();
       string GetPassText();
       string GetFailText();
       int GetPexit();
       int GetFexit();
       string GetFailDamage();
       Option();
       Option(string optionKeyword, string stat, string passText, int pexit, int fexit, string failText, string failDamage);
    private:
        string optionKeyword;
        string stat;
        int fexit;
        int pexit;
        string passText;
        string failText;
        string failDamage;
};

class Room {
    public:
        void SetRoomNumber(int roomNumber);
        void SetDescription(string description);
        int GetRoomNumber();
        string GetDescription();
        vector<Option> GetOptions();
        Option* GetLastOption();
        void AddOption(Option option);
        Room();
        Room(int roomNumber, string description);
    private:
        int roomNumber;
        string description;
        vector<Option> optionList;
};

class World {
    public:
        void SetCurrentRoom(int index);
        Room GetCurrentRoom();
        Room* GetLastRoom();
        void AddRoom(Room room);
        void Play();
        World();
    private:
        vector<Room> roomList;
        Room currentRoom;
};

#endif