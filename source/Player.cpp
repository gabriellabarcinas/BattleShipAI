//
// Created by Gabby Barcinas on 5/13/21.
//

#include <sstream>
#include <memory>
#include <map>
#include <vector>
#include "Player.h"
#include "Move.h"
#include "Ship.h"
#include "InputValidation.h"

// Constructor for player
BattleShip::Player::Player(int numRows, int numCols) : name(), board(numRows, numCols), ships(),
    numShipsSunk(0), opponent(nullptr){
}

BattleShip::Player::Player(const std::string& playerName, int numRows, int numCols) : Player(numRows, numCols){
    name = playerName;
}

// place ships
void BattleShip::Player::placeShips(const std::map<char, int>& shipsInfo){
    this->board.displayPlacementBoard();
    for(const auto& ship : shipsInfo){
        BattleShip::Ship newShip(ship.first, ship.second);
        newShip.place_ship(this->board, this->getName());
        ships.push_back(newShip);
        this->board.displayPlacementBoard();
    }
}

// print the players firing boardContents and placement boardContents
void BattleShip::Player::printBoard() const {
    std::cout << this->name << "'s Firing Board" << std::endl;
    getOpponent().getBoard().displayFiringBoard();
    std::cout << std::endl << std::endl;
    std::cout << this->name << "'s Placement Board" << std::endl;
    board.displayPlacementBoard();
}

// the human player get move function that can be overridden with AI get move
BattleShip::Move BattleShip::Player::getMove(){
    std::string proposedMove;

    // get the move from the user until it is valid format
    std::cout << this->getName() << ", where would you like to fire?" << std::endl;
    std::cout << "Enter your attack coordinate in the form row col: ";
    std::getline(std::cin, proposedMove);

    return Move {proposedMove, *this};
}

// check if all the ships have sunk
bool BattleShip::Player::allShipsSunk() {
    if(getNumShipsSunk() == getNumShips()){
        return true;
    }
    return false;
}

// SETTER FUNCTIONS

// set the player's opponent
void BattleShip::Player::setOpponent(Player& other_player) {
    opponent = &other_player;
}


// GETTER FUNCTIONS

const std::string& BattleShip::Player::getName() const{
    return name;
}


int BattleShip::Player::getNumShips() const {
    return ships.size();
}

// get the player's ship
const std::vector<BattleShip::Ship>& BattleShip::Player::getShips() const{
    return ships;
}

int& BattleShip::Player::getNumShipsSunk(){
    return numShipsSunk;
}

// get the player's opponent
BattleShip::Player& BattleShip::Player::getOpponent() const {
    return *opponent;
}

// get the player's boardContents
BattleShip::Board& BattleShip::Player::getBoard(){
    return board;
}

