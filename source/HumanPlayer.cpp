//
// Created by Gabby Barcinas on 5/19/21.
//

#include <sstream>
#include "Game.h"
#include "Player.h"
#include "HumanPlayer.h"
#include "Move.h"
#include "InputValidation.h"

BattleShip::HumanPlayer::HumanPlayer(int playerID, int numRows, int numCols) : Player(numRows, numCols){
    std::string playerName;
    std::cout << "Player " << playerID << " please enter your name: ";
    std::getline(std::cin, playerName);
    name = playerName;
}

// the human player get move function that can be overridden with AI get move
BattleShip::Move BattleShip::HumanPlayer::getMove(){
    std::string proposedMove;
    this->BattleShip::Player::printBoard();
    // get the move from the user until it is valid format
    std::cout << this->getName() << ", where would you like to fire?" << std::endl;
    std::cout << "Enter your attack coordinate in the form row col: ";
    std::getline(std::cin, proposedMove);

    return Move {proposedMove, *this};
}




