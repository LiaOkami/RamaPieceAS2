#ifndef COULEUR_H_INCLUDED
#define COULEUR_H_INCLUDED

#include <opencv2/opencv.hpp>
#include <vector>
#include <string.h>
// �crit par Laureline Gagnon

/** \brief
 *  fonction principale appel�e dans le programme principal, � la fin de son ex�cution les Pi�ces ont �t� mises � jour avec la valeur
 * \param nom std::string nom du fichier a traiter
 * \param pieces vector<Piece> liste des Pi�ces d�tect�es pr�c�demment
 * \return void
 *
 */
void quelCouleur(std::string nom, vector<Piece> pieces);

/** \brief
 *  fonction permettant de traiter une pi�ce de l'image
 * \param img cv::Mat
 * \param p Piece
 * \return void
 *
 */
void couleur(cv::Mat img, Piece p);

#endif // COULEUR_H_INCLUDED
