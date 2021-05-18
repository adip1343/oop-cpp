#include <iostream>
#include <vector>
#include <cstdlib>

#include "components.hpp"

Board :: Board(int n, int m) {
    
    size_of_table = std::max(n, 10);
    number_of_players = std::max(m,2);
    destination = n*n;
    jump_table.resize(destination+1);
    current_player = 0;
    
    for(int i=1; i<=destination; i++){
        jump_table[i] = i;
    }

    // creating randomized jump table to simulate snakes and ladders
    for(int i=1; i<size_of_table; i++){
        while(true) {
            int src = rand()%100 + 1;
            int dest = rand()%100 +1;
            if(!( src==1 || src==destination || dest == destination || dest == src) 
                && jump_table[dest]==dest && jump_table[src]==src){
                jump_table[src] = dest;
                break;
            }
        }
    }

    // vector of players still not finished
    for(int i=1; i<=number_of_players; i++){
        players.push_back(Player(i));
    }
}

bool Board :: nextTurn(){

    // If only one player remaining then end the game
    if(players.size() == 1){
        winners.push_back(players[current_player]);
        printLeaderboard();
        return false;
    }

    int move = dice.shuffle();
    int current_position = players[current_player].getPosition();

    // If we can move then move
    if(current_position+move <= destination){
        players[current_player].moveTo(jump_table[current_position+move]);
    }

    // If player reaches destination stop
    if(players[current_player].getPosition() == destination){
        winners.push_back(players[current_player]);
        players.erase(players.begin()+current_player);
        current_player = current_player % players.size();
        return true;
    }

    bool perfect_move = (move == 6);
    
    // If perfect move then same player continues otherwise next player
    if(!perfect_move)
        current_player = (current_player+1) % players.size();
    
    return true;
}

void Board :: printLeaderboard(){
    std :: cout << "Pos\tId\n";
    int i = 1;
    for(Player p : winners){
        std::cout << i << "\t" <<p.id << std:: endl;
        i++; 
    }
}