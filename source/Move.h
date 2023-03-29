//
// Created by Gabby Barcinas on 5/19/21.
//

#ifndef BATTLESHIP_MOVE_H
#define BATTLESHIP_MOVE_H

namespace BattleShip {
    class Player;
    class Board;
    class Move {
    public:
        Move(const Player& maker);
        Move(const Player& maker, int row, int col);
        Move(std::string& proposedMove, const Player& maker);
        void make(Board& board);
        bool isValid() const;
        bool isMoveAHit() const;
        void copyCoords(const Move& otherMove);
        void setMove(int randomRow, int randomCol);
        bool getFormattedCorrectly() const;
        int getRow() const;
        int getCol() const;

    private:
        const Player& maker;
        int row, col;
        bool formattedCorrectly;
    };
}

#endif //BATTLESHIP_MOVE_H
