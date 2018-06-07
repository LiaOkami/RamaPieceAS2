/** \file Robot.hh
 *  \brief Classe Robot
 */

#ifndef _ROBOT_HH_INCLUDED_
#define _ROBOT_HH_INCLUDED_

# include <vector>
# include "Piece.hh"
# include "Position.hh"

/** \brief Structure repr�sentant le Robot ramassant les Piece
 *  \author Pierrick Garcia
 */
struct   Robot {
    Position            pos;
    double              speed;
    double              angle;
    Position            start;
    std::vector<Piece>  pieces;

    Robot () {}
    Robot (const Position &_pos) {pos=_pos;start=_pos;}
};

#endif // _ROBOT_HH_INCLUDED_
