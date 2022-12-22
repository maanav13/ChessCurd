#include "bishop.h"
#include "../move.h"

Bishop::Bishop(bool isWhite, pieceType pType, int r, int c, Board *board)
    : Piece(isWhite, pType, r, c, board) {
  value = constants::BISHOP_VALUE;
}

bool Bishop::findValidMoves(std::vector<Move> &validMoves,
                            std::stack<Move> &possibleMoves) {
  bool foundCapture =
      Utility::slidingMove(validMoves, possibleMoves, this, 1, 1) ||
      Utility::slidingMove(validMoves, possibleMoves, this, -1, -1) ||
      Utility::slidingMove(validMoves, possibleMoves, this, -1, 1) ||
      Utility::slidingMove(validMoves, possibleMoves, this, 1, -1);
  return foundCapture;
}