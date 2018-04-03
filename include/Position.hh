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

  Position(double xx = 0, double yy = 0) { x=xx; y=yy;}
};

/** \brief Structure représentant une Position en terme d'entiers positifs
 *  \author Pierrick Garcia
 */
struct PositionInt
{
  unsigned int	x;
  unsigned int	y;
};

#endif