#ifndef KING_H
#define KING_H

#include "piece.h"
class Move;

class King : public Piece {
public:
  King(bool isWhite, pieceType pType, int r, int c, Board *board);

  bool findValidMoves(std::vector<Move> &validMoves,
                      std::stack<Move> &possibleMoves);
};

#endif