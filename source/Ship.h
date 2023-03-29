//
// Created by Gabby Barcinas on 5/14/21.
//

#ifndef BATTLESHIPMASTER_SHIP_H
#define BATTLESHIPMASTER_SHIP_H
#include <string>
#include <iostream>
#include <vector>

namespace BattleShip {
    class Board;
    class Player;
    class Ship {
    public:
        // set up the ships
        Ship(const char& shipName, int shipSize);
        Ship(const char& shipName, int shipSize, int row, int col, int direction);
        void place_ship(Board& board, const std::string& name);
        bool isSunk(Board& board) const;

        // check if valid
        bool valid_coordinate(std::string& coordinate, Board& board);
        bool valid_direction(std::string& direction);
        bool checkFormattingCoordinate(std::string& coordinate);
        bool coordinate_in_bounds(Board& board);

        // SETTER FUNCTIONS
        void setShipDirection(std::string& name);
        bool setShipCoordinate(std::string& name);

        // GETTER FUNCTIONS
        char getShipName() const;
        char getShipSize() const;
        std::string getShipDirection() const;
        int getShipRow() const;
        int getShipCol() const;

        // add to the boardContents
        void add_vertically(int row, int col, Board& board);
        void add_horizontally(int row, int col, Board& board);

    private:
        char shipName;
        int shipSize;
        int rowStart;
        int colStart;
        std::string shipDirection;


    };
}

#endif //BATTLESHIPMASTER_SHIP_H
