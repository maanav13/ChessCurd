#ifndef MOVE_H
#define MOVE_H

#include "utility.h"
#include <string>
class Piece;

class Move {
public:
  Posn origin;
  Posn destination;
  pieceType toPromote;

  Move(Posn origin, Posn destination, pieceType toPromote);

  Move(std::string inputMove);

  void display();
};

#endif