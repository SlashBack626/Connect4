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
        ss << " 1 2 3 4 5 6 7\n";
        for (int row = height - 1; row >= 0; --row) {
            for (int col = 0; col < width; ++col) {
                ss << "|";
                if (row >= store[col].size()) ss << " ";
                else ss << ((store[col][row] == STONE::PLAYER1) ? "X" : "O");
            }
            ss << "|\n";
        }
        ss << " 1 2 3 4 5 6 7\n";
        std::cout << ss.str();
    }

    const size_t Board::getHeight() {
        return height;
    }

    const size_t Board::getWidth() {
        return width;
    }

    bool Board::isValidMove(size_t col) const {
        return col >= 0 && col < width && store[col].size() + 1 <= height;
    }

    bool Board::matchEnded() {
        for (int col = 0; col < width; ++col) {
            if (columnConnects4(col)) return true;
        }
        for (int row = 0; row < height; ++row) {
            if (rowConnects4(row)) return true;
        }
        return false;
    }

    bool Board::columnConnects4(size_t column) {
        auto col = store[column];
        if (col.size() < 4) return false;
        size_t sequence = 0;
        STONE lastStone = STONE::PLAYER1;
        for (auto &s : col) {
            if (s != lastStone) {
                lastStone = s;
                sequence = 1;
            } else {
                sequence++;
                if (sequence >= 4) return true;
            }
        }
        return false;
    }

    bool Board::rowConnects4(size_t row) {
        size_t sequence = 0;
        STONE lastStone = STONE::PLAYER1;
        for (int col = 0; col < width; ++col) {
            auto &column = store[col];
            if(row >= column.size()){
                sequence = 0;
            }
            else if (column[row] == lastStone) {
                sequence++;
                if(sequence >= 4) return true;
            } else {
                lastStone = column[row];
                sequence = 1;
            }
        }
        return false;
    }

    const std::vector<STONE> &Board::getColumn(size_t col) const {
        if(col > width) throw std::range_error("out of range");
        return store[col];
    }
}
