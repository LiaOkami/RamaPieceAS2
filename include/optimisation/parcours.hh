/** \file parcours.hh
 *  \brief Liste les parcours disponible pour RamapieceAlgorithm
 */

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
 *          puis trie des pieces par rapport a la distance entre chacunes
 *  \param �l�ment de type Ramapiece
 *  \return modifie le tableau directement via les pointeurs
 */
void    triDistancePiecePiece(Ramapiece &p);

/**
 *  \brief Surcharge de la fonction
 *
 *  \param Ramapiece& p
 *  \param vector<Piece>& tabPiece
 *
 *  Cette fonction modifie le tableau pris en r�f�rence
 */
void    triDistancePiecePiece(Ramapiece &p, vector<Piece> &tabPiece);

/**
 *  \brief Algorithme de tri, retourne un vector de piece ordonn�e par leur valeur croissante,
 *          peut servir � une recherche dichotomique
 *  \param tableau de piece (exemple p.getPieces())
 *  \return modifie le tableau directement via les pointeurs
 */
void    triValeur(std::vector<Piece> * tabP);

/**
 *  \brief Tri dichotomique pour retrouver une piece d'une certaine valeur,
 *
 *  \param tableau de piece (exemple p.getPieces(), ou p est de type Ramapiece)
 *  \param valeur de la piece recherche
 *  \return int Indice o� trouver la piece, si aucune pi�ces n'est trouv�e, retourne -999
 */
int     rechercheDicho(std::vector<Piece> * tabP, int val);

/**
 *  \brief Parcours basique en partant du principe que le bras ramasse une Piece
 *          et revient en position start � chaque fois
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

/**
 *  \brief Parcours des Voisons avec une somme pr�cise � ramasser
 *  \param Objet de type Ramapiece
 *  \param int, la somme � ramasser
 */
void    parcoursVoisinsSomme(Ramapiece &p, int somme);

/** \brief Utilis� pour savoir si le tableau est vide
 *
 * \param vector<int> &kindPieces Remplit est un vecteur de int repr�santant un tableau de comptage de pieces, de 1 centime �
 * 2 euros
 * \return bool�en, vrai si tableau vide, faux sinon
 *
 */

bool isEmpty(vector<int> kindPieces);

/** \brief Utilis� pour avoir le nombre de pi�ces n�cessaire � obtenir la somme demand�e par le biai du
 *  vecteur de int en parametres, en fonction d'une entr�e de somme et d'un tableau de piece
 *
 * \param p Ramapiece& est un tableau de pieces
 * \param som int correspond � la somme demand�e
 * \param vector<int> &kindPiecesRemplit = vecteur de int repr�santant les pieces � ramasser
 * \return void
 *
 */
void RamaDoable(Ramapiece &p, int som, vector<int> &kindPiecesRemplit);

/**
 *  \brief Parcours des zones avec une somme pr�cise � ramasser
 *  \param Objet de type Ramapiece
 *  \param int, la somme � ramasser
 */
void    parcoursZoneSomme(Ramapiece &p, int somme);

/**
 *  \brief Parcours une zone determin� par parcoursZoneSomme
 *  \param Objet de type Ramapiece
 *  \param vector<piece> correspondant a la zone
 *  \param vector<int> &tabNbPieceRamasse = vecteur de int repr�santant les pieces � ramasser
 */
void    parcoursZonePiece(vector<Piece> &zone, Ramapiece &p, vector<int> &tabNbPieceRamasse);

/**
 *  \brief Verifie si une zone comporte toute les pi�ce dont on a besoin
 *  \param Objet de type Ramapiece
 *  \param vector<piece> correspondant a la zone
 *  \param vector<int> &tabNbPieceRamasse = vecteur de int repr�santant les pieces � ramasser
 *  \return bool
 */
bool    checkZonePiece(const vector<int>& tabNbPieceRamasse, vector<Piece>& zone);

/**
 *  \brief Permet de d�finir la valeur de la pi�ce recherch�
 *  \param int -> correspond � k'indice du tableau, entre 0 et 7
 *  \return int -> valeur de la piece
 */
int     exctractionValeur(int i);

#endif // PARCOURS_H_INCLUDED
