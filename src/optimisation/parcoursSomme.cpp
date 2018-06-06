/** \file parcoursSomme.cpp
 *  \brief Algorithme de parcours avec le mode de fonctionnement somme
 */

 /**
 *  \author Stephane Achari/Nicolas Charlon
 */
#include <iostream>
#include <cmath>
#include <vector>
#include "Ramapiece.hh"
#include "Piece.hh"
#include "parcours.h"

void    parcoursZoneSomme(Ramapiece &p, int somme){
    triDistancePieceBras(p);
    vector<int> kindPiecesRemplit(8);
    vector<Piece> *tabPiece = p.getPieces();

        Piece tmpPiece;
        int i, j;
        int indicePetit = 0;
        double valPetit = getDistance((*tabPiece)[0].pos, p.getRobotPosition());


    RamaDoable(p,somme,kindPiecesRemplit);
    while( isEmpty(kindPiecesRemplit)){
    //creer tableau de pieces avec que les pieces de valeurs d'interet
    //get la valeur de position de toutes les pieces d'un meme type pour
    //prendre la piece avec la distance la plus faible
    //fonction getVal ? getMoney ?



    }
}


