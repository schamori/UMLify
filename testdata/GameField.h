//
// Created by Matthias on 28.02.2023.
//

#ifndef AUFGABE1_GAMEFIELD_H
#define AUFGABE1_GAMEFIELD_H
#include <iostream>
#include "Player.h"
#include <stdlib.h>
#define size 5

class History;
class Player;

class GameField
{
public:
    GameField();
    void printField(char field[size][size], Player* player);
    void fillField(char field[size][size], Player* player);
    char field[size][size];
};

#endif //AUFGABE1_GAMEFIELD_H
