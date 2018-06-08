/** \file imageParcours.h
 *  \brief Classe Image
 */

#ifndef IMAGEPARCOURS_H_INCLUDED
#define IMAGEPARCOURS_H_INCLUDED

#include <opencv2/opencv.hpp>
#include <vector>
#include "Piece.hh"

using namespace std;
using namespace cv;

/** \brief Classe g�rant l'Image repr�sentant le parcours du Robot
 *  \author St�phane Achari
 */
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
        void    afficherImage();

        /**
         *  \return Retourne la matrice de l'image
         */
        const Mat & getImage();

        /**
         *  \brief Placer les pieces sur le tapis avant ramassage
         *  \param Tableau de pieces � placer sur la table
         */
        void    placePieceImage(vector<Piece> *tabPiece);

        /**
         *  \brief Marque en bleu les Piece ramass�es
         *  \param const Position & pos Coordonn�es de la Piece
         */
        void    placePieceParcourus(const Position & pos);

         /**
         *  \brief Enregistre une image du tapis
         *  \param const string & Chemin de l'image dans laquelle enregistrer la photo du tapis actuel
         */
        void sauvegardeImage(const string &);

        /** \brief Affiche la position de d�part du Robot par un rectangle rouge
         *  \param const Position& pos Coordonn�es du Robot
         */
        void placeRobotStart(const Position &pos);

        /**
         *  \brief Repr�sente le trajet effectu� par le Robot
         *
         *  \param const Position & depart Position du bras actuelle
         *  \param const Position & arrivee Position de la Piece
         *  \param int r Couleur rouge (de 0 � 255)
         *  \param int g Couleur verte (de 0 � 255)
         *  \param int g Couleur bleue (de 0 � 255)
         *
         *  Trace un trait de couleur (r, g, b) correspondant au d�placement que le Robot aura effectu�
         */
        void deplaceRobot(Position depart, Position arrivee, int r = 0, int g = 255, int b = 0);
};

/**
    *  \brief Utilis� par certaines fonctions de la classe Image
*/
void MyFilledCircle(const Mat &img, Point center);
void MyFilledCircleRamasse(const Mat &img, Point center);

#endif // IMAGEPARCOURS_H_INCLUDED
