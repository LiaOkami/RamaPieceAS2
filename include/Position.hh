/** \file Position.hh
 *  \brief Classe Position
 */

#ifndef _POSITION_HH_
# define _POSITION_HH_

# include <stdint.h>

/** \brief Structure représentant la Position d'un Object
 *  \author Pierrick Garcia
 */
struct Position
{
  double	x;
  double	y;

  Position(double xx = 0, double yy = 0);
};

/** \brief Retourne la distance entre deux Position
 *
 * \param const Position& pos1
 * \param const Position& pos2
 * \return double
 */
double  getDistance(const Position & pos1, const Position & pos2);

#endif
