#include <array>
#include "generateRamapiece.hh"

std::array<int, 8>  values = {1, 2, 5, 10, 20, 50, 100, 200};

Ramapiece * generateRamapiece(int size) {
    std::vector<Piece>  *pieces = new std::vector<Piece>;
    for(int i = 0 ; i < size ; i++)
        pieces->push_back(Piece(rand() % 200 + 1, rand() % 900 + 100, rand() % 900 + 100));
    return (new Ramapiece(pieces, Robot(Position(rand() % 900 + 100, rand() % 900 + 100))));
}

Ramapiece * generateRamapieceNormal(int size) {
    std::vector<Piece>  *pieces = new std::vector<Piece>;
    for(int i = 0 ; i < size ; i++)
        pieces->push_back(Piece(values[rand() % 8], rand() % 900 + 100, rand() % 900 + 100));
    return (new Ramapiece(pieces, Robot(Position(rand() % 900 + 100, rand() % 900 + 100))));
}
