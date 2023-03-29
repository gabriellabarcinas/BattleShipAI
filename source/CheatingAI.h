//
// Created by Gabby Barcinas on 5/19/21.
//

#ifndef BATTLESHIP_CHEATINGAI_H
#define BATTLESHIP_CHEATINGAI_H
#include "AiPlayer.h"
#include "Move.h"
#include <vector>

namespace BattleShip {
    class CheatingAI  : public AiPlayer {
    public:
        CheatingAI(const std::string& name, int rows, int cols);
        virtual Move getMove() override;
        void getShipCoords();

    protected:
        std::vector<std::pair<int, int>> shipPlacement;
        int count = 0;
    };
}



#endif //BATTLESHIP_CHEATINGAI_H
