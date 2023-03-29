//
// Created by Gabby Barcinas on 5/14/21.
//

#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <cstdio>
#include <sstream>
#include "InputValidation.h"
#include "Ship.h"
#include "Player.h"

// Ship constructor
BattleShip::Ship::Ship(const char& shipName, int shipSize) : shipName(shipName), shipSize(shipSize),
    rowStart(), colStart(),
    shipDirection(){
}

BattleShip::Ship::Ship(const char& shipName, int shipSize, int row, int col, int direction) : shipName(shipName), shipSize(shipSize),
    rowStart(row), colStart(col){
    if(direction == 0){
        shipDirection = "h";
    }if(direction == 1){
        shipDirection = "v";
    }
}

// CALL THE PLACE SHIPS FUNCTIONS
void BattleShip::Ship::place_ship(Board& board, const std::string& name) {

    // get the player ship direction and coordinate
    do{
        setShipDirection(const_cast<std::string &>(name));
    }while(not (setShipCoordinate(const_cast<std::string &>(name))
        and coordinate_in_bounds(board)));

    if (shipDirection == "h") {
        add_horizontally(rowStart, colStart, board);
    }
    else if (shipDirection == "v") {
        add_vertically(rowStart, colStart, board);
    }
}

// GET DIRECTION FROM THE PLAYER
void BattleShip::Ship::setShipDirection(std::string& name) {
    std::string direction;

    do {   // keep getting the direction until input is valid
        std::cout << name << ", do you want to place " << shipName;
        std::cout << " horizontally or vertically?" << std::endl;
        std::cout << "Enter h for horizontal or v for vertical"
                  << std::endl << "Your choice: ";
        std::getline(std::cin, direction);
        std::stringstream dir(direction);
        direction = no_white_space(direction);       // set direction will check if the direction is h or v
    } while(not valid_direction(direction));
    shipDirection = toLower(direction);

}

// GET SHIP COORDINATES FROM THE PLAYER
bool BattleShip::Ship::setShipCoordinate(std::string& name) {
    std::string proposedMove;
    std::string should_be_blank;

    // get the move from the user until it is valid format
    std::cout << name << ", enter the row and column you want to place " << shipName;
    std::cout << ", which is " << shipSize << " long, at with a space in between row and col: ";
    std::getline(std::cin, proposedMove);
    std::stringstream moveParser(proposedMove);
    moveParser >> rowStart >> colStart;

    return StreamOnlyContainsWhiteSpace(moveParser);
}

// CHECK IF VALID SHIP COORDINATES
bool BattleShip::Ship::valid_coordinate(std::string& coordinate, Board& board) {
    return checkFormattingCoordinate(coordinate) && coordinate_in_bounds(board);
}

bool BattleShip::Ship::checkFormattingCoordinate(std::string& coordinate) {
    return getValidInt(coordinate);
}

// will return valid direction if player inputs H or h or V or v
bool BattleShip::Ship::valid_direction(std::string& direction) {
    // h an H is horizontal
    // v and V is vertical
    if (direction == "h" || direction == "H" || direction == "v" || direction == "V") {
        return true;
    }
    return false;
}

// check if the ship coordinate are in bounds
bool BattleShip::Ship::coordinate_in_bounds(Board& board) {
    int count = 0;    // set count to equal 0
    // check if direction is horizontal if it will fit on the boardContents
    if (shipDirection == "h") {
        for (int i = colStart; i < colStart + shipSize; i++) {
            if (board.inBounds(rowStart, i) and board.at(rowStart, i) == '*') {
                count++;
            }
        }
    }
    if (shipDirection == "v") {
        for (int i = rowStart; i < rowStart + shipSize; i++) {
            if (board.inBounds(i, colStart) and board.at(i, colStart) == '*') {
                count++;
            }
        }
    }
    // make sure that the count equals the ship size
    if (count == shipSize) {
        return true;
    } else {
        return false;
    }
}

// ADD THE SHIP ON THE BOARD

// set ship horizontally
void BattleShip::Ship::add_horizontally(int row, int col, Board& board) {
    // for loop going through the length of the ship coords
    // place the ship
    for (int i = col; i < col + shipSize; i++) {
        board.at(row, i) = shipName;
    }
}

// set ship vertically
void BattleShip::Ship::add_vertically(int row, int col, Board& board) {
    // for loop going through the length of the ship coords
    // place the ship
    for (int i = row; i < row + shipSize; i++) {
        board.at(i, col) = shipName;
    }
}

// check if the ship is sunk
bool BattleShip::Ship::isSunk(Board& board) const {
    // if all the coordinates from where the ship begins to where the ships ends is equal to X,
    // then the ship is sunk
    // for how long the ships is
    // ------ stays on the same col
    int count = 0;    // set count to equal 0

    // check if direction is horizontal if it is hit on the boardContents
    if (shipDirection == "h") {
        for (int i = colStart; i < colStart + shipSize; i++) {
            if (board.at(rowStart, i) == 'X') {
                count++;
            }
        }
    }else if (shipDirection == "v") {
        for (int i = rowStart; i < rowStart + shipSize; i++) {
            if (board.at(i, colStart) == 'X') {
                count++;
            }
        }
    }
    // make sure that the count equals the ship size
    if (count == shipSize) {
        return true;
    } else {
        return false;
    }
}

//// GETTER AND SETTER FUNCTIONS ////

// get the ship name
char BattleShip::Ship::getShipName() const{
    return shipName;
}

char BattleShip::Ship::getShipSize() const {
    return shipSize;
}

std::string BattleShip::Ship::getShipDirection() const {
    return shipDirection;
}

int BattleShip::Ship::getShipRow() const {
    return rowStart;
}
int BattleShip::Ship::getShipCol() const {
    return colStart;
}