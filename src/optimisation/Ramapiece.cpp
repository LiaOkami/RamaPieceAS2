#include "Ramapiece.hh"

const std::string   Ramapiece::IMAGE_PATH = "./images/parcours/";
const std::string   Ramapiece::IMAGE_EXT = ".jpg";

Ramapiece::Ramapiece()
{
}

Ramapiece::Ramapiece(vectorPiece *pieces, const Robot& robot, bool isImage) :
    _pieces(pieces), _robot(robot), _distance(0), _money(0), _isVerbose(false), _image(nullptr)
{
    if (isImage)
        this->initImage();
}

Ramapiece::Ramapiece(const Ramapiece &other) :
    _pieces(new vectorPiece(*(other._pieces))), _robot(other._robot),
    _distance(0), _money(0), _isVerbose(false), _image(nullptr)
{
    if (_image)
        this->initImage();
}

Ramapiece & Ramapiece::operator=(const Ramapiece &other) {
    _pieces = other._pieces;
    _robot = other._robot;
    _distance = other._distance;
    _money = other._money;
    _isVerbose = other._isVerbose;
    _image = other._image;
    return *this;
}


Ramapiece::~Ramapiece() {
    if (_pieces != nullptr)
        delete _pieces;
    if (_image != nullptr)
        delete _image;
}

void    Ramapiece::initImage() {
    _image = new Image(IMAGE_WIDTH, IMAGE_HEIGHT);
    _image->placePieceImage(_pieces);
    _imageIndex = 0;
}

void    Ramapiece::_saveImage() {
    _image->sauvegardeImage(IMAGE_PATH + std::to_string(_imageIndex) + IMAGE_EXT);
    _imageIndex += 1;
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
        if (_isVerbose) {
            std::cout << _robot.pos << " to " << piece.pos << '\t'
                      << "Distance : " << dist << "\tValue picked: "
                      << piece.value << std::endl;
        }
        if (_image) {
            _image->placePieceParcourus(piece.pos.x, piece.pos.y);
            _image->deplaceRobot(_robot.pos, piece.pos);
            this->_saveImage();
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
    if (_image) {
        _image->deplaceRobot(_robot.pos, _robot.start);
        this->_saveImage();
    }
    _money += value;
    _robot.pos = _robot.start;
    _robot.pieces.clear();
    _distance += dist;
}

int Ramapiece::getTraveledDistance() {
    return _distance;
}

int Ramapiece::getAvailableMoney() {
    int ret = 0;

    for (const Piece & piece:*(_pieces))
        ret += piece.value;
    return ret;
}

int Ramapiece::getMoney(){
    return _money;
}

void    Ramapiece::verbose() {
    _isVerbose = true;
}

void    Ramapiece::displayImage() {
    _image->afficherImage();
}

void    Ramapiece::saveImage(const std::string &filename) {
    _image->sauvegardeImage(filename);
}
