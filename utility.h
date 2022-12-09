#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace constants {
    inline const double ROOK_VALUE = 4;
    inline const double KNIGHT_VALUE = 2;
    inline const double BISHOP_VALUE = 2;
    inline const double QUEEN_VALUE = 6;
}

enum moveType { move, capture, promotion };

struct Posn {
    int x, y;

    Posn(int x, int y);
};

#endif