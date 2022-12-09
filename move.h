#ifndef MOVE_H
#define MOVE_H

#include "utility.h"

class Piece;

class Move {
    Posn origin;
    Posn destination;
    moveType mType;
    Piece * atDestination;

    Move(Posn origin, Posn destination, moveType mType, Piece *atDestination);
};

#endif