#include "Algorithm.hh"
#include "generateRamapiece.hh"
#include "unitTest.hh"

void    unitTest()
{
    std::vector<int>            average;
    std::vector<Ramapiece *>    test;
    int i;
    int tries;

    i = 0;
    while (Algorithm::algos[i].first != "")
    {
        average.push_back(0);
        i += 1;
    }
    for (tries = 0 ; tries < NB_TRIES ; tries++) {
        test.push_back(generateRamapiece(50));
        for (i = 1 ; i < average.size() ; i++) {
            test.push_back(new Ramapiece(*(test.front())));
        }
        for (i = 0 ; i < average.size() ; i++) {
            Algorithm::algos[i].second(*test[i]);
            average[i] = (average[i] * tries + test[i]->getTraveledDistance()) / (tries + 1);
        }
        test.clear();
    }
    std::cout << "Moyenne sur " << NB_TRIES << " essais" << std::endl;
    for (i = 0 ; i < average.size() ; i++)
        std::cout << Algorithm::algos[i].first << " : " << average[i] << std::endl;
}
