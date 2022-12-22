#include "move.h"
#include <iostream>

Move::Move(Posn origin, Posn destination, pieceType toPromote)
    : origin{origin}, destination{destination}, toPromote{toPromote} {}

Move::Move(std::string inputMove) {
  origin = Posn(inputMove[1] - 49, inputMove[0] - 97);
  destination = Posn(inputMove[3] - 49, inputMove[2] - 97);
  if (inputMove.length() == 5) {
    switch (inputMove[4]) {
    case 'q':
      toPromote = queen;
      break;
    case 'k':
      toPromote = knight;
      break;
    case 'b':
      toPromote = bishop;
      break;
    case 'r':
      toPromote = rook;
      break;
    case 'p':
      toPromote = pawn;
      break;
    }
  } else {
    toPromote = same;
  }
}

void Move::display() {
  std::cout << (char)(origin.c + 97) << origin.r + 1
            << (char)(destination.c + 97) << destination.r + 1 << "\n";
}