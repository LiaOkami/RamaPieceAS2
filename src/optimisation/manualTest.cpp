#include <functional>
#include "algorithm.hh"
#include "generateRamapiece.hh"

using namespace std::placeholders;

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

int algorithmWrapper(Ramapiece &ramapiece, const t_algorithm_param &algorithm)
{
    int dist;
    int money;

    std::cout << "Combien d'argent desirez-vous ? (Il y a environ 5000 sur le tapis)" << std::endl;
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
        std::cout << "Veuillez choisir votre algorithme en rentrant le nombre correspondant :" << std::endl;
        i = 0;
        while (funcs[i].first != "") {
            std::cout << i + 1 << ") " << funcs[i].first << std::endl;
            i += 1;
        }
        j = 0;
        while (funcs_param[j].first != "") {
            std::cout << j + i + 1 << ") " << funcs_param[j].first << std::endl;
            j += 1;
        }

        std::cout << "0) Quitter" << std::endl;
        std::cin >> value;
        if (value > 0 && value <= i) {
            algorithmWrapper(*ramapiece, funcs[value - 1]);
        }
        else if (value > i && value <= i + j) {
            algorithmWrapper(*ramapiece, funcs_param[value - 1 - i]);
        }
        delete ramapiece;
        std::cout << std::endl;
    }
}
