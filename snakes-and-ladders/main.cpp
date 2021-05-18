#include <iostream>
#include <cstdlib>
#include <ctime>

#include "components.hpp"

int main(){
    srand(time(0));
    int BOARD_SIZE = 100;
    int PLAYERS = 5;
    Board game(BOARD_SIZE, PLAYERS);
    while(true){
        if(game.nextTurn())
            continue;
        break;
    }
}