//
// Created by Matthias on 28.02.2023.
//

#ifndef AUFGABE1_GAMEPLAY_H
#define AUFGABE1_GAMEPLAY_H

#include "Player.h"
#include "GameField.h"
#include "Enemy.h"
#include "History.h"

class Gameplay {
    public:
    Gameplay();
    void runEverything();
    void gamePlay(GameField* gamefield, Player* player, History* history, Enemy* enemy);

private:
    void error();
};


#endif //AUFGABE1_GAMEPLAY_H
