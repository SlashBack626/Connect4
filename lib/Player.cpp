//
// Created by Philip on 29.06.2020.
//

#include "Player.h"
namespace connect4 {
    Player::Player(CHIP p) : chip(p) {}

    CHIP Player::getChip() const {
        return chip;
    }
}
