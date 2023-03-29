//
// Created by Gabby Barcinas on 5/13/21.
//

#include "Board.h"
#include <iostream>
#include <vector>

// Constructor for boardContents
BattleShip::Board::Board(int numRows, int numCols) : numRows(numRows), numCols(numCols),
    boardContents(numRows, std::string(numCols, '*')) {
}

// this function will display the firing boardContents
void BattleShip::Board::displayFiringBoard() const {
    //display cols
    std::cout << "  ";
    for (int i = 0; i < numCols; ++i) {
        std::cout << i << ' ';
    }
    // display rows
    std::cout << std::endl;
    int rowNum = 0;
    for (const auto& row : boardContents){
        std::cout << rowNum << ' ';
        for (const auto& piece : row) {
            if(piece == 'X' or
               piece == 'O' or
               piece == '*') {
                std::cout << piece << ' ';
            }else {
                std::cout << "* ";
            }
        }
        std::cout << std::endl;
        ++rowNum;
    }
}

// this function will display the placement boardContents
void BattleShip::Board::displayPlacementBoard() const {
    // display columns
    std::cout << "  ";
    for (int i = 0; i < numCols; ++i) {
        std::cout << i << ' ';
    }
    // display rows
    std::cout << std::endl;
    int rowNum = 0;
    for (const auto& row : boardContents) {
        std::cout << rowNum << ' ';
        for (const auto& piece : row) {
            std::cout << piece << ' ';
        }
        std::cout << std::endl;
        ++rowNum;
    }
}

// placing pieces on the board
void BattleShip::Board::placePieceAt(int row, int col, const char piece) {
    boardContents.at(row).at(col) = piece;
}

// placing a hit on the board
void BattleShip::Board::placeHit(int row, int col) {
    boardContents.at(row).at(col) = 'X';
}

// placing a miss on the board
void BattleShip::Board::placeMiss(int row, int col) {
    boardContents.at(row).at(col) = 'O';
}

// check where the boardContents position is --> const
const char& BattleShip::Board::at(int row, int col) const {
    return boardContents.at(row).at(col);
}

// check the boardContents position --> not const
char& BattleShip::Board::at(int row, int col) {
    return boardContents.at(row).at(col);
}

// within boardContents bounds
bool BattleShip::Board::inBounds(int row, int col) const {
    return between(row, 0, numRows-1) && between(col, 0, numCols-1);
}

// make sure the position is empty
bool BattleShip::Board::position_empty(int row, int col) const {
    if (boardContents.at(row).at(col) != '*') {
            return false;
        }
    return true;
}

bool BattleShip::Board::alreadyFiredAt(int row, int col) const{
    return boardContents.at(row).at(col) == '0' or
            boardContents.at(row).at(col) == 'X';
}

// check to see if the boardContents is in bounds
bool BattleShip::Board::between(int value, int min, int max) const {
    return value >= min && value <= max;
}

// get a vector of vectors for the boardContents
std::vector<std::string> BattleShip::Board::getBoard() {
    return boardContents;
}

// for getting the number of rows
int BattleShip::Board::getNumRows() const{
    return numRows;
}

//for getting the number of cols
int BattleShip::Board::getNumCols() const{
    return numCols;
}







