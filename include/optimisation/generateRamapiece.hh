/** \file generateRamapiece.hh
 *  \brief Comporte le g�n�rateur al�atoire de Ramapiece
 */

#ifndef _GENERATERAMAPIECE_HH_
# define _GENERATERAMAPIECE_HH_

# include "Ramapiece.hh"

/** \brief G�n�re al�atoirement un Ramapiece contenant size pi�ces
 *
 *  \param int size Nombre de Piece sur le tapis
 *  \return Ramapiece
 *
 *  Cette fonction cr�e un nouvel objet Ramapiece.
 *  La Position de chaque Piece, ainsi que la Position de d�part du Robot,
 *  est determin�e al�atoirement avec un x et un y entre 0 et 1000.
 *  La valeur de chaque Piece est determin�e al�atoirement entre 0 et 200.
 */
Ramapiece * generateRamapiece(int size);
/** \brief G�n�re al�atoirement un Ramapiece contenant size pi�ces en EUR

 *
 *  \param int size Nombre de Piece sur le tapis
 *  \return Ramapiece
 *
 *  Cette fonction cr�e un nouvel objet Ramapiece.
 *  Elle fonctionne de la m�me mani�re que generateRamapiece,
 *  mais la valeur donn�e en pi�ces do�t correspondre � une pi�ce EUR.
 *  La valeur est donn�e en centimes, les valeurs possibles sont donc 1, 2, 5, 10, 20, 50, 100 et 200.
 */
Ramapiece * generateRamapieceNormal(int size);

#endif // _GENERATERAMAPIECE_HH_
