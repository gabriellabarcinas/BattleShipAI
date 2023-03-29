//
// Created by Gabby Barcinas on 5/19/21.
//

#ifndef BATTLESHIP_HUMANPLAYER_H
#define BATTLESHIP_HUMANPLAYER_H
#include "Player.h"
#include "Move.h"

namespace BattleShip {
    class HumanPlayer : public Player {
    public:
        HumanPlayer(int playerID, int numRows, int numCols);
        virtual Move getMove() override;
    };
}
#endif //BATTLESHIP_HUMANPLAYER_H
