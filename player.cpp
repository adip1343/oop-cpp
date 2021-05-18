#include "components.hpp"

Player :: Player(int i){
    position = 1;
    id = i;
}

int Player :: getPosition(){
    return position;
}

void Player :: moveTo(int newPosition){
    position = newPosition;
}