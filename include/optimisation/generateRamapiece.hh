/** \file generateRamapiece.hh
 *  \brief Comporte le générateur aléatoire de Ramapiece
 */

#ifndef _GENERATERAMAPIECE_HH_
# define _GENERATERAMAPIECE_HH_

# include "Ramapiece.hh"

/** \brief Génère aléatoirement un Ramapiece contenant size pièces
 *
 *  \param int size Nombre de Piece sur le tapis
 *  \return Ramapiece
 *
 *  Cette fonction crée un nouvel objet Ramapiece.
 *  La Position de chaque Piece, ainsi que la Position de départ du Robot,
 *  est determinée aléatoirement avec un x et un y entre 0 et 1000.
 *  La valeur de chaque Piece est determinée aléatoirement entre 0 et 200.
 */
Ramapiece * generateRamapiece(int size);

Ramapiece * generateRamapieceNormal(int size);

#endif // _GENERATERAMAPIECE_HH_
