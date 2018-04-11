#include "Ramapiece.hh"

Ramapiece::Ramapiece(vectorPiece *pieces, const Robot& robot) :
    _pieces(pieces), _robot(robot) {

}

vectorPiece *   Ramapiece::getPieces() {
    return _pieces;
}
const Position &    Ramapiece::getRobotPosition() {
    return _robot.pos;
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
        std::cout << _robot.pos << " to " << piece.pos << std::endl;
        std::cout << "Distance : " << dist << "\tValue picked: "
                  << piece.value << std::endl;
        _robot.pos = piece.pos;
        _pieces->erase(it);
    }
}

void    Ramapiece::dropPieces() {
    double  dist = getDistance(_robot.pos, _robot.start);

    std::cout << _robot.pos <<  " to " << _robot.start << std::endl;
    std::cout << "Distance : " << dist << "\tCoins dropped." << std::endl;
    _robot.pos = _robot.start;
    _pieces->clear();
}
