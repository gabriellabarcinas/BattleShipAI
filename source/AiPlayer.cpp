//
// Created by Gabby Barcinas on 5/19/21.
//
#include <map>
#include <random>
#include "AiPlayer.h"
#include "Ship.h"
#include "InputValidation.h"

std::mt19937 BattleShip::AiPlayer::randomNumberGenerator;

BattleShip::AiPlayer::AiPlayer(const std::string& name, int numRows, int numCols) : Player(name, numRows, numCols){
}

// place the AI Ships
void BattleShip::AiPlayer::placeShips(const std::map<char, int>& shipsInfo) { // how to override a place_ship function that is in ship.cpp
    int direction, row, col;
    for(const auto& ship : shipsInfo){
        do {
            direction = minstd_get_random_int(0, 1);
            row = minstd_get_random_int(0, this->board.getNumRows() - ship.second);
            col = minstd_get_random_int(0, this->board.getNumCols() - ship.second);
        } while(not valid_AI_ship_placement(direction, row, col, ship.second));
        BattleShip::Ship newShip(ship.first, ship.second, row, col, direction);
        place_ship(this->board, newShip, this->getName());
        BattleShip::Player::ships.push_back(newShip);
    }
}

void BattleShip::AiPlayer::place_ship(Board& board, const Ship& ship, const std::string& name){
    int row = ship.getShipRow();
    int col = ship.getShipCol();
    // add the ships to the board
    if (ship.getShipDirection() == "h") {
        // this means direction = horizontal
        // add the ship horizontally
        for (int i = col; i < col + ship.getShipSize(); i++) {
            board.at(row, i) = ship.getShipName();
        }
    } else {
        // add the ship vertically
        for (int i = row; i < row + ship.getShipSize(); i++) {
            board.at(i, col) = ship.getShipName();
        }
    }
    // print the ship on the board to show
    std::cout << name << "'s Board"<<std::endl;
    board.displayPlacementBoard();
    std::cout << std::endl;
}

// seed the random number generator
void BattleShip::AiPlayer::seed_random_number_generator(int seed) {
    randomNumberGenerator.seed(seed);
}

// random generator for the ai direction
int BattleShip::AiPlayer::minstd_get_random_int(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    int random_num = dist(randomNumberGenerator);
    return random_num;
}

// make sure ship is in valid placement
bool BattleShip::AiPlayer::valid_AI_ship_placement(int direction, int row, int col, int shipSize) {
    int count = 0;    // set count to equal 0
    // check if direction is horizontal if it will fit on the boardContents
    if (direction == 0) {
        for (int i = col; i < col + shipSize; i++) {
            if (board.inBounds(row, i) and board.at(row, i) == '*') {
                count++;
            }
        }
    }
    if (direction == 1) {
        for (int i = row; i < row + shipSize; i++) {
            if (board.inBounds(i, col) and board.at(i, col) == '*') {
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