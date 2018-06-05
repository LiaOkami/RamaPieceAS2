#include <string>
#include <iostream>
#include "compte.h"
#include "Ramapiece.hh"
#include "parcours.h"

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
void RamasAlternative1(int som){
    vector<int> exept;
    cout<<"Quelle piece n'est pas presente sur le tapis ? entrer valeur de piece existante"<<endl;

    }
*/

/*
void RamasAlternative2(int som, Ramapiece p){

    vector<Piece> *pieces = p.getPieces();
    int sumpieces, parcoursTab = pieces->size();
    for(int i = 0;i <= pieces->size(); i++){
            sumpieces += (*pieces)[i].value;

}
    if(som>sumpieces){
        cout<<"valeur demandee trop grande par rapport aux pieces sur le tapis"<<endl;
    }
    triValeur(pieces);
    while(som>0){
        som -= (*pieces)[parcoursTab].value;
        cout<<"On retire la piece"<<(*pieces)[parcoursTab].value<<endl;
        parcoursTab-=1;
    }
}
*/

static bool isEmpty(vector<int> kindPieces){
    bool Vide =false;
for(int k=0;k<=8;k++){
    if(kindPieces[k]>0){
        bool Vide = true;
}
}
return Vide;
}


void RamaDoable(Ramapiece &p, int som){//, vector<int>& kindPiecesRemplit){
    vector<Piece> *pieces = p.getPieces();
    vector<int>   kindPieces(8),kindPiecesOriginal(8);
    int sumTabPieces = 0, sumObtenable, parcoursTab = pieces->size();
    for(int i =0;i<=8;i++){
        kindPieces[i]=0;
        kindPiecesOriginal[i]=0;
    }
    for(int i = 0;i <= parcoursTab; i++){
            sumTabPieces += (*pieces)[i].value;
            //On remplit un tableau avec
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

    cout<<"On a ce tableau de pieces"<<endl;
        for(int i = 0;i < 8; i++){
                cout<<kindPieces[i]<<endl;

        }


    if(som > sumTabPieces){
        cout << "valeur demandee trop grande par rapport aux pieces sur le tapis" << endl;

    }

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
    }while(som>0&& isEmpty(kindPieces));
    for(int i = 0;i < 8; i++){
    kindPiecesOriginal[i]-=kindPieces[i];
   // if(kindPiecesOriginal[i]>0){

        switch(i){
case 0:
    cout<<"Il faut ramasser "<< kindPiecesOriginal[i] << " pieces de 1 centime"<<endl;
    break;
case 1:
    cout<<"Il faut ramasser "<< kindPiecesOriginal[i] << " pieces de 2 centimes"<<endl;
    break;
case 2:
    cout<<"Il faut ramasser "<< kindPiecesOriginal[i] << " pieces de 5 centimes"<<endl;
    break;
case 3:
    cout<<"Il faut ramasser "<< kindPiecesOriginal[i] << " pieces de 10 centimes"<<endl;
    break;
case 4:
    cout<<"Il faut ramasser "<< kindPiecesOriginal[i] << " pieces de 20 centimes"<<endl;
    break;
case 5:
    cout<<"Il faut ramasser "<< kindPiecesOriginal[i] << " pieces de 50 centimes"<<endl;
    break;
case 6:
    cout<<"Il faut ramasser "<< kindPiecesOriginal[i] << " pieces de 1 euro"<<endl;
    break;
case 7:
    cout<<"Il faut ramasser "<< kindPiecesOriginal[i] << " pieces de 2 euros"<<endl;
    break;

}
}
}//utiliser pickUpPiece(const Piece &piece); et
/*
    for(int j = 0; j <= 8; j++){
        kindPiecesRemplit.push_back(kindPiecesOriginal[j]);
    }
}
*/

