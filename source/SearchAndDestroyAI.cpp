//
// Created by Gabby Barcinas on 5/19/21.
//

#include "SearchAndDestroyAI.h"
#include <vector>
#include <utility>

/* this AI has two modes
    1.) Search mode it is just a random AI
            -When it gets a hit, then it changes to Destroy mode
    2.) In destroy mode, it will shoot ->
            left, up, right, then down
            -if hit then it will add to list of locations to fire at
    3.) After hit everything on the list, go back to random ai mode
*/

BattleShip::SearchAndDestroyAI::SearchAndDestroyAI(const std::string &name, int rows, int cols) : RandomAI(name, rows, cols){
}

BattleShip::Move BattleShip::SearchAndDestroyAI::getMove() {
    // this will be if the ship hit queue is empty
    if (destroyPlacement.empty()) {
        // get random move through the randomAI class
        auto moves = BattleShip::RandomAI::getPossibleMoves();
        auto move = BattleShip::RandomAI::pickAMove(moves);

        // choose random row
        int row = move.getRow();
        // choose random col
        int col = move.getCol();
        // if a ship is hit, then activate destroy mode
        if (this->BattleShip::Player::getOpponent().getBoard().at(row, col) != '*' and
            this->BattleShip::Player::getOpponent().getBoard().at(row, col) != 'X' and
            this->BattleShip::Player::getOpponent().getBoard().at(row, col) != 'O') {
            destroyMode(row, col);
        }
        return Move {*this, row, col};
    } else {    // this means that a ship has hit
        int first = destroyPlacement[0].first;   // row is first index in the destroy ship vector
        int second = destroyPlacement[0].second;  // col is second index in destroy ship vector
        // if it contains a ship then add it to the queue again
        if (this->BattleShip::Player::getOpponent().getBoard().at(first, second) != '*' and
            this->BattleShip::Player::getOpponent().getBoard().at(first, second) != 'X' and
            this->BattleShip::Player::getOpponent().getBoard().at(first, second) != 'O') {
            destroyMode(first, second);
        }
        return Move {*this, first, second};
    }
}

// this function will be the destroy mode on the Search and Destroy AI
// it will add all the coordinates around the ship to the vector
// left, up, right, then down --> make sure it is in bounds and position is empty, if hit a ship then go to the
void BattleShip::SearchAndDestroyAI::destroyMode(int row, int col) {
    // get the opponents board to place the positions at
    Board& board = BattleShip::Player::getOpponent().getBoard();
    // fire left if in bounds and position empty
    if (board.inBounds(row, col-1) && not (this->board.alreadyFiredAt(row, col-1))) {
        addFiringLeft(row, col);
    }
    // fire up if in bounds and position empty
    if (board.inBounds(row-1, col) && not (this->board.alreadyFiredAt(row-1, col))) {
        addFiringUp(row, col);
    }
    // fire right if in bounds and position empty
    if (board.inBounds(row, col+1) && not (this->board.alreadyFiredAt(row, col+1))) {
        addFiringRight(row, col);
    }
    // fire down if in bounds and position empty
    if (board.inBounds(row+1, col) && not(this->board.alreadyFiredAt(row+1, col))) {
        addFiringDown(row, col);
    }
}

/* fire left is
    * * *
    L X *
    * * *
    row is the same
    col - 1
 */
void BattleShip::SearchAndDestroyAI::addFiringLeft(int row, int col) {
    // add the left position to the queue
    destroyPlacement.push_back(std::pair<int, int> (row, col-1));
}

/* fire up is
    * U *
    L X *
    * * *
    row is - 1
    col is the same
 */
void BattleShip::SearchAndDestroyAI::addFiringUp(int row, int col) {
    // add the up position to the queue
    destroyPlacement.push_back(std::pair<int, int> (row - 1 , col));
}

/* fire right is
    * U *
    L X R
    * * *
    row is the same
    col is + 1
 */
void BattleShip::SearchAndDestroyAI::addFiringRight(int row, int col) {
    // add the right position to the queue
    destroyPlacement.push_back(std::pair<int, int> (row, col+1));
}

/* fire down is
    * U *
    L X R
    * D *
    row is + 1
    col is the same
 */
void BattleShip::SearchAndDestroyAI::addFiringDown(int row, int col) {
    // add the down position to the queue
    destroyPlacement.push_back(std::pair<int, int> (row + 1, col));
}