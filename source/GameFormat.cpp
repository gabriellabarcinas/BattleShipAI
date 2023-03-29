
// Created by Gabby Barcinas on 5/13/21.
//

#include <iostream>
#include <fstream>
#include <map>
#include <random>
#include "GameFormat.h"
#include "InputValidation.h"

// Game Format constructor
BattleShip::GameFormat::GameFormat(const std::string& filename) : shipAttributes(), numShips(),
    numRowsInBoard(), numColsInBoard(){
    readFile(filename);
}

// get information from the file
void BattleShip::GameFormat::readFile(const std::string& filename) {
    std::fstream infile;
    char ship_name;
    int ship_size;
    infile.open(filename); // open the file
    if (infile.is_open()) {     // open the file and get the first three lines
        std::string line;
        std::getline(infile, line);     // get first line = row
        numRowsInBoard = std::stoi(line);
        std::getline(infile, line);     // get second line = cols
        numColsInBoard = std::stoi(line);
        std::getline(infile, line);     // get third line = num ships
        numShips = std::stoi(line);
        // put ships in a map --> char - int --> H 2 --> key: H value: 2
        for (int j = 0; j < numShips; j++) {
            infile >> ship_name >> ship_size;
            shipAttributes.insert(std::pair<char, int>(ship_name, ship_size)); // input the ship coords into the map
        }
        // close the file
        infile.close();
    } else {        // else print that the file could not open and exit program
        std::cout << "Could not open the file." << std::endl;
        exit(0);
    }
}

// get the game mode from the user
int BattleShip::GameFormat::getGameMode() {
    // ask the user what game mode they want to play
    std::cout << "What type of game do you want to play?" << std::endl;
    std::cout << "1. Human vs Human" << std::endl;
    std::cout << "2. Human vs AI" << std::endl;
    std::cout << "3. AI vs AI" << std::endl;
    // get a valid integer
    return getValidInt("Your choice: ");
}

int BattleShip::GameFormat::getAiMode() {
    // ask the user what ai type they want to have
    std::cout << "What type of AI do you want?" << std::endl;
    std::cout << "1. Cheating AI" << std::endl;
    std::cout << "2. Random AI" << std::endl;
    std::cout << "3. Hunt Destroy AI" << std::endl;
    // get a valid integer
    return getValidInt("Your choice: ");
}

// for getting the number of rows
int BattleShip::GameFormat::getNumRows() const{
    return numRowsInBoard;
}

//for getting the number of cols
int BattleShip::GameFormat::getNumCols() const{
    return numColsInBoard;
}

// SHIP STUFF

// this getting function will get the ship coord map
const std::map<char, int> &BattleShip::GameFormat::getShipAttributes() const {
    return shipAttributes;
}


