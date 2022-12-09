#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Move;
class Piece;

class Board {
    std::vector<Piece *> state;

    void executeMove(const Move& m);

    void undoMove(const Move& m);
};

#endif