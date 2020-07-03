//
// Created by Philip on 29.06.2020.
//

#ifndef CONNECT4_PLAYER_H
#define CONNECT4_PLAYER_H
#include <cstdlib>
#include "CHIP.h"
#include "Board.h"

namespace connect4 {
    class Player {
    protected:
        CHIP chip;

    public:
        explicit Player(CHIP p);

        /// returns the chip (color) of the player
        CHIP getChip() const;

        /**
         * returns the decision where to put the chip based on the given Board
         *  0 <= returnValue < Board::getWidth()
         */
        virtual size_t makeMove(const Board &b) = 0;
    };
}

#endif //CONNECT4_PLAYER_H
