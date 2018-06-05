#include "algorithm.hh"
#include "generateRamapiece.hh"

static inline void  algorithmWrapper(Ramapiece &ramapiece, const t_algorithm &algorithm)
{
    std::cout << "### " << algorithm.first << std::endl;
    algorithm.second(ramapiece);
    ramapiece.displayImage();
    std::cout << "### " << algorithm.first
              << "\tDistance : " << ramapiece.getTraveledDistance()
              << "\tArgent : " << ramapiece.getMoney() << std::endl;
}

static int  algorithmWrapper(Ramapiece &ramapiece, const t_algorithm_money &algorithm)
{
    int dist;
    int money;

    std::cout << "Combien d'argent desirez-vous ? (Monnaie disponible : "
              << ramapiece.getAvailableMoney() << ")" << std::endl;
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
        std::cout << "Veuillez choisir votre algorithme en rentrant le nombre correspondant :" << std::endl;
        i = 0;
        while (RamapieceAlgorithm::algos[i].first != "") {
            std::cout << i + 1 << ") " << RamapieceAlgorithm::algos[i].first << std::endl;
            i += 1;
        }
        j = 0;
        while (RamapieceAlgorithm::algosMoney[j].first != "") {
            std::cout << j + i + 1 << ") " << RamapieceAlgorithm::algosMoney[j].first << std::endl;
            j += 1;
        }

        std::cout << "0) Quitter" << std::endl;
        std::cin >> value;
        if (value > 0 && value <= i) {
            ramapiece = generateRamapiece(50);
            ramapiece->verbose();
            ramapiece->initImage();
            algorithmWrapper(*ramapiece, RamapieceAlgorithm::algos[value - 1]);
            delete ramapiece;
        }
        else if (value > i && value <= i + j) {
            ramapiece = generateRamapieceNormal(50);
            ramapiece->verbose();
            ramapiece->initImage();
            algorithmWrapper(*ramapiece, RamapieceAlgorithm::algosMoney[value - 1 - i]);
            delete ramapiece;
        }
        std::cout << std::endl;
    }
}
