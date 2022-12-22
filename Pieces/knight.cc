#include "knight.h"

Knight::Knight(bool isWhite, pieceType pType, int r, int c, Board *board)
    : Piece(isWhite, pType, r, c, board) {
  value = constants::KNIGHT_VALUE;
}

bool Knight::findValidMoves(std::vector<Move> &validMoves,
                            std::stack<Move> &possibleMoves) {
  return false;
}