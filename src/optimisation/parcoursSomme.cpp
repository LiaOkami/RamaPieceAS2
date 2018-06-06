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
static int getKindPiecesValue(const vector<int> &kindPiecesRemplit,  int value){
    switch(value){
    case 1:
        return kindPiecesRemplit[0];
        break;
    case 2:
        return kindPiecesRemplit[1];
        break;
    case 5:
        return kindPiecesRemplit[2];
        break;
    case 10:
        return kindPiecesRemplit[3];
        break;
    case 20:
        return kindPiecesRemplit[4];
        break;
    case 50:
        return kindPiecesRemplit[5];
        break;
    case 100:
        return kindPiecesRemplit[6];
        break;
    case 200:
        return kindPiecesRemplit[7];
        break;
    }

}

static void removeKindPiece(vector<int> &kindPiecesRemplit,  int value){
    switch(value){
    case 1:
        kindPiecesRemplit[0] -= 1;
        break;
    case 2:
        kindPiecesRemplit[1] -= 1;
        break;
    case 5:
        kindPiecesRemplit[2] -= 1;
        break;
    case 10:
        kindPiecesRemplit[3] -= 1;
        break;
    case 20:
        kindPiecesRemplit[4] -= 1;
        break;
    case 50:
        kindPiecesRemplit[5] -= 1;
        break;
    case 100:
        kindPiecesRemplit[6] -= 1;
        break;
    case 200:
        kindPiecesRemplit[7] -= 1;
        break;
    }

}


Piece   closestPiece(const Position & robotPos,
                             std::vector<Piece> *pieces,
                             const std::vector<int> & kindPiecesRemplit)
{
    Piece   minPiece;
    double  minDist = -1;

    for (const Piece &piece:*pieces) {
        //std::cout << "Piece : " << piece.value << std::endl;
        if (getKindPiecesValue(kindPiecesRemplit, piece.value) > 0)
        {
            if (getDistance(piece.pos, robotPos) < minDist || minDist == -1)
            {
                minPiece = piece;
                minDist = getDistance(piece.pos, robotPos);
            }
        }
    }
    return minPiece;
}

void    parcoursVoisinsSomme(Ramapiece &p, int somme){
    std::vector<Piece> *tabPieces = p.getPieces();
    //triDistancePiecePiece(p);
    vector<int> kindPiecesRemplit;

    Piece tmpPiece;
    RamaDoable(p,somme,kindPiecesRemplit); // T'as une case en trop faut tu fix ça kthxbye
     //Parcours
    while(!isEmpty(kindPiecesRemplit)){
    //creer tableau de pieces avec que les pieces de valeurs d'interet
    //get la valeur de position de toutes les pieces d'un meme type pour
    //prendre la piece avec la distance la plus faible
    //fonction getVal ? getMoney ?
        tmpPiece = closestPiece(p.getRobotPosition(),tabPieces, kindPiecesRemplit);
        p.pickUpPiece(tmpPiece);
        removeKindPiece(kindPiecesRemplit,tmpPiece.value);
    }
    p.dropPieces();
}


