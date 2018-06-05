#include "Algorithm.hh"
#include "generateRamapiece.hh"
#include "unitTest.hh"

static inline void  fillTestRamapiece(std::vector<Ramapiece *> & test, int size)
{
    for (int i = 1 ; i < size ; i++) {
        test.push_back(new Ramapiece(*(test.front())));
    }
}
static inline void  unitTestAlgorithm()
{
    std::vector<int>            averageDistance;
    std::vector<int>            averageValue;
    std::vector<Ramapiece *>    test;
    int i;
    int tries;

    i = 0;
    while (RamapieceAlgorithm::algos[i].first != "")
    {
        averageDistance.push_back(0);
        averageValue.push_back(0);
        i += 1;
    }
    for (tries = 0 ; tries < NB_TRIES ; tries++) {
        test.push_back(generateRamapiece(rand() % 100 + 1));
        fillTestRamapiece(test, averageDistance.size());
        for (i = 0 ; i < averageDistance.size() ; i++) {
            RamapieceAlgorithm::algos[i].second(*test[i]);
            averageDistance[i] = (averageDistance[i] * tries + test[i]->getTraveledDistance()) / (tries + 1);
            averageValue[i] = (averageValue[i] * tries + test[i]->getMoney()) / (tries + 1);
        }
        test.clear();
    }
    std::cout << "Moyenne sur " << NB_TRIES << " essais" << std::endl;
    for (i = 0 ; i < averageDistance.size() ; i++)
        std::cout << "Distance : " << averageDistance[i] << " / Argent : " << averageValue[i]
                  << " (" << RamapieceAlgorithm::algos[i].first << ")" << std::endl;

}

static inline void  testHandler(std::vector<int> &avgDistance, std::vector<int> &avgValue,
                                std::vector<int> &avgError, int tries)
{
    std::vector<Ramapiece *>    test;
    int i;
    int value;
    int availableMoney;

    test.push_back(generateRamapiece(rand() % 100 + 1));
    fillTestRamapiece(test, avgDistance.size());
    availableMoney = test[0]->getAvailableMoney();
    value = rand() % availableMoney;
    for (i = 0 ; i < avgDistance.size() ; i++) {
        RamapieceAlgorithm::algosMoney[i].second(*test[i], value);
        avgDistance[i] = (avgDistance[i] * tries + test[i]->getTraveledDistance()) / (tries + 1);
        avgValue[i] = (avgValue[i] * tries + test[i]->getMoney()) / (tries + 1);
        avgError[i] = avgError[i] * tries + abs(test[i]->getMoney() - test[i]->getAvailableMoney()) / (tries + 1);
    }
    test.clear();
}

static inline void  unitTestAlgorithmMoney()
{
    std::vector<int>            averageDistance;
    std::vector<int>            averageValue;
    std::vector<int>            averageError;
    int i;

    i = 0;
    while (RamapieceAlgorithm::algosMoney[i].first != "")
    {
        averageDistance.push_back(0);
        averageValue.push_back(0);
        averageError.push_back(0);
        i += 1;
    }
    for (int tries = 0 ; tries < NB_TRIES ; tries++) {
        testHandler(averageDistance, averageValue, averageError, tries);
    }
    std::cout << "Moyenne sur " << NB_TRIES << " essais" << std::endl;
    for (i = 0 ; i < averageDistance.size() ; i++)
        std::cout << "Distance : " << averageDistance[i] << " / Argent : " << averageValue[i]
                  << "Erreur : " << averageError[i]
                  << " (" << RamapieceAlgorithm::algos[i].first << ")" << std::endl;

}

void    unitTest()
{
    unitTestAlgorithm();
    //
    unitTestAlgorithmMoney();
}
