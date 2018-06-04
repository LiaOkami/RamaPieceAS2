#include <vector>
#include "algorithm.hh"
#include "Ramapiece.hh"

//// TMP
std::vector<Piece>  *partie1(const std::string &filename) {
    std::vector<Piece>  *pieces = new std::vector<Piece>;
    for(int i = 0 ; i < 50 ; i++)
        pieces->push_back(Piece(rand() % 200 + 1, rand() % 900 + 100, rand() % 900 + 100));
    return (pieces);
}

static inline int   testAlgorithm(const Ramapiece &sample, int i) {
    int ret;

    Ramapiece   *ramapiece = new Ramapiece(sample);
    RamapieceAlgorithm::algos[i].second(*ramapiece);
    ret = ramapiece->getTraveledDistance();
    delete ramapiece;
    return ret;
}

void    pickUpPieces(Ramapiece &sample, const std::string &filename)
{
    int i;
    int minValue;
    int value;
    int idxMin = 0;

    minValue = testAlgorithm(sample, 0);
    i = 1;
    while (RamapieceAlgorithm::algos[i].first != "") {
        value = testAlgorithm(sample, i);
        if (value < minValue) {
            minValue = value;
            idxMin = i;
        }
        i += 1;
    }
    sample.initImage();
    RamapieceAlgorithm::algos[idxMin].second(sample);
    sample.saveImage(filename);
}

int main(int ac, char **av)
{
    if (ac == 3 || ac == 4) {
        std::vector<Piece>  *pieces = partie1(av[1]);
        Ramapiece ramapiece(pieces, Robot(Position(0, 0)));
        if (ac == 3)
            pickUpPieces(ramapiece, av[2]);
        else if (ac == 4)
            ;//pickUpValue(ramapiece, av[2], std::stoi(av[3]));
    }
    else {
        std::cerr << "Nombre d'arguments incorrects" << std::endl;
        return (-1);
    }
    return (0);
}
