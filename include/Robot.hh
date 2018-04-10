/** \file Robot.hh
 *  \brief Classe Robot
 */

#ifndef _ROBOT_HH_INCLUDED_
#define _ROBOT_HH_INCLUDED_

# include <vector>
# include "Piece.hh"
# include "Position.hh"

class   Robot {
  private:
    Position            pos;
    double              speed;
    double              angle;
    std::vector<Piece>  pieces;
};

#endif // _ROBOT_HH_INCLUDED_
