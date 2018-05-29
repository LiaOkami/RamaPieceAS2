/** \file Piece.hh
 *  \brief Classe Piece
 */

#ifndef _PIECE_HH_
# define _PIECE_HH_

# include "Position.hh"

/** \brief Classe représentant une Piece
 *  \author Groupe 1
 */
class Piece
{
  public:
    int         value;
    Position    pos;
    String      couleur;
    int         chiffre;

    Piece(int val = 0, const Position & po = Position());
    Piece(int val, double x, double y);

    bool    operator==(const Piece &piece);
    bool    operator!=(const Piece &piece);
};

#endif
