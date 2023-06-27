//
// Created by morit on 28.02.2023.
//

#include <iostream>
#include <string>
#include <stdexcept>
#include "Game.h"


using namespace std;

Game::Game(int width, int height, int lives): player(lives){
    field = new Field(height, width);
}

Game::~Game() {
    delete field;
}

void Game::render_field() {
    for(int i = 0; i < field->get_height(); i++){
        for(int j = 0; j < field->get_width(); j++) {
            if  (player.get_x() == j && player.get_y() == i){
                cout << " Y ";
            } else if (field->get_array()[j][i] == empty){
                cout << " E ";
            } else if (field->get_array()[j][i] == relict){
                cout << " R ";
            } else if (field->get_array()[j][i] == danger){
                cout << " D ";
            } else if (field->get_array()[j][i] == heal ){
                cout << " H ";
            }
        }
        cout << endl;
    }
}

enum dir Game::get_input() {
    cout << "Choose your next action with w a s d" << endl;
    char input;
    cin >> input;
    while(input != 'w' && input != 's' && input != 'a' && input != 'd'){
        cout << "Invalid Try again to choose your next action with w a s d" << endl;
        cin >> input;
    }

    switch (input) {
        case 'w':
            return up;
        case 's':
            return down;
        case 'a':
            return left_;
        case 'd':
            return right_;
    }
    // Cant compile without it for some reason. Reaches end of void

    throw invalid_argument("Invalid User input")
}

void Game::expand_field() {
    int width = field->get_width() + 1;
    int height = field->get_height() + 1;
    delete field;
    field = new Field(width, height);

}

bool Game::process_Event() {
    switch (field->get_array()[player.get_x()][player.get_y()]) {
        case empty:
            field->get_array()[player.get_x()][player.get_y()] = empty;
            cout << "This field is empty" << endl;
            return true;
        case danger:
            field->get_array()[player.get_x()][player.get_y()] = empty;
            if (rand() % 6 + 1 == 6) {
                cout << "Oh no! You have hurt yourself and lost 1 live. You are down to " << player.get_lives()
                     << " live/s" << endl;
                if (!player.damage()){
                    end_game(no_lives);
                    return false;
                } else {
                    return true;
                }
            } else {
                cout << "Congrats! You escaped danger" << endl;
                return true;
            }


        case heal:
            field->get_array()[player.get_x()][player.get_y()] = empty;
            cout << "You found healing and are lives are going to the moon:  " << player.get_lives() << " live/s"
                 << endl;
            return player.heal();
        case relict:
            field->get_array()[player.get_x()][player.get_y()] = empty;
            int relicts = player.find_relict();
            cout << "You found a valuable relict. You now have " << relicts << " relict/s" << endl;
            if (relicts == field->get_relicts()){
                cout << "You found all relicts. The board will be reset" << endl;
                expand_field();
            }
            return true;
    }
    // Cant compile without it for some reason. Reaches end of void
    return true;

}


void Game::end_game(enum end end_reason) {
    switch (end_reason) {
        case no_lives:
            cout << "You lost because you are out of lives";

    }
}


void Game::move(enum dir input) {
    while (!player.move(field->get_width(), field->get_height(), input)){
        cout << "You can't got here. Try again" << endl;
        input = get_input();
    }
}





