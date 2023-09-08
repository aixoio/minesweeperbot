#include "headers/board.hpp"

minesweeperbot::board::Tile::Tile(unsigned char state) : state(state) {}
minesweeperbot::board::Tile::Tile() : state('N') {};

unsigned char minesweeperbot::board::Tile::getState() const {
  return this->state;
}

void minesweeperbot::board::Tile::setState(unsigned char state) {
  this->state = state;
}

minesweeperbot::board::Board::Board() {
  this->wasCreated = false;
  this->tilesRows = 0;
  this->tilesCols = 0;
}

minesweeperbot::board::Board::~Board() {
  if (this->wasCreated) {
    for (unsigned int i = 0; i < this->tilesRows; i++) {
      delete[] this->tiles[i];
    }
    delete[] this->tiles;
  }
}

unsigned int minesweeperbot::board::Board::getTileCols() const {
  return this->tilesCols;
}

unsigned int minesweeperbot::board::Board::getTileRows() const {
  return this->tilesRows;
}

minesweeperbot::board::Tile** minesweeperbot::board::Board::getTiles() const {
  return this->tiles;
}

minesweeperbot::board::Tile* minesweeperbot::board::Board::getTile(unsigned int x, unsigned int y) const {
  
  if (x < this->tilesRows && y < this->tilesCols) {
    return &this->tiles[x][y];
  }

  return nullptr;

}

void minesweeperbot::board::Board::setTile(minesweeperbot::board::Tile* tile, unsigned int x, unsigned int y) {
  if (x < this->tilesRows && y < this->tilesCols) {
    this->tiles[x][y] = *tile;
  }
}

bool minesweeperbot::board::Board::isWasCreated() const {
  return this->wasCreated;
}

void minesweeperbot::board::Board::create(unsigned int rows, unsigned int cols) {

  if (this->wasCreated) {
    for (unsigned int i = 0; i < this->tilesRows; i++) {
      delete[] this->tiles[i];
    }
    delete[] this->tiles;
  }

  this->tilesRows = rows;
  this->tilesCols = cols;

  this->tiles = new minesweeperbot::board::Tile*[rows];

  for (unsigned int i = 0; i < rows; i++) {
    this->tiles[i] = new minesweeperbot::board::Tile[cols];
  }

  this->wasCreated = true;


}

