//
// Created by Gabby Barcinas on 5/13/21.
//
#ifndef BATTLESHIPMASTER_BOARD_H
#include <vector>
#include <string>
#include <map>
#include "GameFormat.h"
#include "Ship.h"

namespace BattleShip {
    class Board {
    public:
        Board(int numRows, int numCols);
        std::vector<std::string> getBoard();

        // display the boards
        void displayFiringBoard() const;
        void displayPlacementBoard() const;

        // check places on the boardContents
        const char &at(int row, int col) const;
        char &at(int row, int col);
        bool position_empty(int row, int col) const;
        bool alreadyFiredAt(int row, int col) const;
        void placeHit(int row, int col);
        void placeMiss(int row, int col);
        void placePieceAt(int row, int col, const char piece);

        //check for valid input
        bool inBounds(int row, int col) const;
        bool between(int value, int min, int max) const;

        //getter functions
        int getNumRows() const;
        int getNumCols() const;

    private:
        const int numRows, numCols;
        std::vector<std::string> boardContents;
    };
}

#endif //BATTLESHIPMASTER_BOARD_H
