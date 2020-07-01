//
// Created by Philip on 29.06.2020.
//

#include "AIPlayer.h"

namespace connect4 {
    size_t AIPlayer::makeMove(const Board &b) {
        switch (bot) {
            case BOT::BOT1:
                return algo1(b);
            case BOT::BOT2:
                return algo2(b);
            case BOT::BOT3:
                return algo3(b);
            case BOT::BOT4:
                return algo4(b);
        }
    }

    AIPlayer::AIPlayer(STONE p, BOT bot) : Player(p), bot(bot) {}

    size_t AIPlayer::algo1(const Board &b) {
        return 0;
    }

    size_t AIPlayer::algo2(const Board &b) {
        for (int col = 0; col < Board::getWidth(); ++col) {
            if(b.isValidMove(col)) return col;
        }
        throw std::logic_error("cannot make a move");
    }

    size_t AIPlayer::algo3(const Board &b) {
        return 0;
    }

    size_t AIPlayer::algo4(const Board &b) {
        return 0;
    }
}
