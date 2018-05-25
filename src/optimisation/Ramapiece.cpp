#include "Ramapiece.hh"

Ramapiece::Ramapiece()
{
}

Ramapiece::Ramapiece(vectorPiece *pieces, const Robot& robot) :
    _pieces(pieces), _robot(robot), _distance(0), _money(0), _isVerbose(false)
{
}

Ramapiece::Ramapiece(const Ramapiece &other) :
    _pieces(new vectorPiece(*(other._pieces))), _robot(other._robot),
    _distance(0), _money(0), _isVerbose(false)
{
}

Ramapiece & Ramapiece::operator=(const Ramapiece &other) {
    _pieces = other._pieces;
    _robot = other._robot;
    _distance = other._distance;
    _money = other._money;
    _isVerbose = other._isVerbose;
    return *this;
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

    // Cherche la piece dans le vecteur de pi�ces de Ramapiece
    std::vector<Piece>::iterator it = _pieces->begin();
    while (*it != piece && it != _pieces->end())
        it++;
    // Si la pi�ce est trouv�e
    if (it != _pieces->end()) {
        if (_isVerbose) {
            std::cout << _robot.pos << " to " << piece.pos << '\t'
                      << "Distance : " << dist << "\tValue picked: "
                      << piece.value << std::endl;
        }
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
    if (_isVerbose) {
        std::cout << _robot.pos <<  " to " << _robot.start << std::endl
                  << "Distance : " << dist << "\tCoins dropped, value: "
                  << value << "." << std::endl;
    }
    _money += value;
    _robot.pos = _robot.start;
    _robot.pieces.clear();
    _distance += dist;
}

int Ramapiece::getTraveledDistance() {
    return _distance;
}


int Ramapiece::getMoney(){
    return _money;
}

void    Ramapiece::verbose() {
    _isVerbose = true;
}
