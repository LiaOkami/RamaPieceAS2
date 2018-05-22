#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "detection/detection.h"
#include "Piece.hh"

#include <cstdlib>
#include <ctime>

#include <vector>
#include <iostream>

using namespace std;
using namespace cv;

/*void detectionPieces()
{


}















    //transforme en tableau de points blancs (N)

    // boucle pour detecter tous les cercles, pour plus tard
        //on trace un cercle avec trois points tirés aléatoirement (E)
        //nombres aléatoires

        //Piece pieceCourante = traceCercle();

        //On compare le centre du cercle avec chaque point du tableau > on enregistre le nombre de point blanc qu'il comporte (E)
        //Boucle pour chaque point blanc

        //On  Prend le cercle avec le plus de points comme le "vrai" cercle
        //BOucle pour avec une donnée "max"
        //listePieceActuel.push_back(pieceCourante);
}
*/

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
    this->ouvertureFichier("2euros.jpg");

    //cv::cvtColor( imageTapis, gray_image, CV_RGB2GRAY );

  //  cv::Canny(imageTapis,contours,100,300);
     //------------------------------------------------
    //transforme en tableau de points blancs (Nicolas)
    //------------------------------------------------
    vector<vector<Point> > tableaucontours=this->tabContours();

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
           // int nbPoints appartenance;
            //On compare le centre du cercle avec chaque point du tableau > on enregistre le nombre de point blanc qu'il comporte (E)
            //Boucle pour chaque point blanc
            //compare sa distance du centre du cercle

           // for(int c = 0; c < tabsize; c++){ //tableau des points blancs

          }
       // }
        //On Cherche le cercle avec le plus de points comme le "vrai" cercle
        //BOucle pour avec une donnée "max"
    /*    int max = 0;
        for(int c = 0; c < tabsize; c++){

        }*/
    /* --- Fin boucle ---- */
    this->afficherPieces();
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






vector<vector<Point>> Detection::tabContours(){

cv::Mat imageTapisNB;
cv::Mat contours;
cvtColor( imageTapis, imageTapisNB, CV_RGB2GRAY );
cv::Canny(imageTapis,contours,100,1001);



vector<vector<Point>> tableaucontours;
vector<Vec4i> hierarchy;

findContours( contours, tableaucontours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

    return tableaucontours;
}

 void Detection::afficherPieces()
{

/*
    RNG rng(12345);

      Mat drawing = Mat::zeros( contours.size(), CV_8UC3 );
      for( int i = 0; i< tableaucontours.size(); i++ )
     {
       Scalar color = Scalar( rng.uniform(0, 255), rng.uniform(0,255), rng.uniform(0,255) );
       drawContours( drawing, tableaucontours, i, color, 2, 8, hierarchy, 0, Point() );
     }

     */
     cv::Point point(10,10);

      /// Show in a window
      namedWindow( "Contours");
      cv::imshow( "Contours", imageTapis );

    cv::waitKey(0);


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

