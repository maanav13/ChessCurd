#ifndef PIECE_H
#define PIECE_H
#include <vector>

class Move;

class Piece {
    double value;
    bool isWhite;
    int x;
    int y;

    virtual void findValidMoves(std::vector<Move>& validMoves) = 0;

    virtual void executeMove(const Move& m);

    virtual void undoMove(const Move& m);

};

#endif