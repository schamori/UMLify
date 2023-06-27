#include "Game.h"
#include <string>
#define WIDTH 5
#define HEIGHT 5
#define LIVES 5


int main() {
    srand((unsigned) time(NULL));
    Game game(WIDTH, HEIGHT, LIVES);
    while(game.process_Event()){
        game.render_field();
        enum dir input = game.get_input();
        game.move(input);
    }
    return 0;
}
