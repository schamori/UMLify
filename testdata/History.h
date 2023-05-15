//
// Created by Matthias on 27.02.2023.
//

#ifndef AUFGABE1_HISTORY_H
#define AUFGABE1_HISTORY_H

#include <iostream>
#include <string>
#include "Player.h"

class GameField;
class Player;

class History
{
public:
    History();
    void welcomeText();
    void printGameHistory(History* history, Player* player);
    void addRounds(History* history);
    int getRounds(History* history);
    void addGameHistory(std::string action, History* history);

private:
    int rounds;
    std::string gameHistory;
};

#endif //AUFGABE1_HISTORY_H
