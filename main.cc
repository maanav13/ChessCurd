#include "Pieces/bishop.h"
#include "Pieces/knight.h"
#include "Pieces/pawn.h"
#include "Pieces/piece.h"
#include "Pieces/queen.h"
#include "Pieces/rook.h"
#include "board.h"
#include "move.h"
#include "utility.h"
#include <cstdlib>
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

  while (std::cin) {
    if (!isWhite) {
      std::cin >> inputMove;
      if (!std::cin) {
        break;
      }
      Move m = Move(inputMove);
      if (inputMove == "e8c8") {
        Move m1 = Move("a8d8");
        board->executeMove(m1);
      } else if (inputMove == "e8g8") {
        Move m1 = Move("h8f8");
        board->executeMove(m1);
      }
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
    if (!validMoves.empty()) {
      int moveNum = rand() % validMoves.size();
      board->executeMove(validMoves[moveNum]);
      validMoves[moveNum].display();
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
      if (inputMove == "e1c1") {
        Move m1 = Move("a1d1");
        board->executeMove(m1);
      } else if (inputMove == "e1g1") {
        Move m1 = Move("h1f1");
        board->executeMove(m1);
      }
      board->executeMove(m);
    }
  }
  delete board;
}