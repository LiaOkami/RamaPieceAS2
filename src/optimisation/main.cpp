#include <iostream>
#include "compte.h"
#include "Ramapiece.hh"

using namespace std;

void    testRamapiece() {
    std::vector<Piece>  *pieces = new std::vector<Piece>;
    pieces->push_back(Piece(100, 5, 7));
    pieces->push_back(Piece(20, 54, 74));
    pieces->push_back(Piece(200, 543, 373));
    pieces->push_back(Piece(50, 5, 700));
    pieces->push_back(Piece(1, 12, 50));

    Ramapiece   ramapiece(pieces, Robot(Position(53, 4)));
    pieces = ramapiece.getPieces();
    std::cout << "Position de depart: " << ramapiece.getRobotPosition() << std::endl;
    ramapiece.pickUpPiece((*pieces)[2]);
    ramapiece.dropPieces();
}

int main()
{
    testRamapiece();

/*    int som;
    cout << "Quelle somme voulez vous en centimes ?" << endl;
    cin >> som;
    RamasCoinMax(som);
    cout << endl;*/

    return (0);
}
