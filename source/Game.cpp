//
// Created by Gabby Barcinas on 5/13/21.
//

#include <iostream>
#include <memory>
#include <string>
#include "Game.h"
#include "Move.h"
#include "Player.h"
#include "GameFormat.h"
#include "HumanPlayer.h"
#include "RandomAI.h"
#include "CheatingAI.h"
#include "SearchAndDestroyAI.h"

// Game constructor
BattleShip::Game::Game(const std::string& filename, int seed) : gameFormat(filename), players(), playerTurn(0), winner(){
    BattleShip::AiPlayer::seed_random_number_generator(seed);   // seed the random number generator
    int numRows = gameFormat.getNumRows();
    int numCols = gameFormat.getNumCols();
    const std::map<char, int>& shipsInfo = gameFormat.getShipAttributes();
    int gameMode = gameFormat.getGameMode();

    if(gameMode == 1){
        gameModeOne(numRows, numCols, shipsInfo);
    }

    if(gameMode == 2){
        gameModeTwo(numRows, numCols, shipsInfo);
    }

    if(gameMode == 3){
        gameModeThree(numRows, numCols, shipsInfo);
    }

    int i = 1;
    for (const auto& player : players){
        player->setOpponent(*players.at(i));
        --i;
    }
}

void BattleShip::Game::gameModeOne(int numRows, int numCols, const std::map<char, int> &shipsInfo) {
    for (int i = 0; i < 2; ++i){
        std::unique_ptr<Player> newPlayer = std::make_unique<HumanPlayer>(i+1, numRows, numCols);
        newPlayer->placeShips(shipsInfo);
        players.push_back(std::move(newPlayer));
    }
}

void BattleShip::Game::gameModeTwo(int numRows, int numCols,  const std::map<char, int> &shipsInfo) {
    std::unique_ptr<Player> player1, player2;
    player1 = std::make_unique<HumanPlayer>(1 , numRows, numCols);
    player1->placeShips(shipsInfo);
    players.push_back(std::move(player1));
    // get the ai player
    int AIType = gameFormat.getAiMode();
    if(AIType == 1) {
        player2 = std::make_unique<CheatingAI>("AI 1", numRows, numCols);
    }else if(AIType == 2){
        player2 = std::make_unique<RandomAI>("AI 1", numRows, numCols);
    }else if(AIType == 3){
        player2 = std::make_unique<SearchAndDestroyAI>("AI 1", numRows, numCols);
    }
    player2->placeShips(shipsInfo);
    players.push_back(std::move(player2));
}

void BattleShip::Game::gameModeThree(int numRows, int numCols,  const std::map<char, int> &shipsInfo) {
    std::unique_ptr<Player> newPlayer;
    for (int i = 0; i < 2; ++i){
        int AIType = gameFormat.getAiMode();
        std::string id = std::to_string(i+1);
        if(AIType == 1) {
            newPlayer = std::make_unique<CheatingAI>("AI " + id, numRows, numCols);
        }else if(AIType == 2){
            newPlayer = std::make_unique<RandomAI>("AI " + id, numRows, numCols);
        }else if(AIType == 3){
            newPlayer = std::make_unique<SearchAndDestroyAI>("AI " + id, numRows, numCols);
        }
        newPlayer->placeShips(shipsInfo);
        players.push_back(std::move(newPlayer));
    }
}

// function to play the game
void BattleShip::Game::playGame() {
    // play the game
    do{
//        Player& currPlayer = *players.at(playerTurn);
        Move move = getCurrentPlayersMove();
//        move.make(currPlayer.getBoard());
        move.isMoveAHit();
        changePlayerTurn();
    }while(not gameIsOver());
    displayGameResults();
}


// change the player turn when it is called
void BattleShip::Game::changePlayerTurn() {
    playerTurn = (playerTurn + 1) % players.size();
}

// check if the game is over and which player won
bool BattleShip::Game::gameIsOver(){

    for(const auto& player : players) {
        if(player->allShipsSunk()) {
            winner = player->getOpponent().getName();
            return true;
        }
    }
    return false;
}

void BattleShip::Game::displayGameResults() {
    std::cout << this->getWinner() << " won the game!" << std::endl;
}

BattleShip::Move BattleShip::Game::getCurrentPlayersMove() const{
    Player& curPlayer = getCurrentPlayer();
    Move move(curPlayer);

    do {
        move.copyCoords(curPlayer.getMove());
        if (not move.getFormattedCorrectly()) {
            move.copyCoords(curPlayer.getMove());
        }else if (not move.isValid()) {
            curPlayer.printBoard();
            move.copyCoords(curPlayer.getMove());
        }
    }while (not(move.getFormattedCorrectly() or move.isValid()));
    return move;
}

BattleShip::Player& BattleShip::Game::getCurrentPlayer() const{
    return *players.at(playerTurn);
}

std::string& BattleShip::Game::getWinner() {
    return winner;
}
