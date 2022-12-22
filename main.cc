#include "Pieces/bishop.h"
#include "Pieces/knight.h"
#include "Pieces/pawn.h"
#include "Pieces/piece.h"
#include "Pieces/queen.h"
#include "Pieces/rook.h"
#include "board.h"
#include "move.h"
#include "utility.h"
#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  Board *board = new Board();
  std::string color;
  std::cin >> color;
  bool isWhite = color == "white";
  std::string inputMove;
  std::vector<Move> validMoves;
  std::stack<Move> possibleMoves;
  bool foundCapturingMove = false;
  std::unordered_set<Piece *> &availablePieces =
      isWhite ? board->availablePiecesWhite : board->availablePiecesBlack;

  for (auto &u : board->availablePiecesBlack) {
    std::cout << u->r << " " << u->c << " " << u->isWhite << " " << u->pType
              << std::endl;
  }
  std::cout << "White" << std::endl;
  for (auto &u : board->availablePiecesWhite) {
    std::cout << u->r << " " << u->c << " " << u->isWhite << " " << u->pType
              << std::endl;
  }
  while (std::cin) {
    if (!isWhite) {
      std::cin >> inputMove;
      if (!std::cin) {
        break;
      }
      Move m = Move(inputMove);
      board->executeMove(m);
    }
    for (auto &onePiece : availablePieces) {
      foundCapturingMove = foundCapturingMove ||
                           onePiece->findValidMoves(validMoves, possibleMoves);
    }
    if (foundCapturingMove == false) {
      while (!possibleMoves.empty()) {
        validMoves.push_back(possibleMoves.top());
        possibleMoves.pop();
      }
    }
    for (auto &i : validMoves) {
      i.display();
      std::cout << std::endl;
    }
    if (!validMoves.empty()) {
      board->executeMove(validMoves[0]);
      validMoves[0].display();
    }
    validMoves = {};
    possibleMoves = {};
    foundCapturingMove = false;
    if (isWhite) {
      std::cin >> inputMove;
      if (!std::cin) {
        break;
      }
      Move m = Move(inputMove);
      board->executeMove(m);
    }
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        if (board->state[i][j]) {
          std::cout << board->state[i][j]->isWhite;
        } else {
          std::cout << "*";
        }
      }
      std::cout << std::endl;
    }
  }
  delete board;
}