/** \file imageParcours.h
 *  \brief Classe Image
 */

 /**
 *  \author Stephane Achari
 */

#ifndef IMAGEPARCOURS_H_INCLUDED
#define IMAGEPARCOURS_H_INCLUDED

#include <opencv2/opencv.hpp>
#include <vector>
#include "Piece.hh"

using namespace std;
using namespace cv;

class Image{

    private:
        Mat _img;

    public:
        /**
         *  \brief Constructeur Image blanche, repr�sente le tapis
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
         *  \param Tableau de pieces � placer sur la table
         */
        void placePieceImage(vector<Piece> *tabPiece);

        /**
         *  \brief Marque en bleu les piece ramass�
         *  \param Les coordonn�es pos x et y de la piece
         */
        void placePieceParcourus(int x, int y);

         /**
         *  \brief Enregistrer une image du tapis
         *  \param Mettre le path avec le nom de l'image dans lequel enregistrer la photo du tapis actuel
         *          positions x et y de la piece ramass�
         */
        void sauvegardeImage(string);

        /** \brief Affiche la position de d�part du Robot par un cercle
         *  \param const Position& pos
         */
        void placeRobotStart(const Position &pos);

        /**
         *  \brief Repr�sente le trajet effectu� par le robot via des traits
         *  \param depart : position du bras actuelle
         *          arrivee : position de la piece
         *          r,g,b pour la couleur ex : 0,255,0 pour le vert
         *          ex de fonction : img.deplaceRobot(p->getRobotPosition(),tabPiece->front().pos, 0,255,0);
         */
        void deplaceRobot(Position depart, Position arrivee, int r = 0, int g = 255, int b = 0);
};

/**
    *  \brief Utilis� par certaines fonction de la classe Image
*/
void MyFilledCircle(Mat img, Point center);
void MyFilledCircleRamasse(Mat img, Point center);

#endif // IMAGEPARCOURS_H_INCLUDED
