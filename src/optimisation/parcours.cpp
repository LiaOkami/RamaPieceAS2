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

using namespace std;

    const int tailleCercleVoisin = 100;


/**
 *  \brief Algorithme de tri, recupere le tableau de piece de la classe ramapiece,
 *         tri des piece de la plus proche du bras a la plus eloigne
 *         tableau utile si on part du principe que le bras reviens a sa position apres chaque piece
 *  \return modifie le tableau directement via les pointeurs
 */

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

/**
 *  \brief Algorithme de tri, recupere la piece la plus proche du bras,
 *          puis tri des pieces par rapport a la distance entre chacunes
 * \param tableau de piece (exemple p.getPieces())
 * \return modifie le tableau directement via les pointeurs
 */
void triDistancePiecePiece(Ramapiece &p){

        vector<Piece> *tabPiece = p.getPieces();

        Piece tmpPiece;
        int j = 0, i = 0, indicePetit = 0;
        double valPetit = 0.0;

        for(i = 0; i<tabPiece->size(); i++){
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
            valPetit =  getDistance((*tabPiece)[0].pos, (*tabPiece)[i].pos);
            indicePetit = i;

            for(j = i; j<tabPiece->size(); j++){
                if(getDistance((*tabPiece)[i].pos, (*tabPiece)[j].pos) < valPetit){
                    indicePetit = j;
                    valPetit = getDistance((*tabPiece)[i].pos, (*tabPiece)[j].pos);
                }
            }
            /*on echange*/
            tmpPiece = (*tabPiece)[i];
            (*tabPiece)[i] = valPetit;
            (*tabPiece)[indicePetit] = tmpPiece;
        }
}

/**
 *  \brief Algorithme de tri, retourne un vector de piece ordonnée par leur valeur croissante,
 *          peut servir à une recherche dichotomique
 * \param tableau de piece (exemple p.getPieces())
 * \return modifie le tableau directement via les pointeurs
 */
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

/**
 *  \brief Tri dichotomique pour retrouver une piece d'une certaine valeur,
 * \param tableau de piece (exemple p.getPieces(), ou p est de type Ramapiece)
 * \param valeur de la piece recherche
 * \return int -> indice ou trouver la piece, si non trouve retourne -999
 */
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

/**
 *  \brief Parcours basique en partant du principe que le bras ramasse une piece
 *          et reviens en position start à chaque fois
 */
void parcoursSimple(Ramapiece &p){
        triDistancePieceBras(p);
        vector<Piece> *tabPiece = p.getPieces();

        while (tabPiece->size() > 0) {
            p.pickUpPiece(tabPiece->front());
            p.dropPieces();
        }
}

/**
 *  \brief On parcours de telle manière a se que le bras,
 *          aille toujours a la piece la plus proche de sa position actuelle, il fini en revenant a sa position
 */
void parcoursDesVoisins(Ramapiece &p){

        triDistancePiecePiece(p);
        vector<Piece> *tabPiece = p.getPieces();

        while (tabPiece->size() > 0) {
            p.pickUpPiece(tabPiece->front()); // vector->front() == (*vector)[0]
        }
        p.dropPieces();
}

/**
 *  \brief Délimite une grande zone à partir de 4 pieces puis divise cette grande zone en 4
 *          Parcours par la suite chaque petite zone
 */
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

    if(tabPiece->size() >= 4){
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
}

/**
 *  \brief Semblable au parcous des voisins mais une fois arriver sur une piece,
 *          regarde autour de lui dans une zone definie si il n'y a pas d'autres pieces.
 */
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
            for(int i =0; i<tabPiece->size(); i++){
                p.pickUpPiece(tabPiece->front());
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
