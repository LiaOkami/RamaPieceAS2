#include "detection.h"
#include "Piece.hh"

#include <vector>
#include <iostream>
using namespace std;

vector<Piece> detectionPieces()
{
    vector<Piece> listePieceActuel; // Vecteur de pièces retourné à la fin

    //Prend l'image (avec Cany edge detector)

    //transforme en tableau de points blancs

    /* boucle pour detecter tous les cercles, pour plus tard*/
        //on trace un cercle avec trois points tirés aléatoirement (E)
        int alea1, alea2, alea3;
        //Piece pieceCourante = traceCercle();

        //On compare le centre du cercle avec chaque point du tableau > on enregistre le nombre de point blanc qu'il comporte

        //On  Prend le cercle avec le plus de points comme le "vrai" cercle

    /* ------- */


    listePieceActuel.push_back(pieceCourante);

    return listePieceActuel;
}
