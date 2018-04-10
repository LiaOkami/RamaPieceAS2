#include "Position.hh"

Position(double xx = 0, double yy = 0) :
    x(xx), y(yy) {
}

double  getDistance(const Position & pos1, const Position & pos2) {
    return (sqrt(pow(pos1.x - pos2.x, 2) + pow(pos1.y - pos2.y, 2)));
}
