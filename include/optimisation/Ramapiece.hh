/** \file Ramapiece.hh
 *  \brief Classe Ramapiece
 */

#ifndef _RAMAPIECE_HH_INCLUDED_
# define _RAMAPIECE_HH_INCLUDED_

# include <vector>
# include "Piece.hh"
# include "imageParcours.hh"
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
    bool        _isVerbose;
    Image       *_image;
    int         _imageIndex;

    static const std::string    IMAGE_PATH;
    static const std::string    IMAGE_EXT;

    /** \brief Sauvegarde automatiquement l'image à chaque mouvement
     *  L'Image est sauvegardé en tant que IMAGE_PATH + _imageIndex + IMAGE_EXT
     *  _imageIndex est un compteur incrémentant à chaque nouvelle image sauvegardée
     */
    void    _saveImage();

  public:
    Ramapiece();
    Ramapiece(vectorPiece *pieces, const Robot& robot, bool isImage = false);
    Ramapiece(const Ramapiece &other);
    Ramapiece & operator=(const Ramapiece &ramapiece);
    ~Ramapiece();

    static const int            IMAGE_WIDTH = 1200;
    static const int            IMAGE_HEIGHT = 800;

    /** \brief Initialise l'Image qui décrira le parcours du Robot
     */
    void    initImage();

    vectorPiece *       getPieces();  /**< _pieces getter */

    const Position &    getRobotPosition(); /**< _robot.pos getter */

    const Position &    getRobotStart(); /**< _robot.start getter */

    double  getRobotSpeed(); /**< _robot.speed getter */

    /** \brief Ramasse une Piece
     *
     *  \param const Piece& piece
     *
     *  Déplace le Robot jusqu'à la Piece.
     *  La pièce est déposée dans le Robot, et est retirée du tapis.
     */
    void    pickUpPiece(const Piece &piece);

    /** \brief Dépose les Piece
     *
     *  Déplace le Robot jusqu'à son point d'origine, puis dépose les Piece.
     */
    void    dropPieces();

    /** \brief Récupère la distance totale parcourue par le Robot
     *  \return int Distance parcourue
     */
    int     getTraveledDistance();

    /** \brief Calcule l'argent disponible sur le tapis
     *  \return int Argent disponible
     */
    int     getAvailableMoney();

    /** \brief Récupère l'argent ramassé par le Robot
     *  \return int Argent ramassé
     */
    int     getMoney();

    /** \brief Active l'affichage détaille en Console
     *  Affiche tous les déplacements du Robot et les Piece ramassées.
     */
    void    verbose();

    /** \brief Affiche l'Image décrivant le parcours du Robot
     */
    void    displayImage();

    /** \brief Enregistre l'Image décrivant le parcours du Robot.
     *  \param const std::string& filename Nom du fichier à enregistrer
     */
    void    saveImage(const std::string &filename);
};

#endif // _RAMAPIECE_HH_INCLUDED_
