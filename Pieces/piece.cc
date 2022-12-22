#include "piece.h"
#include "../move.h"

Piece::Piece(bool isWhite, pieceType pType, int r, int c, Board *board)
    : isWhite{isWhite}, pType{pType}, r{r}, c{c}, board{board} {}

void Piece::executeMove(const Move &m) {
  r = m.destination.r;
  c = m.destination.c;
}

void Piece::undoMove(const Move &m) {
  r = m.origin.r;
  c = m.origin.c;
}