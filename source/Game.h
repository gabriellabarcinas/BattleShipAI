//
// Created by Gabby Barcinas on 5/13/21.
//

#ifndef BATTLESHIPMASTER_GAME_H
#define BATTLESHIPMASTER_GAME_H
#include <string>
#include <memory>
#include <vector>
#include <random>
#include <algorithm>
#include "Move.h"
#include "GameFormat.h"
#include "Player.h"

namespace BattleShip {
    class Game {
    public:
        explicit Game(const std::string& filename, int seed);
        // game play
        void playGame();
        bool gameIsOver();
        void displayGameResults();

        //setting up the game
        void gameModeOne(int numRows, int numCols, const std::map<char, int> &shipsInfo);
        void gameModeTwo(int numRows, int numCols, const std::map<char, int> &shipsInfo);
        void gameModeThree(int numRows, int numCols, const std::map<char, int> &shipsInfo);
        void setUpGame();

        // Game with player functions
        Player& getCurrentPlayer() const;
        Move getCurrentPlayersMove() const;
        void changePlayerTurn();
        std::string& getWinner();

    private:
        GameFormat gameFormat;
        std::vector<std::unique_ptr<Player>> players;
        int playerTurn;
        std::string winner;
    };
}

#endif //BATTLESHIPMASTER_GAME_H
