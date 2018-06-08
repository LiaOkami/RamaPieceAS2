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

/** \brief Classe gérant l'Image représentant le parcours du Robot
 *  \author Stéphane Achari
 */
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
        void    afficherImage();

        /**
         *  \return Retourne la matrice de l'image
         */
        const Mat & getImage();

        /**
         *  \brief Placer les pieces sur le tapis avant ramassage
         *  \param Tableau de pieces à placer sur la table
         */
        void    placePieceImage(vector<Piece> *tabPiece);

        /**
         *  \brief Marque en bleu les Piece ramassées
         *  \param const Position & pos Coordonnées de la Piece
         */
        void    placePieceParcourus(const Position & pos);

         /**
         *  \brief Enregistre une image du tapis
         *  \param const string & Chemin de l'image dans laquelle enregistrer la photo du tapis actuel
         */
        void sauvegardeImage(const string &);

        /** \brief Affiche la position de départ du Robot par un rectangle rouge
         *  \param const Position& pos Coordonnées du Robot
         */
        void placeRobotStart(const Position &pos);

        /**
         *  \brief Représente le trajet effectué par le Robot
         *
         *  \param const Position & depart Position du bras actuelle
         *  \param const Position & arrivee Position de la Piece
         *  \param int r Couleur rouge (de 0 à 255)
         *  \param int g Couleur verte (de 0 à 255)
         *  \param int g Couleur bleue (de 0 à 255)
         *
         *  Trace un trait de couleur (r, g, b) correspondant au déplacement que le Robot aura effectué
         */
        void deplaceRobot(Position depart, Position arrivee, int r = 0, int g = 255, int b = 0);
};

/**
    *  \brief Utilisé par certaines fonctions de la classe Image
*/
void MyFilledCircle(const Mat &img, Point center);
void MyFilledCircleRamasse(const Mat &img, Point center);

#endif // IMAGEPARCOURS_H_INCLUDED
