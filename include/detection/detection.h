#ifndef DETECTION_H_INCLUDED
#define DETECTION_H_INCLUDED

#include "Piece.hh"
#include "Position.hh"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>
#include <string>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>




using namespace std;

//void detectionPieces();

/** \brief Classe détection, pour détecter les pièces actuellemnt sur le tapis */
class Detection
{
private:
    vector<Piece>   listePieceCourante;
    bool            tapisVide;
    cv::Mat         imageTapis;

public:
    //Constructeur
    Detection();

    /* ---------------------------
            Getters / Setters
       --------------------------- */

    /**\brief
     * \return la liste des pièces sur le tapis
     */
     vector<Piece> getListePieceCourante();

    /* ---------------------------
                Méthodes
       --------------------------- */

    /**\brief Détecte et enregistre les pièces actuellement sur le tapis
    */
    void detectionPieces(const string chemin, const int nbPieces);

    /**\brief Ouvre le fichier correspondant à l'image du tapis
     * \param chaine, chemin de l'image à ouvrir
     * \return booléen indiquant si l'opération a fonctionné
     */
    bool ouvertureFichier(const string chemin);

    /**\brief Détecte les contours marqués de l'image du tapis avec Canny edge detector
     * \return matrice de cv::Point des points blancs de contours détectés sur l'image du tapis
     */
    vector<vector<cv::Point> > tabContours();

    /** \brief affiche les pièces acuellement sur le tapis
    */
    void afficherPieces();
};

    /* ---------------------------
            Méthodes Externes
       --------------------------- */

    /**\brief Trace une pièce à partir de 3 positions
     * \param 3 Positions
     */
Piece tracerPiece3points(Position A, Position B, Position C);

 /**\brief compare les parametre de deux pièces
     * \param
     */
bool comparaison2Pieces(Piece piece1, Piece piece2);

 /**\brief fuisionne les coordonnées de 2 pièces et retourne une piece
     * \param
     */
Piece fusion2Pieces(Piece piece1, Piece piece2);

#endif // DETECTION_H_INCLUDED
