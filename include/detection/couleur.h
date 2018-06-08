#ifndef COULEUR_H_INCLUDED
#define COULEUR_H_INCLUDED

#include <opencv2/opencv.hpp>
#include <vector>
#include <string.h>
// écrit par Laureline Gagnon

/** \brief
 *  fonction principale appelée dans le programme principal, à la fin de son exécution les Pièces ont été mises à jour avec la valeur
 * \param nom std::string nom du fichier a traiter
 * \param pieces vector<Piece> liste des Pièces détectées précédemment
 * \return void
 *
 */
void quelCouleur(std::string nom, vector<Piece> pieces);

/** \brief
 *  fonction permettant de traiter une pièce de l'image
 * \param img cv::Mat
 * \param p Piece
 * \return void
 *
 */
void couleur(cv::Mat img, Piece p);

#endif // COULEUR_H_INCLUDED
