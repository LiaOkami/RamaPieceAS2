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
    /** \brief Pi�ce actuelement sur le tapis (pour les tests) */
    Piece pieceCourante;
    /** \brief liste des pi�ces actuelement sur le tapis */
    vector<Piece> listePieceCourante;
    bool tapisVide;
public:
    //Constructeur
    Detection();

    /* ---------------------------
            Getters / Setters
       --------------------------- */

     Piece getPieceCourante(); //pour les tests

    /** \brief
     * \return la liste des pi�ces sur le tapis
     */
     vector<Piece> getListePieceCourante();

    /* ---------------------------
                M�thodes
       --------------------------- */

    /** \brief d�tecte et enregistre les pi�ces actuellement sur le tapis
    */
    void detectionPieces();

    /** \brief trace une pi�ce � partir de 3 points
    */
    Piece tracerPiece3points(Position A, Position B, Position C);

    /** \brief affiche les pi�ces acuellement sur le tapis
    */
    void afficherPieces();
};

#endif // DETECTION_H_INCLUDED
