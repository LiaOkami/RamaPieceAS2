#include <string>
#include <iostream>
#include "compte.h"
#include "Ramapiece.hh"

using namespace std;

// la fonction renvoie que les plus grosses pieces à ramasser
// Ramassage le plus efficace car prend le moins de piece possible

void RamasCoinMax(int som, Ramapiece p)
{
    vector<Piece> *pieces = p.getPieces();
    int piecemax = (*pieces)[0].value;
    //Prend la piece la plus grosse du tapis pour savoir dans quel cas on est
    for(int i = 0;i <= pieces->size(); i++){
        if((*pieces)[i].value > piecemax){
            piecemax = (*pieces)[i].value;
        }
    }
    int S1 = 0, S2 = 0, S5 = 0, S10 = 0, S20 = 0, S50 = 0, S100 = 0, S200 = 0;
    switch(piecemax){

case 1 :

    while(som >= 1){
        S1 += 1;
        som -= 1;
    }

    break;

case 2 :



    while(som >= 2){
        S2 += 1;
        som -= 2;
    }
    while(som >= 1){
        S1 += 1;
        som -= 1;
    }
    break;

case 5 :



    while(som >= 5){
        S5 += 1;
        som -= 5;
    }
    while(som >= 2){
        S2 += 1;
        som -= 2;
    }
    while(som >= 1){
        S1 += 1;
        som -= 1;
    }

    break;

case 10 :



    while(som >= 10){
        S10 += 1;
        som -= 10;
    }
    while(som >= 5){
        S5 += 1;
        som -= 5;
    }
    while(som >= 2){
        S2 += 1;
        som -= 2;
    }
    while(som >= 1){
        S1 += 1;
        som -= 1;
    }

    break;

case 20:


    while(som >= 20){
        S20 += 1;
        som -= 20;
    }
    while(som >= 10){
        S10 += 1;
        som -= 10;
    }
    while(som >= 5){
        S5 += 1;
        som -= 5;
    }
    while(som >= 2){
        S2 += 1;
        som -= 2;
    }
    while(som >= 1){
        S1 += 1;
        som -= 1;
    }

    break;

case 50 :



    while(som >= 50){
        S50 += 1;
        som -= 50;
    }
    while(som >= 20){
        S20 += 1;
        som -= 20;
    }
    while(som >= 10){
        S10 += 1;
        som -= 10;
    }
    while(som >= 5){
        S5 += 1;
        som -= 5;
    }
    while(som >= 2){
        S2 += 1;
        som -= 2;
    }
    while(som >= 1){
        S1 += 1;
        som -= 1;
    }

    break;

case 100 :


    while(som >= 100){
        S100 += 1;
        som -= 100;
    }
    while(som >= 50){
        S50 += 1;
        som -= 50;
    }
    while(som >= 20){
        S20 += 1;
        som -= 20;
    }
    while(som >= 10){
        S10 += 1;
        som -= 10;
    }
    while(som >= 5){
        S5 += 1;
        som -= 5;
    }
    while(som >= 2){
        S2 += 1;
        som -= 2;
    }
    while(som >= 1){
        S1 += 1;
        som -= 1;
    }

    break;

case 200 :



    while(som >= 200){
        S200 += 1;
        som -= 200;
    }
    while(som >= 100){
        S100 += 1;
        som -= 100;
    }
    while(som >= 50){
        S50 += 1;
        som -= 50;
    }
    while(som >= 20){
        S20 += 1;
        som -= 20;
    }
    while(som >= 10){
        S10 += 1;
        som -= 10;
    }
    while(som >= 5){
        S5 += 1;
        som -= 5;
    }
    while(som >= 2){
        S2 += 1;
        som -= 2;
    }
    while(som >= 1){
        S1 += 1;
        som -= 1;
    }

    break;

    }


    cout<<"On va devoir ramasser un nombres suivant de pieces : "<<endl;
    cout<<endl;
    cout<<"S200 || "<<S200<<endl;
    cout<<"S100 || "<<S100<<endl;
    cout<<"S50  || "<<S50<<endl;
    cout<<"S20  || "<<S20<<endl;
    cout<<"S10  || "<<S10<<endl;
    cout<<"S5   || "<<S5<<endl;
    cout<<"S2   || "<<S2<<endl;
    cout<<"S1   || "<<S1<<endl;

}
/*
void RamasAlternative(int som){
    RamasCoinMax(som);
    cout<<"Sinon on peut faire ca : "<<endl<<endl;
    if(S200>0){

    }

    }
    */

