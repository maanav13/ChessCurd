#ifndef KNIGHT_H
#define KNIGHT_H

#include "piece.h"
class Move;

class Knight : public Piece {
public:
  Knight(bool isWhite, pieceType pType, int r, int c, Board *board);

  bool findValidMoves(std::vector<Move> &validMoves,
                      std::stack<Move> &possibleMoves);
};

#endif