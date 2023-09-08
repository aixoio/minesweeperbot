
#ifndef BOARD_HPP_
#define BOARD_HPP_

#include <string>
namespace minesweeperbot {
  
  namespace board {
    
    class Tile {
      private:
        unsigned char state;
      public:
        Tile(unsigned char state);
        Tile();
        unsigned char getState() const;
        void setState(unsigned char state);
    };

    class Board {
      
      private:
        unsigned int tilesRows;
        unsigned int tilesCols;
        minesweeperbot::board::Tile** tiles;
        bool wasCreated;
      
      public:
        Board();
        ~Board();
        unsigned int getTileRows() const;
        unsigned int getTileCols() const;
        bool isWasCreated() const;
        minesweeperbot::board::Tile** getTiles() const;
        minesweeperbot::board::Tile* getTile(unsigned int x, unsigned int y) const;
        void setTile(minesweeperbot::board::Tile* tile, unsigned int x, unsigned int y);
        void create(unsigned int rows, unsigned int cols);
        
    };

  }

}

#endif // !BOARD_HPP_

