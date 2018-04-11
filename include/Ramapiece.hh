#ifndef _RAMAPIECE_HH_INCLUDED_
# define _RAMAPIECE_HH_INCLUDED_

# include <vector>
# include "Robot.hh"

typedef std::vector<Piece>    vectorPiece;

class   Ramapiece {
  private:
    vectorPiece *_pieces;
    Robot       _robot;

  public:
    Ramapiece(vectorPiece *pieces, const Robot& robot);

    vectorPiece *       getPieces();
    const Position &    getRobotPosition();
    double              getRobotSpeed();
    void                pickUpPiece(const Piece &piece);
    void                dropPieces();

};

#endif // _RAMAPIECE_HH_INCLUDED_
