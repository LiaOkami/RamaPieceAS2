#include "algorithm.hh"
#include "parcours.h"
#include "generateRamapiece.hh"
#include "Ramapiece.hh"

const t_algorithm test[] = {
   {"Parcours Simple", &parcoursSimple},
   {"Parcours des Voisins", &parcoursDesVoisins},
   {"Parcours des Voisins avec zone", &parcoursDesVoisinsZone},
   {"Parcours par zones", &parcoursZone}
};

int algorithmWrapper(Ramapiece &ramapiece, const t_algorithm &algorithm)
{
    int dist;

    std::cout << "### " << algorithm.first << std::endl;
    algorithm.second(ramapiece);
    dist = ramapiece.getTraveledDistance();
    std::cout << "### " << algorithm.first
              << "\tDistance : " << dist << std::endl;
    return dist;
}

void    manualTest()
{
    int value = -1;
    int i;
    Ramapiece   *ramapiece;

    while (value != 0)
    {
        ramapiece = generateRamapiece(50);
        std::cout << "Veuillez choisir votre algorithme en rentrant le nombre correspondant." << std::endl;
        i = 0;
        while (test[i].first != "") {
            std::cout << i + 1 << ") " << test[i].first << std::endl;
            i += 1;
        }
        std::cout << "0) Quitter" << std::endl;
        std::cin >> value;
        if (value > 0 && value <= i) {
            algorithmWrapper(*ramapiece, test[value - 1]);
        }
        delete ramapiece;
        std::cout << std::endl;
    }
}

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
