/** \file Piece.hh
 *  \brief Classe Piece
 */

#ifndef _PIECE_HH_
# define _PIECE_HH_

# include "Position.hh"

/** \brief Structure représentant une Piece
 *  \author Pierrick Garcia
 */
struct Piece
{
    int         value;
    Position    pos;

    Piece(int val = 0, Position po = Position())
      : value(val), pos(po) {}
    Piece(int val, double x, double y)
      : value(val), pos(Position(x, y)) {}
};

#endif
