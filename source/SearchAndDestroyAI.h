//
// Created by Gabby Barcinas on 5/19/21.
//

#ifndef BATTLESHIP_SEARCHANDDESTROYAI_H
#define BATTLESHIP_SEARCHANDDESTROYAI_H

#include "RandomAI.h"
#include "Move.h"
#include <string>
#include <vector>

namespace BattleShip {
    class SearchAndDestroyAI: public RandomAI {
    public:
        SearchAndDestroyAI(const std::string &name, int rows, int cols);
        virtual Move getMove() override;

    protected:
        void destroyMode(int row, int col);
        void addFiringLeft(int row, int col);
        void addFiringUp(int row, int col);
        void addFiringRight(int row, int col);
        void addFiringDown(int row, int col);
        std::vector<std::pair<int, int>> destroyPlacement;
    };
}

#endif //BATTLESHIP_SEARCHANDDESTROYAI_H
