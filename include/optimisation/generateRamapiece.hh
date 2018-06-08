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
/** \brief Génère aléatoirement un Ramapiece contenant size pièces en EUR

 *
 *  \param int size Nombre de Piece sur le tapis
 *  \return Ramapiece
 *
 *  Cette fonction crée un nouvel objet Ramapiece.
 *  Elle fonctionne de la même manière que generateRamapiece,
 *  mais la valeur donnée en pièces doît correspondre à une pièce EUR.
 *  La valeur est donnée en centimes, les valeurs possibles sont donc 1, 2, 5, 10, 20, 50, 100 et 200.
 */
Ramapiece * generateRamapieceNormal(int size);

#endif // _GENERATERAMAPIECE_HH_
