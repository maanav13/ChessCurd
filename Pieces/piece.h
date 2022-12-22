#ifndef PIECE_H
#define PIECE_H
#include "../board.h"
#include "../utility.h"
#include <vector>

class Move;

class Piece {
public:
  double value;
  bool isWhite;
  pieceType pType;
  int r;
  int c;
  Board *board;

  Piece(bool isWhite, pieceType pType, int r, int c, Board *board);

  virtual bool findValidMoves(std::vector<Move> &validMoves,
                              std::stack<Move> &possibleMoves) = 0;

  virtual void executeMove(const Move &m);

  virtual void undoMove(const Move &m);
};

#endif