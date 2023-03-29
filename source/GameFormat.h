//
// Created by Gabby Barcinas on 5/13/21.
//

#ifndef BATTLESHIPMASTER_GAMEFORMAT_H
#define BATTLESHIPMASTER_GAMEFORMAT_H

#include <iostream>
#include <memory>
#include <map>
#include <vector>
#include <random>

namespace BattleShip {
    class GameFormat {
    public:
        explicit GameFormat(const std::string& filename);

        // read the file
        void readFile(const std::string &filename);

        int getNumRows() const;
        int getNumCols() const;
        int getGameMode();
        int getAiMode();
        const std::map<char, int>& getShipAttributes() const;

    private:
        std::map<char, int> shipAttributes; // stores a map of ships with the key: ship name & value: ship size
        int numShips;
        int numRowsInBoard, numColsInBoard;
    };
}

#endif //BATTLESHIPMASTER_GAMEFORMAT_H
