//
// Created by Gabby Barcinas on 5/13/21.
//

#ifndef BATTLESHIPMASTER_PLAYER_H
#define BATTLESHIPMASTER_PLAYER_H
#include <string>
#include <vector>
#include <map>
#include "Move.h"
#include "Ship.h"
#include "Board.h"

namespace BattleShip {
    class Player {
    public:
        Player(int numRows, int numCols);
        Player(const std::string& name, int numRows, int numCols);
        virtual ~Player() = default;
        // Player boardContents functions
        void printBoard() const;

        virtual Move getMove() = 0; // abstract method function

        // Player ships functions
        virtual void placeShips(const std::map<char, int> &shipsInfo);
        bool allShipsSunk();

        // SETTER FUNCTIONS
        void setOpponent(Player& other_player);


        // GETTER FUNCTIONS
        const std::string& getName() const;
        int getNumShips() const;
        int& getNumShipsSunk();
        const std::vector<Ship>& getShips() const;
        Player& getOpponent() const;
        Board& getBoard();

    protected:
        std::string name;
        Board board;
        std::vector<Ship> ships;
        int numShipsSunk;
        Player* opponent;

    };
};

#endif //BATTLESHIPMASTER_PLAYER_H
