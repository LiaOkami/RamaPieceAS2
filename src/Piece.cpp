#include "Piece.hh"

Piece::Piece(int val, const Position &po) :
    value(val), pos(po) {

}

Piece::Piece(int val, double x, double y, double rad) :
    value(val), pos(Position(x, y)), radius(rad) {

}

bool    Piece::operator==(const Piece &piece) {
    return (value == piece.value && pos == piece.pos);
}

bool    Piece::operator!=(const Piece &piece) {
    return (value != piece.value || pos != piece.pos);
}
