#ifndef DETECTION_H_INCLUDED
#define DETECTION_H_INCLUDED

#include "Piece.hh"

/** \brief Fonction permettant la detection des pièces actuellement sur le tapis
 */
void detectionPieces();

/** \brief Classe détection, pour détecter les pièces actuelemnt sur le tapis */
class Detection
{
private:
    Piece pieceCourante; //pour les tests
    /** \brief liste des pièces actuelement sur le tapis */
    vector<Piece> listePieceCourante;
public:
    //Constructeur
    Detection();

    /* ---------------------------
            Getters / Setters
       --------------------------- */

     Piece getPieceCourante(); //pour les tests

    /** \brief
     * \return la liste des pièce courante
     */
     vector<Piece> getListePieceCourante();

    /* ---------------------------
                Méthodes
       --------------------------- */

    /** \brief détecte et enregistre les pièces actuellement sur le tapis
    */
    void detectionPieces();

    /** \brief affiche les pièces acuellement sur le tapis
    */
    void afficherPieces();
};

#endif // DETECTION_H_INCLUDED
