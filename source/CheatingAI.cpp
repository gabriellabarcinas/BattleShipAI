//
// Created by Gabby Barcinas on 5/19/21.
//

#include "CheatingAI.h"
#include <vector>

BattleShip::CheatingAI::CheatingAI(const std::string& name, int rows, int cols) : AiPlayer(name, rows, cols), shipPlacement(){
}

// set the ship position to be the players ships
void BattleShip::CheatingAI::getShipCoords(){
    std::vector<std::pair<int, int>> ships;
    // loop for all the opponents ships
    for (int i = 0; i < BattleShip::Player::board.getNumRows(); ++i){
        for(int j = 0; j < BattleShip::Player::board.getNumCols(); ++j){
            if(this->getOpponent().getBoard().at(i, j) != '*'){
                // get the ship coordinates from the opponents board
                ships.emplace_back(std::pair<int, int>(i, j));
            }
        }
    }
    shipPlacement = ships;
}

BattleShip::Move BattleShip::CheatingAI::getMove(){
    // if there is not ships already set
    if(count < 1){
        getShipCoords();
        count++;
    }
    // make row the first int in the pair and make col the second int in the pair
    int row = shipPlacement.at(0).first;
    int col = shipPlacement.at(0).second;
    // erase the ships from the vector as they are hit
    shipPlacement.erase(shipPlacement.begin());
    // return the move
    return Move{*this, row, col};
}