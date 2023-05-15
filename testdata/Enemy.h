//
// Created by Matthias on 28.02.2023.
//

#ifndef AUFGABE1_ENEMY_H
#define AUFGABE1_ENEMY_H

#include "GameField.h"
#include "Player.h"
#include <iostream>

class History;
class GameField;
class Player;

class Enemy{
public:
    Enemy();
    void checkifKilled(char field[size][size], Enemy* enemy, Player* player);
    void moveEnemy(char field[size][size], Enemy* enemy, Player* player);
    int getEnemyX();
    int getEnemyY(Enemy* enemy);
    void setNext(Enemy* enemy, char field[size][size]);

private:
    int x;
    int y;
    char next;
};

#endif //AUFGABE1_ENEMY_H
