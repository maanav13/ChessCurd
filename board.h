#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <memory>
#include <stack>
#include <unordered_set>

class Move;
class Piece;

class Board {
public:
  Piece *state[8][8];
  std::unordered_set<Piece *> availablePiecesWhite;
  std::unordered_set<Piece *> availablePiecesBlack;
  std::stack<Piece *> removedPiecePrediction;

  Board();

  ~Board();

  void executeMove(const Move &m);

  void undoMove(const Move &m);
};

#endif