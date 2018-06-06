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

    /**\brief accède à la liste de pièces sur le tapis
     * \return la liste des pièces sur le tapis
     */
     vector<Piece> getListePieceCourante();

    /* ---------------------------
                Méthodes
       --------------------------- */

    /**\brief Détecte et enregistre les pièces actuellement sur le tapis
    * \param chemin (à partir du projet) de l'image du tapis à ouvrir
    * \param nombre de pièce à détecter. Si inconnu, vaut 0
    */
    void detectionPieces(const string chemin, const int nbPieces = 0);

    /**\brief Ouvre le fichier correspondant à l'image du tapis
     * \param chaine, chemin de l'image à ouvrir
     * \return booléen indiquant si l'opération a fonctionné
     */
    bool ouvertureFichier(const string chemin);

    /**\brief Détecte les contours marqués de l'image du tapis avec Canny edge detector
     * \return matrice de cv::Point des points blancs de contours détectés sur l'image du tapis
     */
    vector<cv::Point> tabContours();

    /** \brief affiche les pièces acuellement sur le tapis
    */
    void afficherPieces();
};

    /* ---------------------------
            Méthodes Externes
       --------------------------- */

    /**\brief Trace une pièce à partir de 3 positions
     * \param Trois positions de 3 points différents
     * \return Pièce tracée à partir des positions
     */
Piece tracerPiece3points(const Position A, const Position B, const Position C);

 /**\brief vérifie si deux pièces correspondent à la même pièce
     * \param 2 pièces à comparer
     * \return vrai si les pièces correspondent, faux sinon
     */
bool comparaison2Pieces(Piece piece1, Piece piece2);

 /**\brief fusionne 2 pièces
     * \param 2 pièces à fusionner
     * \return Pièce fusionnée
     */
Piece fusion2Pieces(Piece piece1, Piece piece2);

 /**\brief recherche le max d'un tableau de paires Pièce/fréquence
     * \param vecteur de paires Pièce/fréquence
     * \return index de la pièce avec le plus de points sur son tr&cé
     */
int maxTabPaire(const vector< std::pair<Piece, int> > tabPaire);

#endif // DETECTION_H_INCLUDED
