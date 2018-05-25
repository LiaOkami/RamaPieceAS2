#include "algorithm.hh"
#include "generateRamapiece.hh"

void    algorithmWrapper(Ramapiece &ramapiece, const t_algorithm &algorithm)
{
    std::cout << "### " << algorithm.first << std::endl;
    algorithm.second(ramapiece);
    std::cout << "### " << algorithm.first
              << "\tDistance : " << ramapiece.getTraveledDistance()
              << "\tArgent : " << ramapiece.getMoney() << std::endl;
}

int algorithmWrapper(Ramapiece &ramapiece, const t_algorithm_money &algorithm)
{
    int dist;
    int money;
    int availableMoney;

    for (const auto & piece:*(ramapiece.getPieces()))
        availableMoney += piece.value;
    std::cout << "Combien d'argent desirez-vous ? (Monnaie disponible : "
              << availableMoney << ")" << std::endl;
    std::cin >> money;
    std::cout << "### " << algorithm.first << std::endl;
    algorithm.second(ramapiece, money);
    dist = ramapiece.getTraveledDistance();
    std::cout << "### " << algorithm.first
              << "\tDistance : " << dist << std::endl;
    return dist;
}


void    manualTest()
{
    int value = -1;
    int i;
    int j;
    Ramapiece   *ramapiece;

    while (value != 0)
    {
        ramapiece = generateRamapiece(50);
        ramapiece->verbose();
        std::cout << "Veuillez choisir votre algorithme en rentrant le nombre correspondant :" << std::endl;
        i = 0;
        while (Algorithm::algos[i].first != "") {
            std::cout << i + 1 << ") " << Algorithm::algos[i].first << std::endl;
            i += 1;
        }
        j = 0;
        while (Algorithm::algosMoney[j].first != "") {
            std::cout << j + i + 1 << ") " << Algorithm::algosMoney[j].first << std::endl;
            j += 1;
        }

        std::cout << "0) Quitter" << std::endl;
        std::cin >> value;
        if (value > 0 && value <= i) {
            algorithmWrapper(*ramapiece, Algorithm::algos[value - 1]);
        }
        else if (value > i && value <= i + j) {
            algorithmWrapper(*ramapiece, Algorithm::algosMoney[value - 1 - i]);
        }
        delete ramapiece;
        std::cout << std::endl;
    }
}
