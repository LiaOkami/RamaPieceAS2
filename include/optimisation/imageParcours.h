/** \file imageParcours.h
 *  \brief Classe Image
 */

 /**
 *  \author Stephane Achari
 */

#ifndef IMAGEPARCOURS_H_INCLUDED
#define IMAGEPARCOURS_H_INCLUDED

#include <opencv2/opencv.hpp>
#include "Ramapiece.hh"
#include <vector>

using namespace std;
using namespace cv;

class Image{

    private:
        Mat _img;

    public:
        /**
         *  \brief Constructeur Image blanche, représente le tapis
         *  \param hauteur et largeur du tapis
         */
        Image(int width, int height);
        ~Image();
        /**
         *  \brief Permet d'afficher l'image du tapis
         */
        void afficherImage();
        /**
         *  \return Retourne la matrice de l'image
         */
        Mat getImage();
        /**
         *  \brief Placer les pieces sur le tapis avant ramassage
         *  \param Tableau de pieces à placer sur la table
         */
        void placePieceImage(vector<Piece> *tabPiece);
        /**
         *  \brief Marque en bleu les piece ramassé
         *  \param Les coordonnées pos x et y de la piece
         */
        void placePieceParcourus(int x, int y);
         /**
         *  \brief Enregistrer une image du tapis
         *  \param Mettre le path avec le nom de l'image dans lequel enregistrer la photo du tapis actuel
         */
        void sauvegardeImage(string);
};

void MyFilledCircle(Mat img, Point center);
void MyFilledCircleRamasse(Mat img, Point center);

#endif // IMAGEPARCOURS_H_INCLUDED
