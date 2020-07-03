cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 14)

add_library(GameLib empty.cpp Game.cpp Game.h Board.cpp Board.h CHIP.h Player.cpp Player.h HumanPlayer.cpp HumanPlayer.h AIPlayer.cpp AIPlayer.h)