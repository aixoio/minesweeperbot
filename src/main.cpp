#include <iostream>
#include "headers/filereader.hpp"

int main () {
  
  std::cout << "Hello world!\n";

  std::string data = minesweeperbot::filereader::readfile("./board.txt");

  std::cout << data;


  return 0;
}


