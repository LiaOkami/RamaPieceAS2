#include "detection.h"
#include "Piece.hh"

#include <cstdlib>
#include <ctime>

#include <vector>
#include <iostream>
using namespace std;

void detectionPieces()
{
    //Prend l'image (avec Cany edge detector (N)

    //transforme en tableau de points blancs (N)

    /* boucle pour detecter tous les cercles, pour plus tard*/
        //on trace un cercle avec trois points tirés aléatoirement (E)
        //nombres aléatoires

        //Piece pieceCourante = traceCercle();

        //On compare le centre du cercle avec chaque point du tableau > on enregistre le nombre de point blanc qu'il comporte (E)
        //Boucle pour chaque point blanc

        //On  Prend le cercle avec le plus de points comme le "vrai" cercle
        //BOucle pour avec une donnée "max"
        //listePieceActuel.push_back(pieceCourante);
    /* ------- */
}

Detection::Detection(){
    pieceCourante = Piece();
    tapisVide = true;
}

Detection::getPieceCourante()
{
    return pieceCourante;
}

Detection::getListePieceCourante()
{
    if(tapisVide){
        return new vector<Piece>;
    } else {
        return listePieceCourante;
    }
}

void Detection::detectionPieces()
{
    //Prend l'image (avec Cany edge detector (Nicolas)

    //transforme en tableau de points blancs (N)

    // On cherche les pièce du tapis (Etienne)
    /* --- boucle pour detecter toutes les pièces du tapis, pour plus tard ---*/
        for(int i = 0; i < 3; i++){
            //on trace un cercle avec trois points tirés aléatoirement (E)
            //nombres aléatoires
            int MIN = 0, MAX = 10; //MAX = tableau.lenght()
            srand(time(NULL));
            int alea1 = rand()%(MAX-MIN) + MIN,
                alea2 = rand()%(MAX-MIN) + MIN,
                alea3 = rand()%(MAX-MIN) + MIN;
            cout << "Nombres aléatoires : " << alea1 << ", " << alea2 << ", " << alea3 << endl; //test
            Piece piecetracée = tracerPiece3points(pos1,pos2,pos3); //prendre les positions à partir du tableau de points

            //On compare le centre du cercle avec chaque point du tableau > on enregistre le nombre de point blanc qu'il comporte (E)
            //Boucle pour chaque point blanc
        }
        //On Cherche le cercle avec le plus de points comme le "vrai" cercle
        //BOucle pour avec une donnée "max"
        //listePieceActuel.push_back(pieceCourante);
    /* --- Fin boucle ---- */
}

void Detection::afficherPieces()
{
    //TODO
}

Piece Detection::tracerPiece3points(Position A, Position B, Position C)
{
    double yDelta_a = B.y - A.y;
    double xDelta_a = B.x - A.x;
    double yDelta_b = C.y - B.y;
    double xDelta_b = C.x - B.x;

    double aSlope = yDelta_a/xDelta_a;
    double bSlope = yDelta_b/xDelta_b;
    //Coordonées du centre
    double centreX = (aSlope*bSlope*(A.y - C.y) + bSlope*(A.x + B.x) - aSlope*(B.x+C.x) )/(2* (bSlope-aSlope) );
    double centreY = -1*(centreX - (A.x+B.x)/2)/aSlope +  (A.y+B.y)/2;
    //Rayon
    double rayon = getDistance(A, new Position(centreX, centreY));

    return new Piece(0, centreX, centreY); //àMODIFIER : doit aussi retourner le rayon de la pièce
}

