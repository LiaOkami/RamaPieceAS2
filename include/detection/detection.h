#ifndef DETECTION_H_INCLUDED
#define DETECTION_H_INCLUDED

#include "Piece.hh"
#include "Position.hh"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

//void detectionPieces();

/** \brief Classe détection, pour détecter les pièces actuellemnt sur le tapis */
class Detection
{
private:
    /** \brief Pièce actuelement sur le tapis (pour les tests) */
    Piece pieceCourante;
    /** \brief liste des pièces actuelement sur le tapis */
    vector<Piece> listePieceCourante;
    bool tapisVide;
    cv::Mat imageTapis;

public:
    //Constructeur
    Detection();

    /* ---------------------------
            Getters / Setters
       --------------------------- */

     Piece getPieceCourante(); //pour les tests

    /** \brief
     * \return la liste des pièces sur le tapis
     */
     vector<Piece> getListePieceCourante();

    /* ---------------------------
                Méthodes
       --------------------------- */

    bool ouvertureFichier(const string chemin);



    /** \brief détecte et enregistre les pièces actuellement sur le tapis
    */
    void detectionPieces();

    /** \brief trace une pièce à partir de 3 points
    */
    Piece tracerPiece3points(Position A, Position B, Position C);

    /** \brief affiche les pièces acuellement sur le tapis
    */
    void afficherPieces();
};

#endif // DETECTION_H_INCLUDED
