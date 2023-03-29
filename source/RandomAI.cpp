//
// Created by Gabby Barcinas on 5/19/21.
//

#include "RandomAI.h"
#include "AiPlayer.h"
#include "Move.h"
#include <vector>
#include <algorithm>

BattleShip::RandomAI::RandomAI(const std::string& name, int rows, int cols) : AiPlayer(name, rows, cols){
}

BattleShip::Move BattleShip::RandomAI::getMove(){
    auto moves = getPossibleMoves();
    return pickAMove(moves);
}

std::vector<BattleShip::Move> BattleShip::RandomAI::getPossibleMoves() const{
    std::vector<Move> moves;
    for (int row = 0; row < board.getNumRows(); ++row) {
        for (int col = 0; col < board.getNumRows(); ++col)
        if(not this->getOpponent().getBoard().alreadyFiredAt(row, col)){
                moves.push_back({*this, row, col});
        }
    }
    return moves;
}

BattleShip::Move BattleShip::RandomAI::pickAMove(const std::vector<Move>& moves) const{
    std::uniform_int_distribution<int> dis(0, moves.size() - 1);
    return moves.at(dis(randomNumberGenerator));
}
