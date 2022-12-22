#ifndef ROOK_H
#define ROOK_H

#include "piece.h"
class Move;

class Rook : public Piece {
public:
  Rook(bool isWhite, pieceType pType, int r, int c, Board *board);

  bool findValidMoves(std::vector<Move> &validMoves,
                      std::stack<Move> &possibleMoves);
};

#endif