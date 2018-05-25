#include "Algorithm.hh"
#include "generateRamapiece.hh"
#include "unitTest.hh"

void    unitTest()
{
    std::vector<int>            averageDistance;
    std::vector<int>            averageValue;
    std::vector<Ramapiece *>    test;
    int i;
    int tries;

    i = 0;
    while (Algorithm::algos[i].first != "")
    {
        averageDistance.push_back(0);
        averageValue.push_back(0);
        i += 1;
    }
    for (tries = 0 ; tries < NB_TRIES ; tries++) {
        test.push_back(generateRamapiece(rand() % 100 + 1));
        for (i = 1 ; i < averageDistance.size() ; i++) {
            test.push_back(new Ramapiece(*(test.front())));
        }
        for (i = 0 ; i < averageDistance.size() ; i++) {
            Algorithm::algos[i].second(*test[i]);
            averageDistance[i] = (averageDistance[i] * tries + test[i]->getTraveledDistance()) / (tries + 1);
            averageValue[i] = (averageValue[i] * tries + test[i]->getMoney()) / (tries + 1);
        }
        test.clear();
    }
    std::cout << "Moyenne sur " << NB_TRIES << " essais" << std::endl;
    for (i = 0 ; i < averageDistance.size() ; i++)
        std::cout << "Distance : " << averageDistance[i] << " / Argent : " << averageValue[i]
                  << " (" << Algorithm::algos[i].first << ")" << std::endl;
}
