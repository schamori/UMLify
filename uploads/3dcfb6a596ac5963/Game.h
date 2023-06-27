//
// Created by morit on 28.02.2023.
//
#ifndef UNTITLED5_GAME_H
#define UNTITLED5_GAME_H

#include "Field.h"
#include "Player.h"



enum end{
    no_lives, all_relicts
};
class Game {
    public:
        Game(int width, int height, int lives);
        ~Game();
        enum dir get_input();
        void move(enum dir input);
        void render_field();
        bool process_Event();

    private:
        void expand_field();
        void end_game(enum end end_reason);
        Player player;
        Field* field;

};
/*

* @startuml

* Game --|> Player

* @enduml

*/
#endif //UNTITLED5_GAME_H
