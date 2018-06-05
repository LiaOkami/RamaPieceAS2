#ifndef PARCOURS_H_INCLUDED
#define PARCOURS_H_INCLUDED
#include <vector>
#include "Ramapiece.hh"

using namespace std;

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
 * \param �l�ment de type Ramapiece
 * \return modifie le tableau directement via les pointeurs
 */
void    triDistancePiecePiece(Ramapiece &p);

/**
 *  \brief Surcharge de la fonction
 * \param tableau de piece
 * \return modifie le tableau directement via la r�f�rence
 */
void    triDistancePiecePiece(Ramapiece &p, vector<Piece> &tabPiece);

/**
 *  \brief Algorithme de tri, retourne un vector de piece ordonn�e par leur valeur croissante,
 *          peut servir � une recherche dichotomique
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
 *          et reviens en position start � chaque fois
 */
void    parcoursSimple(Ramapiece &p);

/**
 *  \brief On parcours de telle mani�re a se que le bras,
 *          aille toujours a la piece la plus proche de sa position actuelle, il fini en revenant a sa position
 */
void    parcoursDesVoisins(Ramapiece &p);

/**
 *  \brief D�limite une grande zone � partir de 4 pieces puis divise cette grande zone en 4
 *          Parcours par la suite chaque petite zone
 */
void    parcoursZone(Ramapiece &p);

/**
 *  \brief Semblable au parcous des voisins mais une fois arriver sur une piece,
 *          regarde autour de lui dans une zone definie si il n'y a pas d'autres pieces.
 */
void    parcoursDesVoisinsZone(Ramapiece &p);

void    parcoursBasic(Ramapiece &ramapiece);


/** \brief Utilis� pour avoir le nombre de pi�ces n�cessaire � obtenir la somme demand�e par le biai du
 *  vecteur de int en parametres, en fonction d'une entr�e de somme et d'un tableau de piece
 *
 * \param p Ramapiece& = tableau de pieces
 * \param som int = somme demand�e
 * \param vector<int> &kindPiecesRemplit = vecteur de int repr�santant les pieces � ramasser
 * \return void
 *
 */
void RamaDoable(Ramapiece &p, int som, vector<int> &kindPiecesRemplit);
#endif // PARCOURS_H_INCLUDED
