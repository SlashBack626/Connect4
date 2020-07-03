//
// Created by Philip on 29.06.2020.
//

#ifndef CONNECT4_AIPLAYER_H
#define CONNECT4_AIPLAYER_H

#include "Player.h"
namespace connect4 {
    enum class BOT {
        BOT1,
        BOT2,
        BOT3,
        BOT4
    };

    class AIPlayer : public Player {
    private:
        BOT bot;

        static size_t algo1(const Board &b);

        static size_t algo2(const Board &b);

        size_t algo3(const Board &b);

        size_t algo4(const Board &b);

    public:
        explicit AIPlayer(CHIP p, BOT bot = BOT::BOT1);

        // selects one of the 4 predefined algorithms based on the bot property
        size_t makeMove(const Board &b) override;
    };
}

#endif //CONNECT4_AIPLAYER_H
