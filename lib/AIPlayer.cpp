//
// Created by Philip on 29.06.2020.
//

#include "AIPlayer.h"
#include <random>

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

    AIPlayer::AIPlayer(CHIP p, BOT bot) : Player(p), bot(bot) {}

    // randomly selects a column
    size_t AIPlayer::algo1(const Board &b) {
        std::random_device rd;
        std::default_random_engine re(rd());
        std::uniform_int_distribution<int> dist(0, Board::getWidth());
        size_t output;
        do {
            output = dist(re);
        } while (!b.isValidMove(output));
        return output;
    }

    // always puts chip in left most column
    size_t AIPlayer::algo2(const Board &b) {
        for (int col = 0; col < Board::getWidth(); ++col) {
            if(b.isValidMove(col)) return col;
        }
        throw std::logic_error("cannot make a move");
    }

    // always selects column with the least stones
    size_t AIPlayer::algo3(const Board &b) {
        size_t maxSize = Board::getHeight();
        size_t selection = 0;
        for (int col = 0; col < Board::getWidth(); ++col) {
            auto &column = b.getColumn(col);
            if (column.size() < maxSize) {
                selection = col;
                maxSize = column.size();
            }
        }
        if(!b.isValidMove(selection)) throw std::logic_error("cannot make move");
        return selection;
    }

    // wins in at least 85% of all games
    size_t AIPlayer::algo4(const Board &b) {
        return 0;
    }
}
