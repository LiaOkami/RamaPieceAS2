#ifndef DETECTION_H_INCLUDED
#define DETECTION_H_INCLUDED

#include "Piece.hh"

/** \brief Fonction permettant la detection des pi�ces actuellement sur le tapis
 */
void detectionPieces();

/** \brief Classe d�tection, pour d�tecter les pi�ces actuelemnt sur le tapis */
class Detection
{
private:
    Piece pieceCourante; //pour les tests
    /** \brief liste des pi�ces actuelement sur le tapis */
    vector<Piece> listePieceCourante;
public:
    //Constructeur
    Detection();

    /* ---------------------------
            Getters / Setters
       --------------------------- */

     Piece getPieceCourante(); //pour les tests

    /** \brief
     * \return la liste des pi�ce courante
     */
     vector<Piece> getListePieceCourante();

    /* ---------------------------
                M�thodes
       --------------------------- */

    /** \brief d�tecte et enregistre les pi�ces actuellement sur le tapis
    */
    void detectionPieces();

    /** \brief affiche les pi�ces acuellement sur le tapis
    */
    void afficherPieces();
};

#endif // DETECTION_H_INCLUDED
