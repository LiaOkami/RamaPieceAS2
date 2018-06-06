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

    /**\brief acc�de � la liste de pi�ces sur le tapis
     * \return la liste des pi�ces sur le tapis
     */
     vector<Piece> getListePieceCourante();

    /* ---------------------------
                M�thodes
       --------------------------- */

    /**\brief D�tecte et enregistre les pi�ces actuellement sur le tapis
    * \param chemin (� partir du projet) de l'image du tapis � ouvrir
    * \param nombre de pi�ce � d�tecter. Si inconnu, vaut 0
    */
    void detectionPieces(const string chemin, const int nbPieces = 0);

    /**\brief Ouvre le fichier correspondant � l'image du tapis
     * \param chaine, chemin de l'image � ouvrir
     * \return bool�en indiquant si l'op�ration a fonctionn�
     */
    bool ouvertureFichier(const string chemin);

    /**\brief D�tecte les contours marqu�s de l'image du tapis avec Canny edge detector
     * \return matrice de cv::Point des points blancs de contours d�tect�s sur l'image du tapis
     */
    vector<cv::Point> tabContours();

    /** \brief affiche les pi�ces acuellement sur le tapis
    */
    void afficherPieces();
};

    /* ---------------------------
            M�thodes Externes
       --------------------------- */

    /**\brief Trace une pi�ce � partir de 3 positions
     * \param Trois positions de 3 points diff�rents
     * \return Pi�ce trac�e � partir des positions
     */
Piece tracerPiece3points(const Position A, const Position B, const Position C);

 /**\brief v�rifie si deux pi�ces correspondent � la m�me pi�ce
     * \param 2 pi�ces � comparer
     * \return vrai si les pi�ces correspondent, faux sinon
     */
bool comparaison2Pieces(Piece piece1, Piece piece2);

 /**\brief fusionne 2 pi�ces
     * \param 2 pi�ces � fusionner
     * \return Pi�ce fusionn�e
     */
Piece fusion2Pieces(Piece piece1, Piece piece2);

 /**\brief recherche le max d'un tableau de paires Pi�ce/fr�quence
     * \param vecteur de paires Pi�ce/fr�quence
     * \return index de la pi�ce avec le plus de points sur son tr&c�
     */
int maxTabPaire(const vector< std::pair<Piece, int> > tabPaire);

#endif // DETECTION_H_INCLUDED
