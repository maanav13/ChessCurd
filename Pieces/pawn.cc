#include "pawn.h"
#include "../move.h"

Pawn::Pawn(bool isWhite, pieceType pType, int r, int c, Board *board)
    : Piece(isWhite, pType, r, c, board) {
  value = constants::PAWN_VALUE;
}

bool Pawn::findValidMoves(std::vector<Move> &validMoves,
                          std::stack<Move> &possibleMoves) {
  int offset = isWhite ? 1 : -1;
  int promoteRank = isWhite ? 6 : 1;
  bool foundCapture = false;
  Piece *target;
  for (int col : {c - 1, c + 1}) {
    target = (col <= 7 && col >= 0) ? board->state[r + offset][col] : nullptr;
    if (target && target->isWhite != isWhite && r == promoteRank) {
      validMoves.emplace_back(Move(Posn(r, c), Posn(r + offset, col), queen));
      validMoves.emplace_back(Move(Posn(r, c), Posn(r + offset, col), knight));
      foundCapture = true;
    } else if (target && target->isWhite != isWhite && r != promoteRank) {
      validMoves.emplace_back(Move(Posn(r, c), Posn(r + offset, col), same));
      foundCapture = true;
    }
  }
  target = board->state[r + offset][c];
  if (!target && r == promoteRank) {
    possibleMoves.push(Move(Posn(r, c), Posn(r + offset, c), queen));
    possibleMoves.push(Move(Posn(r, c), Posn(r + offset, c), knight));
  } else if (!target) {
    possibleMoves.push(Move(Posn(r, c), Posn(r + offset, c), same));
  }
  return foundCapture;
}
