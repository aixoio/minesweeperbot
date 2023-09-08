#include "headers/parseboard.hpp"
#include "headers/board.hpp"
#include <iostream>
#include <sstream>
#include <vector>

minesweeperbot::board::Board* minesweeperbot::parseboard::parseboard(std::string data) {

  std::istringstream iss(data);
  std::string line;
  std::vector<std::vector<unsigned char> > tileStates;

  while (std::getline(iss, line)) {
    std::vector<unsigned char> row;
    std::istringstream lineStream(line);
    unsigned char tileState;

    while (lineStream >> tileState) {
      row.push_back(tileState);
    }

    tileStates.push_back(row);
  }

  minesweeperbot::board::Board* board = new minesweeperbot::board::Board();
  unsigned int numRows = tileStates.size();
  unsigned int numCols = (numRows > 0) ? tileStates[0].size() : 0;

  board->create(numRows, numCols);

  for (unsigned int i = 0; i < numRows; ++i) {
    for (unsigned int j = 0; j < numCols; ++j) {
      unsigned char tileState = tileStates[i][j];
      minesweeperbot::board::Tile* tile = new minesweeperbot::board::Tile(tileState);
      board->setTile(tile, i, j);
    }
  }

  return board;

}

