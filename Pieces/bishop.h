#ifndef BISHOP_H
#define BISHOP_H

#include "piece.h"
class Move;

class Bishop : public Piece {
public:
  Bishop(bool isWhite, pieceType pType, int r, int c, Board *board);

  bool findValidMoves(std::vector<Move> &validMoves,
                      std::stack<Move> &possibleMoves);
};

#endif