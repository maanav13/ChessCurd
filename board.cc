#include "board.h"
#include "Pieces/bishop.h"
#include "Pieces/king.h"
#include "Pieces/knight.h"
#include "Pieces/pawn.h"
#include "Pieces/piece.h"
#include "Pieces/queen.h"
#include "Pieces/rook.h"
#include "move.h"
#include <algorithm>

Board::Board() {
  for (int i : {0, 7}) {
    bool isWhite = i == 0;
    state[i][0] = new Rook(isWhite, rook, i, 0, this);
    state[i][7] = new Rook(isWhite, rook, i, 7, this);
    state[i][1] = new Knight(isWhite, knight, i, 1, this);
    state[i][6] = new Knight(isWhite, knight, i, 6, this);
    state[i][2] = new Bishop(isWhite, bishop, i, 2, this);
    state[i][5] = new Bishop(isWhite, bishop, i, 5, this);
    state[i][3] = new Queen(isWhite, queen, i, 3, this);
    state[i][4] = new King(isWhite, king, i, 4, this);
    int pawnRow = i == 0 ? 1 : 6;
    for (int j = 0; j < 8; j++) {
      state[pawnRow][j] = new Pawn(isWhite, pawn, pawnRow, j, this);
    }
  }
  for (int i = 2; i <= 5; i++) {
    for (int j = 0; j < 8; j++) {
      state[i][j] = nullptr;
    }
  }
  for (int j = 0; j < 8; j++) {
    availablePiecesWhite.insert(state[0][j]);
    availablePiecesBlack.insert(state[7][j]);
    availablePiecesWhite.insert(state[1][j]);
    availablePiecesBlack.insert(state[6][j]);
  }
  removedPiecePrediction = {};
}

Board::~Board() {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      delete state[i][j];
    }
  }
}

void promotePawn(Piece *&position, std::unordered_set<Piece *> &availablePieces,
                 Piece *origin, const Move &m) {
  availablePieces.erase(origin);
  switch (m.toPromote) {
  case queen: {
    position = new Queen(origin->isWhite, queen, m.destination.r,
                         m.destination.c, origin->board);
  } break;
  case knight: {
    position = new Knight(origin->isWhite, knight, m.destination.r,
                          m.destination.c, origin->board);
  } break;
  case bishop: {
    position = new Bishop(origin->isWhite, bishop, m.destination.r,
                          m.destination.c, origin->board);
  } break;
  case rook: {
    position = new Rook(origin->isWhite, queen, m.destination.r,
                        m.destination.c, origin->board);
  }
    availablePieces.insert(position);
  }
}

void Board::executeMove(const Move &m) {
  Piece *origin = state[m.origin.r][m.origin.c];
  Piece *destination = state[m.destination.r][m.destination.c];
  origin->executeMove(m);
  if (!destination) {
    state[m.origin.r][m.origin.c] = destination;
    state[m.destination.r][m.destination.c] = origin;
  } else if (destination && destination->isWhite != origin->isWhite) {
    if (destination->isWhite)
      availablePiecesWhite.erase(destination);
    else
      availablePiecesBlack.erase(destination);
    removedPiecePrediction.push(destination);
    state[m.origin.r][m.origin.c] = nullptr;
    state[m.destination.r][m.destination.c] = origin;
  } else if ((m.destination.r == 7 && origin->isWhite ||
              m.destination.r == 0 && !origin->isWhite) &&
             origin->pType == pawn) {
    if (origin->isWhite) {
      removedPiecePrediction.push(destination);
      promotePawn(state[m.destination.r][m.destination.c], availablePiecesWhite,
                  origin, m);
    } else {
      removedPiecePrediction.push(destination);
      promotePawn(state[m.destination.r][m.destination.c], availablePiecesBlack,
                  origin, m);
    }
  }
  state[m.origin.r][m.origin.c] = nullptr;
}

void Board::undoMove(const Move &m) {
  state[m.destination.r][m.destination.c]->undoMove(m);
  Piece *reverted = state[m.destination.r][m.destination.c];
  state[m.origin.r][m.origin.c] = reverted;
  state[m.destination.r][m.destination.c] = nullptr;
  if (removedPiecePrediction.top()->r == m.destination.r &&
      removedPiecePrediction.top()->c == m.destination.c) {
    state[m.destination.r][m.destination.c] = removedPiecePrediction.top();
    removedPiecePrediction.pop();
    Piece *restored = state[m.destination.r][m.destination.c];
    if (restored->isWhite)
      availablePiecesWhite.insert(restored);
    else
      availablePiecesBlack.insert(restored);
  }
  if (m.toPromote != same) {
    state[m.origin.r][m.origin.c] = removedPiecePrediction.top();
    removedPiecePrediction.pop();
    delete state[m.destination.r][m.destination.c];
    state[m.destination.r][m.destination.c] = nullptr;
  }
}