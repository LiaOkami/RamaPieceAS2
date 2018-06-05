/** \file unitTest.hh
 *  \brief Réalise les tests unitaires
 */

#pragma once

/** \brief Nombre de tests générés pour chaque Algorithm
 */
#define NB_TRIES    500

/** \brief Cette fonction sert à effectuer automatiquement des tests sur les Algorithm
 *  NB_TRIES tests seront générés aléatoirement, avec un placement aléatoire du Robot,
 *  un nombre aléatoire de Piece dont les Position et valeurs sont également choisies aléatoirement.
 *  Tous les Algorithm effectueront les mêmes tests, et un résumé de leur performance sera affiché à la fin.
 */
void    unitTest();
