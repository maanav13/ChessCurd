#include "knight.h"

Knight::Knight(bool isWhite, pieceType pType, int r, int c, Board *board)
    : Piece(isWhite, pType, r, c, board) {
  value = constants::KNIGHT_VALUE;
}

bool Knight::findValidMoves(std::vector<Move> &validMoves,
                            std::stack<Move> &possibleMoves) {
  bool foundCapture = false;
  for (int i : {1, -1}) {
    for (int j : {2, -2}) {
      foundCapture = foundCapture ||
                     Utility::fixedMove(validMoves, possibleMoves, this, i, j);
    }
  }
  for (int i : {2, -2}) {
    for (int j : {1, -1}) {
      foundCapture = foundCapture ||
                     Utility::fixedMove(validMoves, possibleMoves, this, i, j);
    }
  }
  return foundCapture;
}