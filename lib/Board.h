//
// Created by Philip on 29.06.2020.
//

#ifndef CONNECT4_BOARD_H
#define CONNECT4_BOARD_H

#include <array>
#include <vector>
#include "CHIP.h"

namespace connect4 {
    /// represents the board
    class Board {
    private:
        const static size_t height = 6;
        const static size_t width = 7;
    public:
        static const size_t getHeight();

        static const size_t getWidth();

    private:
        std::array<std::vector<CHIP>, width> store;

        bool columnConnects4(size_t col);
        bool rowConnects4(size_t row);

    public:
        /// prints the board to stdout in a human readable way
        void print();

        /**
         * will put a chip in the given column
         * throws an error if the column is already full
         */
        void putChip(size_t column, CHIP p);

        /**
         * checks if it is valid to put a chip into the given column
         */
        bool isValidMove(size_t col) const;

        /**
         * checks if the match has ended (either by players winning or draw)
         */
        bool matchEnded();

        /**
         * returns the vector for a given column
         */
        const std::vector<CHIP>& getColumn(size_t col) const;
    };
}

#endif //CONNECT4_BOARD_H
