#include "algorithm.hh"
#include "parcours.h"
#include "Ramapiece.hh"
#include "manualTest.hh"

const t_algorithm funcs[] = {
   {"Parcours Simple", &parcoursSimple},
   {"Parcours des Voisins", &parcoursDesVoisins},
   {"Parcours des Voisins avec zone", &parcoursDesVoisinsZone},
   {"Parcours par zones", &parcoursZone},
   {"", nullptr}
};

const t_algorithm_param funcs_param[] = {
   {"", nullptr}
};

void    unitTest()
{

}

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
    std::cout << "Sortie du programme." << std::endl;
}
