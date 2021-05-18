#include <cstdlib>
#include <ctime>

#include "components.hpp"

int Dice :: shuffle(){
    return 1 + rand()%6;
}