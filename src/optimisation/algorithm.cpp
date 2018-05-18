#include "algorithm.hh"
#include "parcours.h"

//void parcoursZone(Ramapiece &p);

const t_algorithm test[] = {
   {"Parcours Simple", &parcoursSimple},
   {"Parcours des Voisins", &parcoursDesVoisins},
   {"", nullptr}
};

int algorithmWrapper(Ramapiece &ramapiece, const t_algorithm &algorithm) {
    int dist;

    std::cout << "### " << algorithm.first << std::endl;
    algorithm.second(ramapiece);
    dist = ramapiece.getTraveledDistance();
    std::cout << "### " << algorithm.first
              << "\tDistance : " << dist << std::endl;
    return dist;
}

void    menu(Ramapiece &ramapiece) {
    int value;
    int i = 0;

    std::cout << "Bienvenue dans Ramapiece." << std::endl
              << "Veuillez choisir votre algorithme en rentrant le nombre correspondant." << std::endl;
    while (test[i].first != "") {
        std::cout << i + 1 << ") " << test[i].first << std::endl;
        i += 1;
    }
    std::cin >> value;
    if (value > 0 && value <= i) {
        algorithmWrapper(ramapiece, test[value - 1]);
    }
    else
        std::cerr << "Mauvaise valeur rentrée, sortie du programme." << std::endl;
}
