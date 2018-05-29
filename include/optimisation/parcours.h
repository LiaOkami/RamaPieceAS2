#ifndef PARCOURS_H_INCLUDED
#define PARCOURS_H_INCLUDED

#include "Ramapiece.hh"

/**
 *  \brief Algorithme de tri, recupere le tableau de piece de la classe ramapiece,
 *         tri des piece de la plus proche du bras a la plus eloigne
 *         tableau utile si on part du principe que le bras reviens a sa position apres chaque piece
 *  \return modifie le tableau directement via les pointeurs
 */
void    triDistancePieceBras(Ramapiece &p);

/**
 *  \brief Algorithme de tri, recupere la piece la plus proche du bras,
 *          puis tri des pieces par rapport a la distance entre chacunes
 * \param tableau de piece (exemple p.getPieces())
 * \return modifie le tableau directement via les pointeurs
 */
void    triDistancePiecePiece(Ramapiece &p);

/**
 *  \brief Algorithme de tri, retourne un vector de piece ordonnée par leur valeur croissante,
 *          peut servir à une recherche dichotomique
 * \param tableau de piece (exemple p.getPieces())
 * \return modifie le tableau directement via les pointeurs
 */
void    triValeur(std::vector<Piece> * tabP);

/**
 *  \brief Tri dichotomique pour retrouver une piece d'une certaine valeur,
 * \param tableau de piece (exemple p.getPieces(), ou p est de type Ramapiece)
 * \param valeur de la piece recherche
 * \return int -> indice ou trouver la piece, si non trouve retourne -999
 */
int     rechercheDicho(std::vector<Piece> * tabP, int val);

/**
 *  \brief Parcours basique en partant du principe que le bras ramasse une piece
 *          et reviens en position start à chaque fois
 */
void    parcoursSimple(Ramapiece &p);

/**
 *  \brief On parcours de telle manière a se que le bras,
 *          aille toujours a la piece la plus proche de sa position actuelle, il fini en revenant a sa position
 */
void    parcoursDesVoisins(Ramapiece &p);

/**
 *  \brief Délimite une grande zone à partir de 4 pieces puis divise cette grande zone en 4
 *          Parcours par la suite chaque petite zone
 */
void    parcoursZone(Ramapiece &p);

/**
 *  \brief Semblable au parcous des voisins mais une fois arriver sur une piece,
 *          regarde autour de lui dans une zone definie si il n'y a pas d'autres pieces.
 */
void    parcoursDesVoisinsZone(Ramapiece &p);

/** \brief Renvoie le nombre de pièces nécessaire à obtenir la somme demandée, en fonction d'un
tableau de piece en parametre
 *
 * \param p Ramapiece& = tableau de pieces
 * \param som int = somme demandée
 * \return void
 *
 */
void RamaDoable(Ramapiece &p, int som);

#endif // PARCOURS_H_INCLUDED
