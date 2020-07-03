//
// Created by Philip on 16.06.2020.
//

#include "Game.h"
#include <iostream>

using std::cout;
using std::endl;

connect4::Game::Game(Player &p1, Player &p2) : players({p1, p2}), winner(WINNER::NONE) {}

void connect4::Game::start() {
    if (started) throw "Can only be called once";
    started = true;
    gameLoop();
}

void connect4::Game::gameLoop() {
    CHIP player = CHIP::PLAYER1;
    while (!finished) {
        if (player == CHIP::PLAYER1) round++;
        std::system("clear");
        printRound(player);
        board.print();
        getUserInput(players[(player == CHIP::PLAYER1) ? 0 : 1]);
        finished = board.matchEnded();
        if(finished) winner = (player == CHIP::PLAYER1) ? WINNER::PLAYER1 : WINNER::PLAYER2;
        player = (player == CHIP::PLAYER1) ? CHIP::PLAYER2 : CHIP::PLAYER1;
    }
    std::system("clear");
    board.print();
    printWinner(winner);
}

void connect4::Game::printWinner(WINNER winner) {
    switch (winner) {
        case WINNER::PLAYER1:
            cout << "Player 1 wins!" << endl;
            break;
        case WINNER::PLAYER2:
            cout << "Player 2 wins" << endl;
            break;
        default:
            cout << "Match was a draw" << endl;
    }
}

void connect4::Game::printRound(CHIP player) {
    std::cout << "Round: " << round << "\n"
              << ((player == CHIP::PLAYER1) ? "Player1" : "Player2") << "'s turn!" << std::endl;
}

void connect4::Game::getUserInput(Player &p) {
    board.putChip(p.makeMove(board), p.getChip());
}
