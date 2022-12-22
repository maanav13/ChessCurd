#ifndef PAWN_H
#define PAWN_H

#include "piece.h"
class Move;

class Pawn : public Piece {
public:
  Pawn(bool isWhite, pieceType pType, int r, int c, Board *board);

  bool findValidMoves(std::vector<Move> &validMoves,
                      std::stack<Move> &possibleMoves);
};

#endif