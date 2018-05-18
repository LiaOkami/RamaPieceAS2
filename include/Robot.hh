/** \file Robot.hh
 *  \brief Classe Robot
 */

#ifndef _ROBOT_HH_INCLUDED_
#define _ROBOT_HH_INCLUDED_

# include <vector>
# include "Piece.hh"
# include "Position.hh"

struct   Robot {
    Position            pos;
    double              speed;
    double              angle;
    Position            start;
    std::vector<Piece>  pieces;

    Robot (const Position &_pos) {pos=_pos;start=_pos;}
};

#endif // _ROBOT_HH_INCLUDED_
