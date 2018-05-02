/** \file parcours.cpp
 *  \brief Algorithme de parcours et de tri
 */

 /**
 *  \author Stephane Achari
 */
#include <iostream>
#include <cmath>
#include <vector>
#include "compte.h"
#include "Ramapiece.hh"
#include "Piece.hh"

using namespace std;

/**
 *  \brief Algorithme de tri, recupere le tableau de piece de la classe ramapiece,
 *         tri des piece de la plus proche du bras a la plus eloigne
 *         tableau utile si on part du principe que le bras reviens a sa position apres chaque piece
 *  \return vector
 */
vector<Piece> triDistancePieceBras(Ramapiece p){
        Piece tmpPiece;
        int j = 0, i = 0, indicePetit = 0;
        double valPetit = 0.0;

        vector<Piece> *tabPiece = p.getPieces();

        for(i = 0; i<p.tabPiece->size(); i++){
            valPetite =  getDistance(tabPiece[i]->start, p.getRobotPosition());
            indicePetit = i;

            for(j = i; j<tabInt.size(); j++){
                /*On parcours tout le tableau a la recherche de la plus petite distance
                    puis on garde son indice et sa valeur pour la suite*/
                if(getDistance(tabPiece[j]->start, p.getRobotPosition()) < valPetite){
                    indicePetit = j;
                    valPetite = getDistance(tabPiece[j]->start, p.getRobotPosition());
                }
            }
            /*on echange*/
            tmpPiece = tabPiece[i];
            tabPiece[i] = valPetite;
            tabPiece[indicePetit] = tmp;
        }

        return tabPiece;
}

/**
 *  \brief Algorithme de tri, recupere la piece la plus proche du bras,
 *          puis tri des pieces par rapport a la distance entre chacunes
 * \param tableau de piece (exemple p.getPieces(), ou p est de type Ramapiece)
 * \return vector
 */
vector<Piece> triDistancePiecePiece(const std::vector<int> & tabP){

        vector<Piece> tabPiece = tabP;

        Piece tmpPiece;
        int j = 0, i = 0; indicePetit = 0;
        double valPetit = 0.0;

        for(i = 0; i<tabPiece.size(); i++)){
            if(valPetit > getDistance(tabPiece[i]->start, p.getRobotPosition())){
               indicePetit = i;
               valPetit = getDistance(tabPiece[i]->start, p.getRobotPosition());
            }
        }
        tmpPiece = tabPiece[0];
        tabPiece[0] = tabPiece[indicePetit];
        tabPiece[indicePetit] = tmpPiece;


        /*on commence a 1 car elle � l'indice 0 on a notre reference de depart,
            au fur et a mesure la reference change pour faire en fonction d'une autre piece*/

        for(i = 1; i<p.tabPiece.size(); i++){
            valPetit =  getDistance(tabPiece[0]->pos, tabPiece[i]->pos);
            indicePetit = i;

            for(j = i; j<tabInt.size(); j++){
                if(getDistance(tabPiece[i]->pos,tabPiece[j]->pos) < valPetite){
                    indicePetit = j;
                    valPetit = getDistance(tabPiece[j]->pos, p.getRobotPosition());
                }
            }
            /*on echange*/
            tmpPiece = tabPiece[i];
            tabPiece[i] = valPetit;
            tabPiece[indicePetit] = tmp;
        }

        return tabPiece;
}

/**
 *  \brief Algorithme de tri, retourne un vector de piece ordonn�e par leur valeur croissante,
 *          peut servir � une recherche dichotomique
 * \param tableau de piece (exemple p.getPieces(), ou p est de type Ramapiece)
 * \return vector
 */
vector<Piece> triValeur(const std::vector<int> & tabP){

        vector<Piece> tabPiece = tabP;

        Piece tmpPiece;
        int j = 0, i = 0; indicePetit = 0;
        int valPetit = 0;

        for(i = 0; i<p.tabPiece.size(); i++){

            valPetit =  tabPiece[j]->value;
            indicePetit = i;

            for(j = i; j<tabInt.size(); j++){
                if(tabPiece[j]->value < valPetite){
                    indicePetit = j;
                    valPetit = tabPiece[j]->value);
                }
            }
            /*on echange*/
            tmpPiece = tabPiece[i];
            tabPiece[i] = valPetit;
            tabPiece[indicePetit] = tmp;
        }

        return tabPiece;
}

/**
 *  \brief Algorithme de tri, retourne un vector de piece ordonn�e par leur valeur croissante,
 *          peut servir � une recherche dichotomique
 * \param tableau de piece (exemple p.getPieces(), ou p est de type Ramapiece)
 * \return vector
 */
vector<Piece> triValeur(const std::vector<int> & tabP){

        vector<Piece> tabPiece = tabP;

        Piece tmpPiece;
        int j = 0, i = 0; indicePetit = 0;
        int valPetit = 0;

        for(i = 0; i<p.tabPiece.size(); i++){

            valPetit =  tabPiece[j]->value;
            indicePetit = i;

            for(j = i; j<tabInt.size(); j++){
                if(tabPiece[j]->value < valPetite){
                    indicePetit = j;
                    valPetit = tabPiece[j]->value);
                }
            }
            /*on echange*/
            tmpPiece = tabPiece[i];
            tabPiece[i] = valPetit;
            tabPiece[indicePetit] = tmp;
        }

        return tabPiece;
}

/**
 *  \brief Tri dichotomique pour retrouver une piece d'une certaine valeur,
 * \param tableau de piece (exemple p.getPieces(), ou p est de type Ramapiece)
 * \param valeur de la piece recherche
 * \return int -> indice ou trouver la piece, si non trouve retourne -999
 */
int rechercheDicho(const std::vector<int> & tabP, int val){

        vector<Piece> tabPiece = triValeur(tabP);

        int indiceMax = tabPiece.size(), indiceMin = 0, indiceMil = 0;
        bool pieceTrouve = false;

        while(!pieceTrouve && (indiceMax - indiceMin) > 1){
            indiceMil = (indiceMax + indiceMin )/2;
            if(tabPiece[indiceMil]->value = val){
                pieceTrouve = trouve;
            }
            else if(val > tabPiece[indiceMil]->value){
                indiceMin = indiceMil;
            }
            else{
                indiceMax = indiceMil - 1;
            }
        }

        if(pieceTrouve){
            return tabPiece[indiceMil];
        }
        else{
            return -999;
        }
}

/**
 *  \brief Parcours basique en partant du principe que le bras ramasse une piece
 *          et reviens en position start � chaque fois
 */
void parcoursSimple(Ramapiece p){

        vector<Piece> tabPiece = triDistancePieceBras(p);

        for(int i = 0; i<tabPiece.size(); i++){
            p.pickUpPiece(tabPiece[i]);
            p.dropPieces();
        }
}

/**
 *  \brief On parcours de telle mani�re a se que le bras,
 *          aille toujours a la piece la plus proche de sa position actuelle, il fini en revenant a sa position
 */
void parcoursDesVoisins(Ramapiece p){

        vector<Piece> tabPiece = triDistancePieceBras(p.getPieces());

        for(int i = 0; i<tabPiece.size(); i++){
            p.pickUpPiece(tabPiece[i]);
        }
        p.dropPieces();
}

/**
 *  \brief On parcours de telle mani�re a faire des cercles pour se rapprocher du centre
 */
void parcoursCirculaire(Ramapiece p){
}

/**
 *  \brief Parcours par dans une zone d�finie puis change de zone
 */
void parcoursZone(Ramapiece p){
    vector<Piece> tabPiece = p.getPieces();
    vector<Piece> zoneBasGaucheTab = p.getPieces();
    vector<Piece> zoneBasDroitTab = p.getPieces();
    vector<Piece> zoneHautGaucheTab = p.getPieces();
    vector<Piece> zoneHautDroitTab = p.getPieces();

    int i = 0;

    Piece pBasGauche = tabPiece[0], pHautGauche = tabPiece[0], pBasDroit = tabPiece[0], pHautDroit = tabPiece[0];
    if(tabPiece.size() > 4){

        /*on recupere les 4 piece qui vont creer la zone global de recherche*/
        for(i = 0; tabPiece.size();i++){ //point bas droit du carre
            if(tabPiece[i]->pos.x < pBasDroit->pos.x && tabPiece[i]->pos.y < pBasDroit->pos.y){
                pBasDroit = tabPiece[i];
            }
        }

        for(i = 0; tabPiece.size();i++){ //point bas gauche du carre
            if(tabPiece[i]->pos.x > pBasGauche->pos.x && tabPiece[i]->pos.y < pBasGauche->pos.y){
                pBasGauche = tabPiece[i];
            }
        }

        for(i = 0; tabPiece.size();i++){ //point haut droit du carre
            if(tabPiece[i]->pos.x < pHautDroit->pos.x && tabPiece[i]->pos.y > pHautDroit->pos.y){
                pHautDroit = tabPiece[i];
            }
        }

        for(i = 0; tabPiece.size();i++){ //point haut gauche du carre
            if(tabPiece[i]->pos.x > pHautGauche->pos.x && tabPiece[i]->pos.y > pHautGauche->pos.y){
                pHautGauche = tabPiece[i];
            }
        }

        /*on divise la zone qu'on a creer en 4 et on repartie les piece dans chaque zone*/

        for(i = 0; tabPiece.size();i++){ //point bas droit du carre
            if(tabPiece[i]->pos.x <= (pBasDroit->pos.x + pBasGauche->pos.x)/2 && tabPiece[i]->pos.y <= (pBasDroit->pos.y + pHautDroit->pos.y)/2{
                zoneBasDroitTab.push_back(tabPiece[i]);
            }
        }

        for(i = 0; tabPiece.size();i++){ //point bas droit du carre
            if(tabPiece[i]->pos.x > (pBasDroit->pos.x + pBasGauche->pos.x)/2 && tabPiece[i]->pos.y > (pBasDroit->pos.y + pHautDroit->pos.y)/2{
                zoneHautDroitTab.push_back(tabPiece[i]);
            }
        }

        for(i = 0; tabPiece.size();i++){ //point bas droit du carre
            if(tabPiece[i]->pos.x > (pBasDroit->pos.x + pBasGauche->pos.x)/2 && tabPiece[i]->pos.y <= (pBasDroit->pos.y + pHautDroit->pos.y)/2{
                zoneBasGaucheTab.push_back(tabPiece[i]);
            }
        }
        for(i = 0; tabPiece.size();i++){ //point bas droit du carre
            if(tabPiece[i]->pos.x <= (pBasDroit->pos.x + pBasGauche->pos.x)/2 && tabPiece[i]->pos.y <= (pBasDroit->pos.y + pHautDroit->pos.y)/2{
                zoneHautGaucheTab.push_back(tabPiece[i]);
            }
        }

        /*on parcours chaque zone pour ramasser*/
        for(i = 0; zoneBasDroitTab.size(); i++){
            p.pickUpPiece(zoneBasDroitTab[i]);

        }
        for(i = 0; zoneHautDroitTab.size(); i++){
            p.pickUpPiece(zoneHautDroitTab[i]);
        }
        for(i = 0; zoneBasGaucheTab.size(); i++){
            p.pickUpPiece(zoneBasGaucheTab[i]);
        }
        for(i = 0; zoneHautGaucheTab.size(); i++){
            p.pickUpPiece(zoneHautGaucheTab[i]);
        }

        /*on depose toute les pieces*/
        p.dropPieces();
    }
}
