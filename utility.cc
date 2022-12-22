#include "utility.h"
#include "Pieces/piece.h"
#include "move.h"

Posn::Posn() : r{-1}, c{-1} {}

Posn::Posn(int r, int c) : r{r}, c{c} {}

namespace Utility {
bool slidingMove(std::vector<Move> &validMoves, std::stack<Move> &possibleMoves,
                 Piece *p, int rowOffset, int colOffset) {
  Piece *target = nullptr;
  bool foundCapture = false;
  int col = p->c, row = p->r;
  while (col <= 7 && col >= 0 && row <= 7 && row >= 0) {
    target = p->board->state[row][col];
    if (!target) {
      possibleMoves.push(Move(Posn(p->r, p->c), Posn(row, col), same));
    } else if (target && target->isWhite != p->isWhite) {
      validMoves.push_back(Move(Posn(p->r, p->c), Posn(row, col), same));
      foundCapture = true;
      break;
    } else if (target && target->isWhite == p->isWhite && target != p) {
      break;
    }
    row += rowOffset;
    col += colOffset;
  }
  return foundCapture;
}

bool fixedMove(std::vector<Move> &validMoves, std::stack<Move> &possibleMoves,
               Piece *p, int rowOffset, int colOffset) {
  Piece *target = nullptr;
  bool foundCapture = false;
  int row = p->r + rowOffset;
  int col = p->c + colOffset;
  if (row <= 7 && row >= 0 && col <= 7 && col >= 0) {
    target = p->board->state[row][col];
    if (!target) {
      possibleMoves.push(Move(Posn(p->r, p->c), Posn(row, col), same));
    } else if (target && target->isWhite != p->isWhite) {
      validMoves.push_back(Move(Posn(p->r, p->c), Posn(row, col), same));
      foundCapture = true;
    }
  }
  return foundCapture;
}
} // namespace Utility