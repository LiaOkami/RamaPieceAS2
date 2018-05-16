#include "detection.h"
#include "Piece.hh"

#include <cstdlib>
#include <ctime>

#include <vector>
#include <iostream>
using namespace std;

void detectionPieces()
{
    //vector<Piece> listePieceActuel; // Vecteur de pièces retourné à la fin

    //Prend l'image (avec Cany edge detector (N)

    //transforme en tableau de points blancs (N)

    /* boucle pour detecter tous les cercles, pour plus tard*/
        //on trace un cercle avec trois points tirés aléatoirement (E)
        //nombres aléatoires
        int MIN = 0, MAX = 10; //MAX = tableau.lenght()
        srand(time(NULL));
        int alea1 = rand()%(MAX-MIN) + MIN,
            alea2 = rand()%(MAX-MIN) + MIN,
            alea3 = rand()%(MAX-MIN) + MIN;
        cout << "Nombres aléatoires : " << alea1 << ", " << alea2 << ", " << alea3 << endl;
        //Piece pieceCourante = traceCercle();

        //On compare le centre du cercle avec chaque point du tableau > on enregistre le nombre de point blanc qu'il comporte (E)
        //Boucle pour chaque point blanc

        //On  Prend le cercle avec le plus de points comme le "vrai" cercle
        //BOucle pour avec une donnée "max"
        //listePieceActuel.push_back(pieceCourante);
    /* ------- */

    //return null; //listePieceActuel;
}
