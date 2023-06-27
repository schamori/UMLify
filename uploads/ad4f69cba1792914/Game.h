#ifndef GAME_H
#define GAME_H

#include "Ship.h"
#include <vector>

class Game
{
    public:
        Game();
        virtual ~Game();
        void play();

    protected:

    private:
        std::vector<Ship*> playerFleet;
        std::vector<Ship*> enemyFleet;

        void createFleet(std::vector<Ship*> &fleet);
        void printFleet(std::vector<Ship*> &fleet);
        bool isGameOver();
        void performRound();
        void playerTurn();
        void enemyTurn();
};

#endif // GAME_H
