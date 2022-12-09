#include "move.h"

Move::Move(Posn origin, Posn destination, moveType mType, Piece *atDestination) : origin{origin}, destination{destination}, mType{mType}, atDestination{atDestination} {}