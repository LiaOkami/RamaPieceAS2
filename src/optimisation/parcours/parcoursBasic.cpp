#include "parcours.hh"

void    parcoursBasic(Ramapiece &ramapiece) {
    std::vector<Piece> *tabPieces = ramapiece.getPieces();

    while (tabPieces->size() > 0) {
        ramapiece.pickUpPiece(tabPieces->front());
    }
    ramapiece.dropPieces();
}
