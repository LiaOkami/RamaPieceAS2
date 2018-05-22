#include "Ramapiece.hh"

Ramapiece::Ramapiece() {
}

Ramapiece::Ramapiece(vectorPiece *pieces, const Robot& robot) :
    _pieces(pieces), _robot(robot), _distance(0) {
}

Ramapiece & Ramapiece::operator=(const Ramapiece &other) {
    _pieces = other._pieces;
    _robot = other._robot;
    _distance = other._distance;
}


Ramapiece::~Ramapiece() {
    if (_pieces != nullptr)
        delete _pieces;
}

vectorPiece *   Ramapiece::getPieces() {
    return _pieces;
}
const Position &    Ramapiece::getRobotPosition() {
    return _robot.pos;
}

const Position &    Ramapiece::getRobotStart() {
    return _robot.start;
}

double  Ramapiece::getRobotSpeed() {
    return _robot.speed;
}

void    Ramapiece::pickUpPiece(const Piece &piece) {
    double  dist = getDistance(_robot.pos, piece.pos);

    // Cherche la piece dans le vecteur de pièces de Ramapiece
    std::vector<Piece>::iterator it = _pieces->begin();
    while (*it != piece && it != _pieces->end())
        it++;
    // Si la pièce est trouvée
    if (it != _pieces->end()) {
        std::cout << _robot.pos << " to " << piece.pos << '\t'
                  << "Distance : " << dist << "\tValue picked: "
                  << piece.value << std::endl;
        _robot.pos = piece.pos;
        _robot.pieces.push_back(piece);
        _pieces->erase(it);
        _distance += dist;
    }
}

void    Ramapiece::dropPieces() {
    double  dist = getDistance(_robot.pos, _robot.start);
    int     value = 0;

    for (const Piece &piece:_robot.pieces)
        value += piece.value;
    std::cout << _robot.pos <<  " to " << _robot.start << std::endl
              << "Distance : " << dist << "\tCoins dropped, value: "
              << value << "." << std::endl;
    _robot.pos = _robot.start;
    _distance += dist;
}

int Ramapiece::getTraveledDistance() {
    return _distance;
}
