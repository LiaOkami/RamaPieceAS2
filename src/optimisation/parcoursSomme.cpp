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

//Fonction qui renvoie le nombre de pièce selon la valeur demandée

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


int     exctractionValeur(int i){
    int valeurPiece = 0;

    switch (i)
    {
        case 0:
            valeurPiece = 1;
        break;
        case 1:
            valeurPiece = 2;
        break;
        case 2:
            valeurPiece = 5;
        break;
        case 3:
            valeurPiece = 10;
        break;
        case 4:
            valeurPiece = 20;
        break;
        case 5:
            valeurPiece = 50;
        break;
        case 6:
            valeurPiece = 100;
        break;
        case 7:
            valeurPiece = 200;
        break;

        default:
        break;
    }

    return valeurPiece;
}



//Fonction qui retire une piece du tableau compteur de piece

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
    vector<int> kindPiecesRemplit;

    Piece tmpPiece;
    RamaDoable(p,somme,kindPiecesRemplit);

    //Parcours
    while(!isEmpty(kindPiecesRemplit)){

        tmpPiece = closestPiece(p.getRobotPosition(),tabPieces, kindPiecesRemplit);
        p.pickUpPiece(tmpPiece);
        removeKindPiece(kindPiecesRemplit,tmpPiece.value);
    }
    p.dropPieces();
}

bool    checkZonePiece(const vector<int>& tabNbPieceRamasse,vector<Piece>& zone){

        bool toutePiece = true;
        int i = 0, k = 0, cpt = 0, indice = 0, valeurPiece = 0;

        /*On trie les valeurs pour rendre la recherche plus rapide*/
        triValeur(&zone);

        while(i<tabNbPieceRamasse.size() && toutePiece){
        /*On récupère la valeur de la piece*/
            cpt = 0;
            valeurPiece = exctractionValeur(i);
            indice = rechercheDicho(&zone, valeurPiece);

            while(zone[indice] == valeurPiece){

                cpt++;
                indice++;
            }

            if(cpt < tabNbPieceRamasse[i]){ //verifie qu'on a bien le bon nombre de piece dans cette zone
                toutePiece = false;
            }
            i++;
        }

        return toutePiece;
}

void    parcoursZoneSomme(Ramapiece &p, int somme){
    vector<int> tabNbPieceRamasse;
    //appel a la fonction pour nous donner le nombre de piece par valeur qu'il faut
    RamaDoable(p, somme, tabNbPieceRamasse);

    vector<Piece> *tabPiece = p.getPieces();

    /*Creation de tableau pour chaque zone*/
    vector<Piece> zoneBasGaucheTab;
    vector<Piece> zoneBasDroitTab;
    vector<Piece> zoneHautGaucheTab;
    vector<Piece> zoneHautDroitTab;
    vector<Piece> tabErreur;

    int i = 0, zonePiece = 0;

    /*Initialisation des piece qui nous serviront à délimiter la zone*/
    Piece xMin = (*tabPiece)[0], xMax = (*tabPiece)[0], yMin = (*tabPiece)[0], yMax = (*tabPiece)[0];

    /*on recupere les 4 piece qui vont creer la zone global de recherche*/
    for(i = 1; i<tabPiece->size();i++){
        //Piece avec le plus petit x
        if((*tabPiece)[i].pos.x < xMin.pos.x){
            xMin = (*tabPiece)[i];
        }
        //Piece avec le plus grand x
        if((*tabPiece)[i].pos.x > xMax.pos.x){
            xMax = (*tabPiece)[i];
        }
        //Piece avec le plus petit y
        if((*tabPiece)[i].pos.y < yMin.pos.y){
            yMin = (*tabPiece)[i];
        }
        //Piece avec le plus grand y
        if((*tabPiece)[i].pos.y > yMax.pos.y){
            yMax = (*tabPiece)[i];
        }
    }

    /*on divise la zone qu'on a creer en 4 et on repartie les piece dans chaque zone*/

    for(i = 0; i<tabPiece->size();i++){
        //zone bas droit du carre
        if((*tabPiece)[i].pos.x <= (xMin.pos.x + xMax.pos.x)/2 && (*tabPiece)[i].pos.y <= (yMin.pos.y + yMax.pos.y)/2){
            zoneBasDroitTab.push_back((*tabPiece)[i]);
        }
        //zone bas gauche du carre
        else if((*tabPiece)[i].pos.x > (xMin.pos.x + xMax.pos.x)/2 && (*tabPiece)[i].pos.y <= (yMin.pos.y + yMax.pos.y)/2){
            zoneHautDroitTab.push_back((*tabPiece)[i]);
        }
        //zone haut droit du carre
        else if((*tabPiece)[i].pos.x <= (xMin.pos.x + xMax.pos.x)/2 && (*tabPiece)[i].pos.y > (yMin.pos.y + yMax.pos.y)/2){
            zoneBasGaucheTab.push_back((*tabPiece)[i]);
        }
        //zone haut gauche du carre
        else if((*tabPiece)[i].pos.x > (xMin.pos.x + xMax.pos.x)/2 && (*tabPiece)[i].pos.y > (yMin.pos.y + yMax.pos.y)/2){
            zoneHautGaucheTab.push_back((*tabPiece)[i]);
        }
        else{
            tabErreur.push_back((*tabPiece)[i]); //permet de vérifier qu'il n'y a pas de piece laissé
        }
    }

    /*On organise les tableaux pour un parcours plus optimal*/

    triDistancePiecePiece(p,zoneBasDroitTab);
    triDistancePiecePiece(p,zoneHautDroitTab);
    triDistancePiecePiece(p,zoneBasGaucheTab);
    triDistancePiecePiece(p,zoneHautGaucheTab);

    /*On test pour voir si une zone a déjà toute les pieces*/


    if(checkZonePiece(tabNbPieceRamasse, zoneBasDroitTab)){
        zonePiece = 1;
    }else if (checkZonePiece(tabNbPieceRamasse, zoneHautDroitTab)){
        zonePiece = 2;
    }else if (checkZonePiece(tabNbPieceRamasse, zoneBasGaucheTab)){
        zonePiece = 3;
    }else if (checkZonePiece(tabNbPieceRamasse, zoneHautGaucheTab)){
        zonePiece = 4;
    }else{
        zonePiece = 0;
    }
//a faire
/*
    switch (zone){
        case 0:
            valeurPiece = 1;
        break;
        case 1:
            valeurPiece = 2;
        break;
        case 2:
            valeurPiece = 5;
        break;
        case 3:
            valeurPiece = 10;
        break;
        case 4:
            valeurPiece = 20;
        break;

        default:
        break;
    }
    */
    /*on parcours chaque zone pour ramasser*/
    for(i = 0; i<zoneBasDroitTab.size(); i++){
        p.pickUpPiece(zoneBasDroitTab[i]);
    }
    for(i = 0; i<zoneHautDroitTab.size(); i++){
        p.pickUpPiece(zoneHautDroitTab[i]);
    }
    for(i = 0; i<zoneBasGaucheTab.size(); i++){
        p.pickUpPiece(zoneBasGaucheTab[i]);
    }
    for(i = 0; i<zoneHautGaucheTab.size(); i++){
        p.pickUpPiece(zoneHautGaucheTab[i]);
    }

    /*on depose toute les pieces*/
    p.dropPieces();
}

