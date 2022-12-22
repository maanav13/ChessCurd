#ifndef QUEEN_H
#define QUEEN_H

#include "piece.h"
class Move;

class Queen : public Piece {
public:
  Queen(bool isWhite, pieceType pType, int r, int c, Board *board);

  bool findValidMoves(std::vector<Move> &validMoves,
                      std::stack<Move> &possibleMoves);
};

#endif