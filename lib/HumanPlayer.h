//
// Created by Philip on 29.06.2020.
//

#ifndef CONNECT4_HUMANPLAYER_H
#define CONNECT4_HUMANPLAYER_H

#include "Player.h"

namespace connect4 {
    class HumanPlayer : public Player {
    private:
        size_t getUserInput();

    public:
        explicit HumanPlayer(STONE p);

        size_t makeMove(const Board &b) override;
    };
}

#endif //CONNECT4_HUMANPLAYER_H
