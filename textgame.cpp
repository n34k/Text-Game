#include <iostream>
using namespace std;
#include <stdlib.h>
#include <time.h>
#include <cstdlib>  
#include <cctype>
int main() {
    srand(time(0));
    int strength = rand() % 15 + 3;
    int intelligence = rand() % 15 + 3;
    int dex = rand() % 15 + 3;
    int charisma = rand() % 15 + 3;
    int maxHealth = rand() % 6 + 3;
    int currentHealth = maxHealth;
    int failCount = 0;
    string endIn;
    string startCin;
    string secondCin;
    cout << "Type \"Begin\" to start or anything else to quit." << endl;
    cin >> startCin;
    for (int i = 0; i < startCin.length(); i++) {
        startCin[i] = tolower(startCin[i]);
    }
   
    if (startCin == "begin") {
        cout << "Stats:" << endl << "Strength: " << strength << endl << "Intelligence: " << intelligence << endl << "Dexterity: " << dex << endl << "Charisma: " << charisma << endl << "Current Health: " << currentHealth << endl << endl;
        cout << "You are standing in front of the gate to a large mysterious mansion." << endl << "The gate\'s rusted lock seems ready to fall off." << endl << "Maybe if you bashed the gate hard enough, you could get through it." << endl << "Or, you could try to climb over the gate. Would you like to CLIMB or BASH the gate?" << endl << endl;
    }
    else {
        cout << "Finish" << endl;
    }
    while (failCount < 3) {
        cin >> secondCin;
       for (int i = 0; i < secondCin.length(); i++) {
        secondCin[i] = tolower(secondCin[i]);
    }
    if (secondCin == "climb") {
        int climbDex = rand() % 20 + 1;
        failCount = failCount + 3;
        cout << "You rolled a " << climbDex << " against a Dex of " << dex << "." << endl;
        if(dex >= climbDex) {
            cout << "Success." << endl << endl << "You carefully climb over the old rusted gate. You land safely on your feet inside the grounds of the mysterious mansion." << endl;
        }
        else {
            int climbDamage = rand() % 4 + 1;
            cout << "Fail." << endl << endl << "As you make your way over the rusted gate, the finial you are using for support snaps and you land hard on the ground below. You take " << climbDamage << " damage and are a little shaken. Nevertheless, you have made it inside the grounds of the mysterious mansion." << endl;
            currentHealth = maxHealth - climbDamage;
            cout << "Current Health: " << currentHealth << endl << endl;
        } 
    }
    else if (secondCin == "bash") {
        int bashStr = rand() % 20 + 1;
        failCount = failCount + 3;
        cout << "You rolled a " << bashStr << " against a Str of " << strength << "." << endl;
        if(strength >= bashStr) {
            cout << "Success." << endl << "You put all your weight into a massive assault on the gate. As you suspected, the lock was not up to the challenge and gave way easily.You hear a large thud as the gate crashes open. You have made it inside the grounds of the mysterious mansion." << endl << endl;
        }
        else {
            int bashDamage = rand() % 4 + 1;
            cout << "Fail." << endl << "You put all your weight into a massive assault on the gate. At first, the lock resists your attack, and the collision with the gate bites into your shoulder. You take " << bashDamage << " damage. After a moment's hesitation, the lock gives, and the gate swings open with a thud. You have made it inside the grounds of the mysterious mansion." << endl << endl;
            currentHealth = maxHealth - bashDamage;
            cout << "Current Health: " << currentHealth << endl << endl;
        }
    }
    else {
        failCount ++;
        cout << "Attempt: " << failCount << endl << "I'm sorry I did not understand that response. Please try again." << endl;
        if (failCount >= 3) {
            cout << "Finish" << endl;
            cin >> endIn;
        }
    }
    }
    cout << "Finish" << endl << endl << "Thank you for playing our demo. We hope you have enjoyed it." << endl;
    cin >> endIn;
}  
