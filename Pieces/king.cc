#include "king.h"

King::King(bool isWhite, pieceType pType, int r, int c, Board *board)
    : Piece(isWhite, pType, r, c, board) {
  value = constants::KING_VALUE;
}

bool King::findValidMoves(std::vector<Move> &validMoves,
                          std::stack<Move> &possibleMoves) {
  bool foundCapture =
      Utility::fixedMove(validMoves, possibleMoves, this, 0, 1) ||
      Utility::fixedMove(validMoves, possibleMoves, this, 1, 1) ||
      Utility::fixedMove(validMoves, possibleMoves, this, -1, 1) ||
      Utility::fixedMove(validMoves, possibleMoves, this, -1, 0) ||
      Utility::fixedMove(validMoves, possibleMoves, this, -1, -1) ||
      Utility::fixedMove(validMoves, possibleMoves, this, 0, -1) ||
      Utility::fixedMove(validMoves, possibleMoves, this, 1, -1) ||
      Utility::fixedMove(validMoves, possibleMoves, this, 1, 0);
  return foundCapture;
}