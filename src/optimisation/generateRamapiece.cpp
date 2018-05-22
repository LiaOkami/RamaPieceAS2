#include <cstdlib>
#include <ctime>
#include "Ramapiece.hh"

Ramapiece   generateRamapiece(int size) {
    srand(time(NULL));
    std::vector<Piece>  *pieces = new std::vector<Piece>;
    for(int i = 0 ; i < size ; i++)
        pieces->push_back(Piece(rand() % 200, rand() % 900 + 100, rand() % 900 + 100));
    return (Ramapiece(pieces, Robot(Position(rand() % 900 + 100, rand() % 900 + 100))));
}
