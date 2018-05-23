#include "algorithm.hh"

const t_algorithm   Algorithm::algos[] = {
        {"Parcours Simple", &parcoursSimple},
        {"Parcours des Voisins", &parcoursDesVoisins},
        {"Parcours des Voisins avec zone", &parcoursDesVoisinsZone},
        {"Parcours par zones", &parcoursZone},
        {"Parcours par zones", &parcoursZone},
        {"", nullptr}
    };

const t_algorithm_money Algorithm::algosMoney[] = {
        {"", nullptr}
    };

