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



Detection::Detection(){
    pieceCourante = Piece();
    tapisVide = true;
}

void Detection::detectionPieces()
{
    //------------------------------------------------
    //Charge l'image (avec Cany edge detector) dans l'attribut imageTapis (Nicolas)
    //------------------------------------------------
    this->ouvertureFichier("2euros.jpg");

    //------------------------------------------------
    //transforme en tableau de points blancs
    //------------------------------------------------
    vector<vector<Point> > tabContours = this->tabContours();

    //------------------------------------------------
    // On cherche les pièce du tapis (E)
    //------------------------------------------------
    srand(time(NULL)); // initialise les nombres aléatoires
    vector< std::pair<Piece, int> > tabPiecesDetectees; // enregistre la pièce et le nb de pts qu'il y a dessus (accès : .first, .second)

    for(int i = 0; i < 100; i++){
        //on trace un cercle avec trois points tirés aléatoirement du tableau de contours
        int MIN = 0, MAX = tabContours.size();
        cv::Point pointsTires[3];

        for(int cpt = 0; cpt < 3; cpt ++){
            int Ialea = rand()%(MAX-MIN) + MIN;
            int Jalea = rand()%(tabContours[Ialea].size()-MIN) + MIN;
            pointsTires[cpt] = tabContours[Ialea][Jalea];
            //AFFICHAGE TEST
            cout << "Point aleatoire " << Ialea << ", " << Jalea << " trouve : " << tabContours[Ialea][Jalea].x << "x | " << tabContours[Ialea][Jalea].y <<"y" << endl;
        }
        Position pos1(pointsTires[0].x, pointsTires[0].y), pos2(pointsTires[1].x, pointsTires[1].y), pos3(pointsTires[2].x, pointsTires[2].y);
        Piece pieceTracee = tracerPiece3points(pos1, pos2, pos3);
        //AFFICHAGE TEST
        cout << "Piece tracee : " << pieceTracee.pos.x << "x | " << pieceTracee.pos.y << "y rayon : " << pieceTracee.radius;

        //On compare le centre du cercle avec chaque point du tableau > on enregistre le nombre de point blanc qu'il comporte sur son contour
        //On compare la distance de chaque point blanc du centre du cercle
        int nbPointsAppartenance = 0;
        if(pieceTracee.value != -1){
            //si pas d'erreur, on fait le traitement et enregistre
            for(int i = 0; i < tabContours.size(); i++){
                for(int j = 0; j < tabContours[i].size(); j++){
                    Position pointVerifie(tabContours[i][j].x, tabContours[i][j].y);
                    double distance = getDistance(pieceTracee.pos, pointVerifie);
                    if(pieceTracee.radius -1.0 < distance && distance < pieceTracee.radius +1.0){ //si appartient, on le compte
                        nbPointsAppartenance++;
                    }
                }
            }
            tabPiecesDetectees.push_back(make_pair(pieceTracee, nbPointsAppartenance));
        }
        //AFFICHAGE TEST
        cout << ", apparait " << nbPointsAppartenance << " fois" << endl << "---------------------" << endl;
    }
    //On Cherche le cercle avec le plus de points, qu'on enregistre comme le "vrai" cercle
    /* A CHANGER pour detecter plusieurs pieces, et pour éliminer les doublons */
    int maxPoints = 0, indexMax = 0;
    for(int c = 0; c < tabPiecesDetectees.size(); c++){
        if(tabPiecesDetectees[c].second > maxPoints){
            maxPoints = tabPiecesDetectees[c].second;
            indexMax = c;
        }
    }
    pieceCourante = tabPiecesDetectees[indexMax].first; //temporaire
    listePieceCourante.push_back(tabPiecesDetectees[indexMax].first); //définitif
    //AFFICHAGE TEST
    //cout << "Piece selectionee : " << tabPiecesDetectees[indexMax].first.pos.x << "x | " << tabPiecesDetectees[indexMax].first.pos.y << "y rayon : " << tabPiecesDetectees[indexMax].first.radius << ", apparait " << maxPoints << " fois" << endl << "---------------------" << endl;

    this->afficherPieces();
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

vector< vector<Point> > Detection::tabContours(){

cv::Mat imageTapisNB;
cv::Mat contours;
cvtColor( imageTapis, imageTapisNB, CV_RGB2GRAY );
cv::Canny(imageTapis,contours,100,1001);

//cv::namedWindow("Gray");
//cv::imshow("Gray",imageTapisNB);
cv::namedWindow("Contours");
cv::imshow("Contours", contours);

vector< vector<Point> > tableaucontours;
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
    cv::Point centre(pieceCourante.pos.x,pieceCourante.pos.y);

    cv::circle(imageTapis, centre, pieceCourante.radius, Scalar( 0, 255, 0 ), 5);

    /// Show in a window
    namedWindow( "NB");
    cv::imshow( "NB", imageTapis );

    // Affichage dans la console de toutes les pièces sur le tapis
    for(int i = 0; i < listePieceCourante.size(); i++){
        cout << " --- Piece courante" << i+1 << " ---" << endl;
        cout << "centre : " << listePieceCourante[i].pos.x << ", " << listePieceCourante[i].pos.y << " rayon : " << listePieceCourante[i].radius << endl;
    }
    cv::waitKey(0);
}

Piece tracerPiece3points(Position A, Position B, Position C)
{
    double yDelta_a = B.y - A.y;
    double xDelta_a = B.x - A.x;
    double yDelta_b = C.y - B.y;
    double xDelta_b = C.x - B.x;
    //si un des delta x = 0, on quitte
    if( xDelta_a == 0 || xDelta_b == 0){
        return Piece(-1, 0.0, 0.0);
    }

    double aSlope = yDelta_a/xDelta_a;
    double bSlope = yDelta_b/xDelta_b;
    //Coordonées du centre
    double centreX = (aSlope*bSlope*(A.y - C.y) + bSlope*(A.x + B.x) - aSlope*(B.x+C.x) )/(2* (bSlope-aSlope) );
    double centreY = -1*(centreX - (A.x+B.x)/2)/aSlope +  (A.y+B.y)/2;
    Position posCentre(centreX, centreY);
    //Rayon
    double rayon = getDistance(A, posCentre);

    return Piece(0, centreX, centreY, rayon);
}

