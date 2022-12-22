cmake_minimum_required(VERSION 3.15)

project(ChessCurd)

add_executable( chessCurd main.cc move.cc board.cc utility.cc Pieces/bishop.cc Pieces/knight.cc Pieces/pawn.cc Pieces/piece.cc Pieces/queen.cc Pieces/rook.cc )
