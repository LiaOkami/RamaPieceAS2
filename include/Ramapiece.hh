/** \file Ramapiece.hh
 *  \brief Classe Ramapiece
 */

#ifndef _RAMAPIECE_HH_INCLUDED_
# define _RAMAPIECE_HH_INCLUDED_

# include <vector>
# include "Robot.hh"

typedef std::vector<Piece>    vectorPiece;

/** \brief Classe représentant le robot ramassant les Piece
 *  \author Pierrick Garcia
 */
class   Ramapiece {
  private:
    vectorPiece *_pieces;
    Robot       _robot;
    int         _distance;
    int         _money;

  public:
    Ramapiece();
    Ramapiece(vectorPiece *pieces, const Robot& robot);
    Ramapiece & operator=(const Ramapiece &ramapiece);
    ~Ramapiece();

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
     *  Déplace le Robot jusqu'à la Piece.
     *  La pièce est déposée dans le Robot, et est retirée du tapis.
     */
    void                pickUpPiece(const Piece &piece);

    /** \brief Dépose les Piece
     *
     *  Déplace le Robot jusqu'à son point d'origine, puis dépose les Piece.
     */
    void                dropPieces();

    /** \brief Récupère la distance totale parcourue par le Robot
     *  \return int Distance parcourue
     */
    int                 getTraveledDistance();

    /** \brief Récupère l'argent ramassé par le Robot
     *  \return int Argent ramassé
     */
    int                 getMoney();

    /** \brief Copie Ramapièce avec un tableau de Piece unique
     *  \return Ramapiece& *this
     */
    Ramapiece &         copyRamapiece(const Ramapiece &other);
};

#endif // _RAMAPIECE_HH_INCLUDED_
