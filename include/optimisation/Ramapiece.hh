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

/** \brief Classe repr�sentant le robot ramassant les Piece
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

    /** \brief Sauvegarde automatiquement l'image � chaque mouvement
     *  L'Image est sauvegard� en tant que IMAGE_PATH + _imageIndex + IMAGE_EXT
     *  _imageIndex est un compteur incr�mentant � chaque nouvelle image sauvegard�e
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

    /** \brief Initialise l'Image qui d�crira le parcours du Robot
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
     *  D�place le Robot jusqu'� la Piece.
     *  La pi�ce est d�pos�e dans le Robot, et est retir�e du tapis.
     */
    void    pickUpPiece(const Piece &piece);

    /** \brief D�pose les Piece
     *
     *  D�place le Robot jusqu'� son point d'origine, puis d�pose les Piece.
     */
    void    dropPieces();

    /** \brief R�cup�re la distance totale parcourue par le Robot
     *  \return int Distance parcourue
     */
    int     getTraveledDistance();

    /** \brief Calcule l'argent disponible sur le tapis
     *  \return int Argent disponible
     */
    int     getAvailableMoney();

    /** \brief R�cup�re l'argent ramass� par le Robot
     *  \return int Argent ramass�
     */
    int     getMoney();

    /** \brief Active l'affichage d�taille en Console
     *  Affiche tous les d�placements du Robot et les Piece ramass�es.
     */
    void    verbose();

    /** \brief Affiche l'Image d�crivant le parcours du Robot
     */
    void    displayImage();

    /** \brief Enregistre l'Image d�crivant le parcours du Robot.
     *  \param const std::string& filename Nom du fichier � enregistrer
     */
    void    saveImage(const std::string &filename);
};

#endif // _RAMAPIECE_HH_INCLUDED_
