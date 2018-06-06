/** \file Position.hh
 *  \brief Classe Position
 */

#ifndef _POSITION_HH_
# define _POSITION_HH_

# include <iostream>
# include <stdint.h>

/** \brief Classe représentant la Position d'un Object
 *  \author Pierrick Garcia
 */
class Position
{
  public:
    double	x;
    double	y;

    Position(double xx = 0, double yy = 0);

    bool    operator==(const Position &pos);
    bool    operator!=(const Position &pos);
};

/** \brief Retourne la distance entre deux Position
 *
 * \param const Position& pos1
 * \param const Position& pos2
 * \return double
 */
double  getDistance(const Position & pos1, const Position & pos2);

std::ostream &   operator<<(std::ostream &os, const Position &pos);

#endif
