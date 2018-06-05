/** \file parcours.cpp
 *  \brief Algorithme de parcours et de tri
 */

 /**
 *  \author Stephane Achari
 */
#include <iostream>
#include <cmath>
#include <vector>
#include "Ramapiece.hh"
#include "Piece.hh"
#include "imageParcours.h"

using namespace std;

const int tailleCercleVoisin = 100;

void triDistancePieceBras(Ramapiece &p){
        Piece tmpPiece;
        int j = 0, i = 0, indicePetit = 0;
        double valPetit = 0.0;

        vector<Piece> *tabPiece = p.getPieces();

        for(i = 0; i<tabPiece->size(); i++){
            valPetit =  getDistance((*tabPiece)[i].pos, p.getRobotStart());
            indicePetit = i;

            for(j = i; j<tabPiece->size(); j++){
                /*On parcours tout le tableau a la recherche de la plus petite distance
                    puis on garde son indice et sa valeur pour la suite*/
                if(getDistance((*tabPiece)[j].pos, p.getRobotStart()) < valPetit){
                    indicePetit = j;
                    valPetit = getDistance((*tabPiece)[j].pos, p.getRobotStart());
                }
            }
            /*on echange*/
            tmpPiece = (*tabPiece)[i];
            (*tabPiece)[i] = (*tabPiece)[indicePetit];
            (*tabPiece)[indicePetit] = tmpPiece;
        }
}

void triDistancePiecePiece(Ramapiece &p){

        vector<Piece> *tabPiece = p.getPieces();

        Piece tmpPiece;
        int i, j;
        int indicePetit = 0;
        double valPetit = getDistance((*tabPiece)[0].pos, p.getRobotPosition());

        for(i = 1; i<tabPiece->size(); i++){
            if(valPetit > getDistance((*tabPiece)[i].pos, p.getRobotPosition())){
               indicePetit = i;
               valPetit = getDistance((*tabPiece)[i].pos, p.getRobotPosition());
            }
        }
        /*On recupere la piece la plus proche du robot*/
        tmpPiece = (*tabPiece)[0];
        (*tabPiece)[0] = (*tabPiece)[indicePetit];
        (*tabPiece)[indicePetit] = tmpPiece;


        /*on commence a 1 car elle à l'indice 0 on a notre reference de depart,
            au fur et a mesure la reference change pour faire en fonction d'une autre piece*/

        for(i = 1; i<tabPiece->size(); i++){
            valPetit =  getDistance((*tabPiece)[i - 1].pos, (*tabPiece)[i].pos);
            indicePetit = i;

            for(j = i + 1; j<tabPiece->size(); j++){
                if(getDistance((*tabPiece)[i - 1].pos, (*tabPiece)[j].pos) < valPetit){
                    indicePetit = j;
                    valPetit = getDistance((*tabPiece)[i - 1].pos, (*tabPiece)[j].pos);
                }
            }
            /*on echange*/
            tmpPiece = (*tabPiece)[i];
            (*tabPiece)[i] = (*tabPiece)[indicePetit];
            (*tabPiece)[indicePetit] = tmpPiece;
        }
}

void triValeur(std::vector<Piece> * tabP){

        vector<Piece> *tabPiece = tabP;

        Piece tmpPiece;
        int j = 0, i = 0, indicePetit = 0;
        int valPetit = 0;

        for(i = 0; i<tabPiece->size(); i++){

            valPetit =  (*tabPiece)[j].value;
            indicePetit = i;

            for(j = i; j<tabPiece->size(); j++){
                if((*tabPiece)[j].value < valPetit){
                    indicePetit = j;
                    valPetit = (*tabPiece)[j].value;
                }
            }
            /*on echange*/
            tmpPiece = (*tabPiece)[i];
            (*tabPiece)[i] = valPetit;
            (*tabPiece)[indicePetit] = tmpPiece;
        }
}

int rechercheDicho(std::vector<Piece> * tabP, int val){

        vector<Piece> *tabPiece = tabP;
        triValeur(tabPiece);

        int indiceMax = tabPiece->size(), indiceMin = 0, indiceMil = 0;
        bool pieceTrouve = false;

        while(!pieceTrouve && (indiceMax - indiceMin) > 1){
            indiceMil = (indiceMax + indiceMin )/2;
            if((*tabPiece)[indiceMil].value == val){
                pieceTrouve = true;
            }
            else if(val > (*tabPiece)[indiceMil].value){
                indiceMin = indiceMil;
            }
            else{
                indiceMax = indiceMil - 1;
            }
        }

        if(pieceTrouve){
            return indiceMil;
        }
        else{
            return -999;
        }
}

void parcoursSimple(Ramapiece &p){
        triDistancePieceBras(p);
        vector<Piece> *tabPiece = p.getPieces();

        while (tabPiece->size() > 0) {
            p.pickUpPiece(tabPiece->front());
            p.dropPieces();
        }
}

void parcoursDesVoisins(Ramapiece &p){

        triDistancePiecePiece(p);
        vector<Piece> *tabPiece = p.getPieces();

        while (tabPiece->size() > 0) {
            p.pickUpPiece(tabPiece->front()); // vector->front() == (*vector)[0]
        }
        p.dropPieces();
}

void parcoursZone(Ramapiece &p){
    vector<Piece> *tabPiece = p.getPieces();

    /*Creation de tableau pour chaque zone*/
    vector<Piece> zoneBasGaucheTab;
    vector<Piece> zoneBasDroitTab;
    vector<Piece> zoneHautGaucheTab;
    vector<Piece> zoneHautDroitTab;
    vector<Piece> tabErreur;

    int i = 0;

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

void parcoursDesVoisinsZone(Ramapiece &p){

    triDistancePiecePiece(p);
    vector<Piece> *tabPiece = p.getPieces();
    vector<Piece> tabPieceProvisoir = {};

    while (tabPiece->size() > 0) {
        p.pickUpPiece(tabPiece->front()); //correspond a la premiere case du tableau

        //On regarde si dans la zone autour du bras il y a des pieces
        for(int i =0; i<tabPiece->size(); i++){
            if(getDistance((*tabPiece)[i].pos,p.getRobotPosition()) <= tailleCercleVoisin){
                tabPieceProvisoir.push_back((*tabPiece)[i]);
            }
            //On ramasse toute les pieces dans la zone
            for(const Piece & piece:tabPieceProvisoir){
                p.pickUpPiece(piece);
            }
        }
        //On vide le tableau temporaire
        tabPieceProvisoir.clear();
        //On recalcule le tableau
        triDistancePiecePiece(p);
        //*tabPiece = p.getPieces();
    }
    p.dropPieces();
}
