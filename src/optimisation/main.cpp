#include <iostream>
#include "compte.h"
#include "Ramapiece.hh"

using namespace std;

int main()
{
    int som;
    cout << "Quelle somme voulez vous en centimes ?" << endl;
    cin >> som;
    RamasCoinMax(som);
    cout << endl;

    return 0;
}
