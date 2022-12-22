#include "rook.h"
#include "../move.h"

Rook::Rook(bool isWhite, pieceType pType, int r, int c, Board *board)
    : Piece(isWhite, pType, r, c, board) {
  value = constants::ROOK_VALUE;
}

bool Rook::findValidMoves(std::vector<Move> &validMoves,
                          std::stack<Move> &possibleMoves) {
  bool foundCapture =
      Utility::slidingMove(validMoves, possibleMoves, this, 1, 0) ||
      Utility::slidingMove(validMoves, possibleMoves, this, -1, 0) ||
      Utility::slidingMove(validMoves, possibleMoves, this, 0, 1) ||
      Utility::slidingMove(validMoves, possibleMoves, this, 0, -1);
  return foundCapture;
}