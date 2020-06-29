//
// Created by Philip on 29.06.2020.
//

#ifndef CONNECT4_PLAYER_H
#define CONNECT4_PLAYER_H
#include <cstdlib>
#include "STONE.h"
#include "Board.h"

namespace connect4 {
    class Player {
    protected:
        STONE stone;

    public:
        explicit Player(STONE p);

        STONE getStone() const;

        // return column
        virtual size_t makeMove(const Board &b) = 0;
    };
}

#endif //CONNECT4_PLAYER_H
