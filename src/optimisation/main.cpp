/** \file main.cpp
 *  \brief Fichier principale de la solution Opti
 */
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "manualTest.hh"
#include "unitTest.hh"
#include "imageParcours.hh"
#include "Ramapiece.hh"
#include "generateRamapiece.hh"
#include <string>
#include "parcours.hh"

/** \brief Ouvre un menu terminal pour choisir son algorithme
 */
void    menu()
{
    int value;

    std::cout << "Bienvenue dans Ramapiece." << std::endl
              << "1) Tests manuels" << std::endl
              << "2) Tests unitaires" << std::endl
              << "0) Quitter" << std::endl;
    std::cin >> value;
    switch (value)
    {
    case 1:
        manualTest();
        break;
    case 2:
        unitTest();
        break;
    }
}

void    testRamaDoable()
{
    Ramapiece *p = generateRamapieceNormal(5);
    vector<int> pieces;

    RamaDoable(*p, p->getAvailableMoney() / 10 , pieces);
    for(int i=0;i<=8;i++){
        cout<<pieces[i]<<endl;
    }
}
int main()
{
    srand(time(NULL));
    menu();
    //testRamaDoable();
    std::cout << "Sortie du programme." << std::endl;


    //Test Image
/*
    Ramapiece *p = generateRamapiece(50);
    Image img(2000,1500);
    img.placePieceImage(p->getPieces());
    img.sauvegardeImage("");
    string cpt = "";
    int i = 0;

    triDistancePiecePiece(*p);
    vector<Piece> *tabPiece = p->getPieces();

    while (tabPiece->size() > 0) {
        cpt =  to_string(i);

        img.placePieceParcourus((tabPiece->front().pos.x),(tabPiece->front().pos.y));
        img.deplaceRobot(p->getRobotPosition(),tabPiece->front().pos, 0,255,0); //vert

        p->pickUpPiece(tabPiece->front()); // vector->front() == (*vector)[0]

        img.sauvegardeImage(cpt);

        i++;
    }
    p->dropPieces();

    img.afficherImage();
*/
    return (0);
}
