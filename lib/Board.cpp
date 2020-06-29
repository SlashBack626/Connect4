//
// Created by Philip on 29.06.2020.
//

#include <sstream>
#include <iostream>
#include "Board.h"
namespace connect4 {

    void Board::setStone(size_t column, STONE p) {
        auto &col = store[column];
        if (col.size() >= height) throw std::range_error("column not in range");
        col.push_back(p);
    }

    void Board::print() {
        std::stringstream ss;
        for (int row = height - 1; row >= 0; --row) {
            for (int col = 0; col < width; ++col) {
                ss << "|";
                if (row >= store[col].size()) ss << " ";
                else ss << ((store[col][row] == STONE::PLAYER1) ? "X" : "O");
            }
            ss << "|\n";
        }
        std::cout << ss.str();
    }

    const size_t Board::getHeight() {
        return height;
    }

    const size_t Board::getWidth() {
        return width;
    }

    bool Board::isValidMove(size_t col) const {
        return col >= 0 && col < width && store[col].size()+1 <= height;
    }
}