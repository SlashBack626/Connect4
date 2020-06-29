//
// Created by Philip on 29.06.2020.
//

#include "Player.h"
namespace connect4 {
    Player::Player(STONE p) : stone(p) {}

    STONE Player::getStone() const {
        return stone;
    }
}
