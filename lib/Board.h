//
// Created by Philip on 29.06.2020.
//

#ifndef CONNECT4_BOARD_H
#define CONNECT4_BOARD_H

#include <array>
#include <vector>
#include "STONE.h"

namespace connect4 {
    class Board {
    private:
        const static size_t height = 6;
        const static size_t width = 7;
    public:
        static const size_t getHeight();

        static const size_t getWidth();

    private:
        std::array<std::vector<STONE>, width> store;

    public:
        void print();

        void setStone(size_t column, STONE p);

        bool isValidMove(size_t col) const;
    };
}

#endif //CONNECT4_BOARD_H
