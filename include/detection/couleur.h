#ifndef COULEUR_H_INCLUDED
#define COULEUR_H_INCLUDED

#include <Piece.hh>
#include <opencv2/opencv.hpp>
#include <vector>
#include <string.h>
// écrit par Laureline Gagnon

 // variables gloabales stockant les Pièces de références
std::vector<Piece>      jaune;
std::vector<Piece>      rouge;
std::vector<Piece>      euro;

/** \brief Permet de trouver la couleur d'une pièce
 *
 * \param img[] cv::Mat tableau de matrices contenant les couleurs Lab de l'image
 * \param p Piece& pièce dont on doit trouver la couleur
 * \return void
 *
 */
void couleur(cv::Mat img[], Piece &p);

/** \brief calcul la distance colométrique d'une pièce avec toutes les pièces de référence
 *
 * \param p Piece pièce traitée
 * \param dist std::vector<std::vector<double> >& tableau de sauvegarde des distances
 * \return void
 *
 */
void distance(Piece p, std::vector<std::vector<double> >& dist);

/** \brief Retourne dans quel tableau (ie couleur) se trouve le minimum et le supprime de ce tableau
 *
 * \param d std::vector<double>& tableau dont on cherche le minimum
 * \param ind int& enregistre l'indice a enlevé
 * \return int
 *
 */
int mini(std::vector<double>& d);

/** \brief Permet de remplir les trois tableaux de Pièces de références
 *
 * \param nom std::string nom de l'image
 * \param choix int permet de savoir si la pièce est rouge (3), jaune(4) ou euro (1 ou 2)
 * \return int
 *
 */
int traitementImg(std::string nom, int choix);

/** \brief Modifie la valeur de l'attribut couleur des pièces du tapis
 *
 * \param nom std::string nom du fichier a traiter
 * \param pieces std::vector<Piece>& vecteur de pièces venant de la partie détection
 * \return void
 *
 */
void quelCouleur(std::string nom, std::vector<Piece>& pieces);

/** \brief Donne une valeur aléatoire en fonction de la couleur des pièces
 *
 * \param pieces std::vector<Piece>& tableau des pièces venant de la partie détection de couleur
 * \return void
 *
 */
void donnerValeur(std::vector<Piece>& pieces);

#endif // COULEUR_H_INCLUDED
