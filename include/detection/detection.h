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

/** \brief Classe d�tection, pour d�tecter les pi�ces actuellemnt sur le tapis */
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
     * \return la liste des pi�ces sur le tapis
     */
     vector<Piece> getListePieceCourante();

    /* ---------------------------
                M�thodes
       --------------------------- */

    /**\brief D�tecte et enregistre les pi�ces actuellement sur le tapis
    */
    void detectionPieces(const string chemin, const int nbPieces);

    /**\brief Ouvre le fichier correspondant � l'image du tapis
     * \param chaine, chemin de l'image � ouvrir
     * \return bool�en indiquant si l'op�ration a fonctionn�
     */
    bool ouvertureFichier(const string chemin);

    /**\brief D�tecte les contours marqu�s de l'image du tapis avec Canny edge detector
     * \return matrice de cv::Point des points blancs de contours d�tect�s sur l'image du tapis
     */
    vector<vector<cv::Point> > tabContours();

    /** \brief affiche les pi�ces acuellement sur le tapis
    */
    void afficherPieces();
};

    /* ---------------------------
            M�thodes Externes
       --------------------------- */

    /**\brief Trace une pi�ce � partir de 3 positions
     * \param 3 Positions
     */
Piece tracerPiece3points(Position A, Position B, Position C);

 /**\brief compare les parametre de deux pi�ces
     * \param
     */
bool comparaison2Pieces(Piece piece1, Piece piece2);

 /**\brief fuisionne les coordonn�es de 2 pi�ces et retourne une piece
     * \param
     */
Piece fusion2Pieces(Piece piece1, Piece piece2);

#endif // DETECTION_H_INCLUDED
