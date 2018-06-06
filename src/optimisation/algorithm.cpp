#include "algorithm.hh"

const t_algorithm   RamapieceAlgorithm::algos[] = {
        {"Parcours Simple", &parcoursSimple},
        {"Parcours Basique", &parcoursBasic},
        {"Parcours des Voisins", &parcoursDesVoisins},
        {"Parcours des Voisins avec zone", &parcoursDesVoisinsZone},
        {"Parcours par zones", &parcoursZone},
        {"", nullptr}
};

const t_algorithm_money RamapieceAlgorithm::algosMoney[] = {
        {"Parcours par valeur", &parcoursZoneSomme},
        {"", nullptr}
};
