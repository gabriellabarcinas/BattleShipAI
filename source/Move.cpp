//
// Created by Gabby Barcinas on 5/19/21.
//

#include <sstream>
#include "Move.h"
#include "InputValidation.h"
#include "Player.h"

BattleShip::Move::Move(const Player& maker) : maker(maker), row(), col(), formattedCorrectly(true){
}

BattleShip::Move::Move(const Player& maker, int row, int col) : maker(maker), row(row), col(col), formattedCorrectly(true){
}

BattleShip::Move::Move(std::string& proposedMove, const Player& maker) : Move(maker){
    std::stringstream moveParser(proposedMove);
    moveParser >> row >> col;
    formattedCorrectly = StreamOnlyContainsWhiteSpace(moveParser);
}

// check if the move is a hit
bool BattleShip::Move::isMoveAHit() const{

    char c = maker.getOpponent().getBoard().at(row, col);
    // check through the ships if the move is a hit
    for (const auto& ship : maker.getOpponent().getShips()) {
        if (c == ship.getShipName()) {
            // check if the move is a hit
            maker.getOpponent().getBoard().placeHit(row, col);
            maker.printBoard();
            std::cout << maker.getName() << " hit " << maker.getOpponent().getName();
            std::cout << "'s " << ship.getShipName() << "!" << std::endl;
            // check if the ship is sunk
            if (ship.isSunk(maker.getOpponent().getBoard())) {
                ++maker.getOpponent().getNumShipsSunk();
                std::cout << maker.getName() << " destroyed " << maker.getOpponent().getName();
                std::cout << "'s " << ship.getShipName() << "!" << std::endl;
            }
            // new line for spacing
            std::cout << std::endl;
            return true;
        }
    }

    // print if the board is a miss
    maker.getOpponent().getBoard().placeMiss(row, col);
    maker.printBoard();
    std::cout << "Missed." << std::endl;
    std::cout << std::endl;
    return false;
}

// check if the move is valid --> in bounds and position is empty
bool BattleShip::Move::isValid() const{
    return maker.getOpponent().getBoard().inBounds(row, col) && !maker.getOpponent().getBoard().alreadyFiredAt(row, col);
}

void BattleShip::Move::copyCoords(const Move& otherMove) {
    row = otherMove.row;
    col = otherMove.col;
}

void BattleShip::Move::make(Board& board) {
    char piece;
    if (isMoveAHit()) {
        piece = 'X';
    } else {
        piece = 'O';
    }
    board.placePieceAt(row, col, piece); // placeHit & placeMiss functions in board
}

bool BattleShip::Move::getFormattedCorrectly() const{
    return formattedCorrectly;
}

int BattleShip::Move::getRow() const{
    return row;
}

int BattleShip::Move::getCol() const{
    return col;
}
