//
// Created by Gabby Barcinas on 5/19/21.
//

#ifndef BATTLESHIP_AIPLAYER_H
#define BATTLESHIP_AIPLAYER_H
#include "Player.h"
#include "Ship.h"
#include <random>
#include <map>

namespace BattleShip {
    class AiPlayer : public Player {
    public:
        AiPlayer(const std::string& name, int numRows, int numCols);
        virtual ~AiPlayer() = default;

        virtual Move getMove() override = 0; // abstract method

        // for placing the ships
        virtual void placeShips(const std::map<char, int>& shipsInfo) override;
        void place_ship(Board& board, const Ship& ship, const std::string& name);
        bool valid_AI_ship_placement(int direction, int row, int col, int shipSize);
        // random number generator
        static void seed_random_number_generator(int seed);
        static int minstd_get_random_int(int min, int max);
    protected:
        static std::mt19937 randomNumberGenerator;
    };
}

#endif //BATTLESHIP_AIPLAYER_H
