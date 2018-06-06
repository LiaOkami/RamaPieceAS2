#include <string>
#include <iostream>
#include "compte.h"
#include "Ramapiece.hh"
#include "parcours.h"

using namespace std;

//Renvoie vrai si le tableau est toujours remplit, faux si totalement vide
 bool isEmpty(vector<int> kindPieces){
    bool Vide = true;

for(int k=0;k<=8;k++){

    if(kindPieces[k]>0){

         Vide = false;
}
}
return Vide;
}

// C'est mal indenté tu vas te faire manger si tu corriges pas ça avant vendredi
void RamaDoable(Ramapiece &p, int som, vector<int> &kindPiecesOriginal) {
    vector<Piece> *pieces = p.getPieces();
    vector<int>   kindPieces(8);
    int sumTabPieces = 0;

    //initialisation des atbleaux à 0

    for(int i =0;i<8;i++){
        kindPieces[i]=0;
        kindPiecesOriginal.push_back(0);
    }

    //On remplit les tableaux selon les valeurs des pieces sur le tapis
    for(int i = 0;i <= pieces->size(); i++){


            switch((*pieces)[i].value){
    case 1 :
            kindPieces[0]+=1;
            kindPiecesOriginal[0]+=1;
            break;
    case 2 :
            kindPieces[1]+=1;
            kindPiecesOriginal[1]+=1;
            break;
    case 5 :
            kindPieces[2]+=1;
            kindPiecesOriginal[2]+=1;
            break;
    case 10 :
            kindPieces[3]+=1;
            kindPiecesOriginal[3]+=1;
            break;
    case 20 :
            kindPieces[4]+=1;
            kindPiecesOriginal[4]+=1;
            break;
    case 50 :
            kindPieces[5]+=1;
            kindPiecesOriginal[5]+=1;
            break;
    case 100 :
            kindPieces[6]+=1;
            kindPiecesOriginal[6]+=1;
            break;
    case 200 :
            kindPieces[7]+=1;
            kindPiecesOriginal[7]+=1;
            break;
            }

}

    // on recherche les pieces a ramasser
    do{
        if(som >= 200 && kindPieces[7] > 0){
            som = som - 200;
            kindPieces[7] -= 1;

        }
        else if(som >= 100 && kindPieces[6] > 0){
            som = som - 100;
            kindPieces[6] -= 1;
        }
        else if(som >= 50 && kindPieces[5] > 0){
            som = som - 50;
            kindPieces[5] -= 1;
        }
        else if(som >= 20 && kindPieces[4] > 0){
            som = som - 20;
            kindPieces[4] -= 1;
        }
        else if(som >= 10 && kindPieces[3] > 0){
            som = som - 10;
            kindPieces[3] -= 1;
        }
        else if(som >= 5 && kindPieces[2] > 0){
            som = som - 5;
            kindPieces[2] -= 1;
        }
        else if(som >= 2 && kindPieces[1] > 0){
            som = som - 2;
            kindPieces[1] -= 1;
        }
        else if(som >= 1 && kindPieces[0] > 0){
            som = som - 1;
            kindPieces[0] -= 1;
        }
        else
            break;
    }while(som>0 && !isEmpty(kindPieces));


    // calcul de la différence entre les deux tableaux
    for(int i = 0;i < 8; i++){
        kindPiecesOriginal[i]-=kindPieces[i];
    }
}
