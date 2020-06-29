#include <iostream>
#include "Game.h"
#include "HumanPlayer.h"

int main() {
    connect4::HumanPlayer p1(STONE::PLAYER1);
    connect4::HumanPlayer p2(STONE::PLAYER2);
    connect4::Game game(p1, p2);
    game.start();
//    connect4::Board b;
//    b.print();
//    std::cout << "\n";
//    b.setStone(0, STONE::PLAYER1);
//    b.setStone(0, STONE::PLAYER1);
//    b.setStone(0, STONE::PLAYER2);
//    b.setStone(1, STONE::PLAYER2);
//    b.setStone(1, STONE::PLAYER1);
//    std::system("clear");
//    b.print();
//    std::cout << p1.makeMove(b) << std::endl;
    return 0;
}
