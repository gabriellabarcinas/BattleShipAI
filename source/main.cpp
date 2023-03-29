/*
 Gabby Barcinas and Angelina Lim
 ECS36B Homework 3: Battleship
 This program will have two players play a game of battleship
 */

#include <iostream>
#include <string>
#include "Game.h"
#include <chrono>

int main(int argc, char** argv) {
    int seed;
    // if there are enough arguments
    if (argc == 1) {
        seed = std::stoi(argv[1]);
    }else {
        // change the seed to the current time
        seed = std::chrono::system_clock::now().time_since_epoch().count();
    }

    // get the config file from the command line
    std::string filename(argv[1]);

    BattleShip::Game theGame(filename, seed); // create a game
    theGame.playGame(); // play the game

    return 0;
}

