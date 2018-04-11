#include <cmath>
#include "Position.hh"

Position::Position(double xx, double yy) :
    x(xx), y(yy) {
}

bool    Position::operator==(const Position &pos) {
    return (x == pos.x && y == pos.y);
}

bool    Position::operator!=(const Position &pos) {
    return (x != pos.x || y != pos.y);
}

double  getDistance(const Position & pos1, const Position & pos2) {
    return (sqrt(pow(pos1.x - pos2.x, 2) + pow(pos1.y - pos2.y, 2)));
}

std::ostream &   operator<<(std::ostream &os, const Position &pos) {
    os << '(' << pos.x << ", " << pos.y << ")";
    return os;
}
