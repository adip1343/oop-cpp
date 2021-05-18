#include <vector>

class Dice{

    public :
        int shuffle();  // gives result of shuffling of dice

};

class Player{

    private :
        int position;   // position player starts with 1
        int id;         // unique ID of player

    public :
        friend class Board;             // needs to access ID
        Player(int i);      
        void moveTo(int newPosition);   // moves to new position
        int getPosition();              // gives position

};

class Board{

    private :
        int size_of_table;      
        int number_of_players;
        int current_player;
        Dice dice;
        int destination;                    // size_of_table**2
        std :: vector <int> jump_table;     // jump table to simlate snakes and ladders
        std :: vector <Player> players;     // vector on currently playing players
        std :: vector <Player> winners;     // vector of finished players

    public :
        Board(int n, int m);                    
        Board() : Board(10, 2){};           // defalt 10*10 grid with 2 players
        bool nextTurn();                    // performs next turn returns false on ending game
        void printLeaderboard();            // prints leaderboard of the game

};
