//
// Created by morit on 28.02.2023.
//


#ifndef UNTITLED5_PLAYER_H
#define UNTITLED5_PLAYER_H

# include "Cords.h"
enum dir{
    up, down, left_, right_
};
class Player
{
public:
    Player(int default_lives);
    bool move(int width, int height, enum dir);
    bool damage();
    bool heal();
    int find_relict();
    int get_x();
    int get_y();
    int get_lives();
private:
    int relicts;
    int lives;
    Cords cords;
};

#endif //UNTITLED5_PLAYER_H
