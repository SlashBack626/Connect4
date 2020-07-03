//
// Created by Philip on 16.06.2020.
//

#ifndef INC_4WINS_GAME_H
#define INC_4WINS_GAME_H

#include <array>
#include <memory>
#include "Player.h"
#include "Board.h"

namespace connect4 {
    enum class WINNER {
        PLAYER1,
        PLAYER2,
        NONE
    };

    // Main class of the game
    class Game {
    private:
        bool started = false;
        bool finished = false;
        unsigned int round = 0;
        WINNER winner;
        std::array<std::reference_wrapper<Player>, 2> players;
        Board board;

    private:

        // main loop which will  last until the game is over
        void gameLoop();

        // user should select the column where he wants to put the chip
        void getUserInput(Player &p);

        // prints the winner of the game
        static void printWinner(WINNER winner);

        // prints the current round counter
        void printRound(CHIP player);

    public:
        Game(Player &p1, Player &p2);

        // can only be called once
        void start();
    };
}

#endif //INC_4WINS_GAME_H
