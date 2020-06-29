//
// Created by Philip on 29.06.2020.
//

#include <iostream>
#include <limits>
#include "HumanPlayer.h"

namespace connect4 {
    size_t HumanPlayer::makeMove(const Board &b) {
        char c;
        while (true) {
            std::cout << "Enter column: ";
            std::cin >> c;
            if (std::isdigit(c) && b.isValidMove(std::strtol(&c, nullptr, 10)-1)) break;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "invalid input" << std::endl;
        }
        return std::strtol(&c, nullptr, 10);
    }

    HumanPlayer::HumanPlayer(STONE p) : Player(p) {}
}
