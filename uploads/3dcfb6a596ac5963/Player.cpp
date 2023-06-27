//
// Created by morit on 28.02.2023.
//

#include "Player.h"

Player::Player(int default_lives) {
    lives = default_lives;
    relicts = 0;
}

int Player::get_lives() {
    return lives;
}



int Player::get_x()  {
    return cords.x;
}

int Player::get_y() {
    return cords.y;
}

bool Player::damage() {
    lives--;
    return lives != 0;
}

bool Player::heal() {
    lives++;
    return true;
}

bool Player::move(int width, int height, enum dir dir) {
    switch (dir){
        case up:
            if (cords.y - 1 < 0){
                return false;
            }
            else{
                cords.y--;
                return true;
            }
        case down:
            if (cords.y + 1 > height - 1){
                return false;
            }
            else{
                cords.y++;
                return true;
            }
        case left_:
            if (cords.x - 1 < 0){
                return false;
            }
            else{
                cords.x--;
                return true;
            }
        case right_:
            if (cords.x + 1 > width - 1){
                return false;
            }
            else{
                cords.x++;
                return true;
            }
    }
}
int Player::find_relict() {
    relicts++;
    return relicts;
}

