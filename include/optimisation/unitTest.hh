/** \file unitTest.hh
 *  \brief R�alise les tests unitaires
 */

#pragma once

/** \brief Nombre de tests g�n�r�s pour chaque Algorithm
 */
#define NB_TRIES    500

/** \brief Cette fonction sert � effectuer automatiquement des tests sur les Algorithm
 *  NB_TRIES tests seront g�n�r�s al�atoirement, avec un placement al�atoire du Robot,
 *  un nombre al�atoire de Piece dont les Position et valeurs sont �galement choisies al�atoirement.
 *  Tous les Algorithm effectueront les m�mes tests, et un r�sum� de leur performance sera affich� � la fin.
 */
void    unitTest();
