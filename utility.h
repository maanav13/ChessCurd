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
inline const double KING_VALUE = 6;
inline const double PAWN_VALUE = 1;

} // namespace constants

enum pieceType { pawn, rook, knight, bishop, queen, king, same };
struct Posn {
  int r, c;

  Posn();
  Posn(int r, int c);
};

namespace Utility {
bool slidingMove(std::vector<Move> &validMoves, std::stack<Move> &possibleMoves,
                 Piece *p, int rowOffset, int colOffset);
bool fixedMove(std::vector<Move> &validMoves, std::stack<Move> &possibleMoves,
               Piece *p, int rowOffset, int colOffset);
} // namespace Utility

#endif