#include <iostream>
#include "headers/filereader.hpp"
#include "headers/parseboard.hpp"
#include "headers/board.hpp"

int main () {
  
  std::cout << "Hello world!\n";

  std::string data = minesweeperbot::filereader::readfile("./board.txt");

  minesweeperbot::board::Board* board = minesweeperbot::parseboard::parseboard(data);

  std::cout << "X: 0, Y: 1, V: " << board->getTile(0, 1)->getState() << '\n';

  return 0;
}


