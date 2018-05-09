#include <iostream>
#include "compte.h"
#include "algorithm.hh"
#include "generateRamapiece.hh"
#include "Ramapiece.hh"

using namespace std;

int main()
{
    Ramapiece ramapiece = generateRamapiece(50);
    menu(ramapiece);

/*    int som;
    cout << "Quelle somme voulez vous en centimes ?" << endl;
    cin >> som;
    RamasCoinMax(som);
    cout << endl;*/

    return (0);
}
