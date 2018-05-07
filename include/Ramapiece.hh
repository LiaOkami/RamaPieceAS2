/** \file Ramapiece.hh
 *  \brief Classe Ramapiece
 */

#ifndef _RAMAPIECE_HH_INCLUDED_
# define _RAMAPIECE_HH_INCLUDED_

# include <vector>
# include "Robot.hh"

typedef std::vector<Piece>    vectorPiece;

/** \brief Classe repr�sentant le robot ramassant les Piece
 *  \author Pierrick Garcia
 */
class   Ramapiece {
  private:
    vectorPiece *_pieces;
    Robot       _robot;

  public:
    Ramapiece(vectorPiece *pieces, const Robot& robot);

    /** \brief Retourne le vecteur contenant les Piece sur le tapis roulant
     *  \return vectorPiece*
     */
    vectorPiece *       getPieces();

    /** \brief Retourne la position actuelle du Robot
     *  \return const Position&
     */
    const Position &    getRobotPosition();

    /** \brief Retourne la position initiale du Robot
     *  \return const Position&
     */
    const Position &    getRobotStart();

    /** \brief Retourne la vitesse du Robot
     *  \return double
     */
    double              getRobotSpeed();

    /** \brief Ramasse une Piece
     *
     *  \param const Piece& piece
     *
     *  D�place le Robot jusqu'� la Piece.
     *  La pi�ce est d�pos�e dans le Robot, et est retir�e du tapis.
     */
    void                pickUpPiece(const Piece &piece);

    /** \brief D�pose les Piece
     *
     *  D�place le Robot jusqu'� son point d'origine, puis d�pose les Piece.
     */
    void                dropPieces();

};

#endif // _RAMAPIECE_HH_INCLUDED_
