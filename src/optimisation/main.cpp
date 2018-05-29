/** \file main.cpp
 *  \brief Fichier principale de la solution Opti
 */
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "manualTest.hh"
#include "unitTest.hh"
#include "imageParcours.h"
#include "Ramapiece.hh"
#include "generateRamapiece.hh"

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


int main()
{
    srand(time(NULL));
    menu();
    std::cout << "Sortie du programme." << std::endl;


    //Test Image
    /*Ramapiece  * p = generateRamapiece(50);
    Image img(1500,800);
    img.placePieceImage(p->getPieces());
    img.afficherImage();*/

    return (0);
}
