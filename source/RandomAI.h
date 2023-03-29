//
// Created by Gabby Barcinas on 5/19/21.
//

#ifndef BATTLESHIP_RANDOMAI_H
#define BATTLESHIP_RANDOMAI_H
#include "AiPlayer.h"
#include "Move.h"
#include <vector>
#include <random>

namespace BattleShip {

    class RandomAI : public AiPlayer{
    public:
        RandomAI(const std::string &name, int rows, int cols);
        virtual Move getMove() override;
        std::vector<Move> getPossibleMoves() const;
        virtual Move pickAMove(const std::vector<Move>& moves) const;
    };
}

#endif //BATTLESHIP_RANDOMAI_H
