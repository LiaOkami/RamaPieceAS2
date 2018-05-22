#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

#include "detection/detection.h"
#include "Piece.hh"
//nombres aléatoires
#include <cstdlib>
#include <ctime>

#include <vector>
#include <iostream>
using namespace std;
using namespace cv;


Detection::Detection(){
    pieceCourante = Piece();
    tapisVide = true;
}

Piece Detection::getPieceCourante()
{
    return pieceCourante;
}

vector<Piece> Detection::getListePieceCourante()
{
    if(tapisVide){
        vector<Piece> vecteurVide;
        return vecteurVide;
    } else {
        return listePieceCourante;
    }
}

void Detection::detectionPieces()
{
    //------------------------------------------------
    //Prend l'image (avec Cany edge detector (Nicolas)
    //------------------------------------------------
    Detection d;
    d.ouvertureFichier("2euros.jpg");

/*    cv::Mat contours;
    cv::Mat gray_image;

    cvtColor( image, gray_image, CV_RGB2GRAY );

    cv::Canny(image,contours,100,1001);
    //cout << contours << endl;
    //10,350

    vector<vector<Point> > tableaucontours;
    vector<Vec4i> hierarchy;

    //affichage dans la console des coordonnées de contour

    findContours( contours, tableaucontours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

    for(int i= 0; i < tableaucontours.size(); i++)
{
    for(int j= 0; j < tableaucontours[i].size();j++) // run until j < contours[i].size();
    {
        cout << tableaucontours[i][j] << endl; //do whatever
    }
}

    //on dessine l'image en fonction de données sorties de la fonction canny
    RNG rng(12345);

      Mat drawing = Mat::zeros( contours.size(), CV_8UC3 );
      for( int i = 0; i< tableaucontours.size(); i++ )
     {
       Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
       drawContours( drawing, tableaucontours, i, color, 2, 8, hierarchy, 0, Point() );
     }

      /// Show in a window
      namedWindow( "Contours");
      imshow( "Contours", drawing );

    cv::namedWindow("Image");
    cv::imshow("Image",image);

    cv::namedWindow("Gray");
    cv::imshow("Gray",gray_image);

    cv::namedWindow("Canny");
    cv::imshow("Canny",contours);
    cv::waitKey(0);*/

    //------------------------------------------------
    //transforme en tableau de points blancs (Nicolas)
    //------------------------------------------------



    //------------------------------------------------
    // On cherche les pièce du tapis (Etienne)

    /* --- boucle pour detecter toutes les pièces du tapis, pour plus tard ---*/
        vector<std::pair<Piece, int>> tabPiecesDetectees; // enregistre la pièce et le nb de pts qu'il y a dessus (accès : .first, .second)
        for(int i = 0; i < 3; i++){
            //on trace un cercle avec trois points tirés aléatoirement (E)
            //nombres aléatoires
            int MIN = 0, MAX = 10; //MAX = tableau.lenght()
            srand(time(NULL));
            int alea1 = rand()%(MAX-MIN) + MIN,
                alea2 = rand()%(MAX-MIN) + MIN,
                alea3 = rand()%(MAX-MIN) + MIN;
            cout << "Nombres aléatoires : " << alea1 << ", " << alea2 << ", " << alea3 << endl; //test
           // Piece piecetracée = tracerPiece3points(pos1,pos2,pos3); //prendre les positions à partir du tableau de points

            //On compare le centre du cercle avec chaque point du tableau > on enregistre le nombre de point blanc qu'il comporte (E)
            //Boucle pour chaque point blanc
            //compare sa distance du centre du cercle
            int nbPointsAppartenance;
            for(int c = 0; c < tabsize; c++){ //tableau des points blancs //R
                int distance = getDistance(pieceTracee.pos, tab[c]); //R
                if(pieceTracee.rayon-2 < distance && distance < pieceTracee.rayon+2){ //si appartient, on le compte //R
                    nbPointsAppartenance++;
                }
            }
            tabPiecesDetectees.push_back(make_pair(pieceTracee,nbPointsAppartenance));
        }
        //On Cherche le cercle avec le plus de points comme le "vrai" cercle
        int maxPoints = 0, imax = 0;
        for(int j = 0; j < tabPiecesDetectees.size(); j++){
            if(tabPiecesDetectees[j].second > maxPoints){
                maxPoints = tabPiecesDetectees[j].second;
                imax = j;
            }
        }
        pieceCourante = tabPiecesDetectees[imax].first;
    /* --- Fin boucle ---- */
}

bool Detection::ouvertureFichier(const string chemin){
    // Check if we can open the file
    imageTapis = imread(chemin, 1);
    if(!imageTapis.data) {
        cout << "Can't open file " << chemin << std::endl;
        return false;
    }
    else {
        return true;
    }
}


void Detection::afficherPieces()
{
    //TODO
}

Piece tracerPiece3points(Position A, Position B, Position C)
{
    double yDelta_a = B.y - A.y;
    double xDelta_a = B.x - A.x;
    double yDelta_b = C.y - B.y;
    double xDelta_b = C.x - B.x;

    double aSlope = yDelta_a/xDelta_a;
    double bSlope = yDelta_b/xDelta_b;
    //Coordonées du centre
    double centreX = (aSlope*bSlope*(A.y - C.y) + bSlope*(A.x + B.x) - aSlope*(B.x+C.x) )/(2* (bSlope-aSlope) );
    double centreY = -1*(centreX - (A.x+B.x)/2)/aSlope +  (A.y+B.y)/2;
    Position posCentre(centreX, centreY);
    //Rayon
    double rayon = getDistance(A, posCentre);

    return Piece(0, centreX, centreY); //àMODIFIER : doit aussi retourner le rayon de la pièce
}

