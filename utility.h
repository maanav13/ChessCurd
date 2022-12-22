#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <stack>
#include <vector>

class Move;
class Piece;

namespace constants {
inline const double ROOK_VALUE = 4;
inline const double KNIGHT_VALUE = 3;
inline const double BISHOP_VALUE = 3;
inline const double QUEEN_VALUE = 6;
inline const double PAWN_VALUE = 1;

} // namespace constants

enum moveType { move, capture, promotion, capture_promotion };

enum pieceType { pawn, rook, knight, bishop, queen, king, same };
struct Posn {
  int r, c;

  Posn();
  Posn(int r, int c);
};

namespace Utility {
bool slidingMove(std::vector<Move> &validMoves, std::stack<Move> &possibleMoves,
                 Piece *p, int rowOffset, int colOffset);
}

#endif