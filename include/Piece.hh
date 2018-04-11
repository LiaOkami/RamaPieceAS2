/** \file Piece.hh
 *  \brief Classe Piece
 */

#ifndef _PIECE_HH_
# define _PIECE_HH_

# include "Position.hh"

/** \brief Classe représentant une Piece
 *  \author Pierrick Garcia
 */
class Piece
{
  public:
    int         value;
    Position    pos;

    Piece(int val = 0, const Position & po = Position());
    Piece(int val, double x, double y);

    bool    operator==(const Piece &piece);
    bool    operator!=(const Piece &piece);
};

#endif
