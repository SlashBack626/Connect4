//
// Created by Philip on 29.06.2020.
//

#include <iostream>
#include <sstream>
#include <limits>
#include "HumanPlayer.h"

namespace connect4 {
    size_t HumanPlayer::makeMove(const Board &b) {
        size_t input;
        std::string line;
        bool valid;
        while (true) {
            std::cout << "Enter column: ";
            std::getline(std::cin, line);
            std::stringstream ss(line);
            ss >> input;
            valid = !ss.fail() && ss.eof();
            if (valid && input > 0 && input <= Board::getWidth()) break;
            std::cout << "Invalid input" << std::endl;
        }
        return input-1;
    }

    HumanPlayer::HumanPlayer(STONE p) : Player(p) {}
}
