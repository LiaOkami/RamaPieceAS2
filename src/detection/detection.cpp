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
    tapisVide = true;
}

void Detection::detectionPieces()
{
    //------------------------------------------------
    //Charge l'image dans l'attribut imageTapis
    //------------------------------------------------
    this->ouvertureFichier("images/01.jpg");

    //------------------------------------------------
    //transforme en tableau de points blancs
    //------------------------------------------------
    vector<vector<Point> > tabContours = this->tabContours();

    //------------------------------------------------
    // On cherche les pièce du tapis
    //------------------------------------------------
    srand(time(NULL)); // initialise les nombres aléatoires
    vector< std::pair<Piece, int> > tabPiecesDetectees; // pièce, nb de pts qui appartiennet à son contour (accès std::pair : .first, .second)

    for(int i = 0; i < 1000; i++){
        //on trace un cercle avec trois points tirés aléatoirement du tableau de contours
        int MIN = 0, MAX = tabContours.size();
        cv::Point pointsTires[3];

        for(int cpt = 0; cpt < 3; cpt ++){
            int Ialea = rand()%(MAX-MIN) + MIN;
            int Jalea = rand()%(tabContours[Ialea].size()-MIN) + MIN;
            pointsTires[cpt] = tabContours[Ialea][Jalea];
            //AFFICHAGE TEST
            //cout << "Point aleatoire " << Ialea << ", " << Jalea << " trouve : " << tabContours[Ialea][Jalea].x << "x | " << tabContours[Ialea][Jalea].y <<"y" << endl;
        }
        Position pos1(pointsTires[0].x, pointsTires[0].y), pos2(pointsTires[1].x, pointsTires[1].y), pos3(pointsTires[2].x, pointsTires[2].y);
        Piece pieceTracee = tracerPiece3points(pos1, pos2, pos3);
        //AFFICHAGE TEST
        //cout << "Piece tracee : " << pieceTracee.pos.x << "x | " << pieceTracee.pos.y << "y rayon : " << pieceTracee.radius;

        //On compare la distance de chaque point blanc du centre du cercle > on enregistre le nombre de points que la pièce comporte sur son contour
        int nbPointsAppartenance = 0;
        if(pieceTracee.value > -1){
            for(int i = 0; i < tabContours.size(); i++){
                for(int j = 0; j < tabContours[i].size(); j++){
                    Position pointVerifie(tabContours[i][j].x, tabContours[i][j].y);
                    double distance = getDistance(pieceTracee.pos, pointVerifie);
                    if(pieceTracee.radius -5.0 < distance && distance < pieceTracee.radius +5.0){ //si appartient, on le compte
                        nbPointsAppartenance++;
                    }
                }
            }
            tabPiecesDetectees.push_back(make_pair(pieceTracee, nbPointsAppartenance));
        }
    }

    //On Cherche le cercle avec le plus de points, qu'on enregistre comme le "vrai" cercle
    int maxPoints = 0, indexMax = 0;
    for(int c = 0; c < tabPiecesDetectees.size(); c++){
        if(tabPiecesDetectees[c].second > maxPoints){
            maxPoints = tabPiecesDetectees[c].second;
            indexMax = c;
        }
    }
    pieceCourante = tabPiecesDetectees[indexMax].first; //temporaire
    listePieceCourante.push_back(tabPiecesDetectees[indexMax].first); //définitif
    tapisVide = false;
    //AFFICHAGE TEST
    cout << "Piece selectionee MAX : " << tabPiecesDetectees[indexMax].first.pos.x << "x | " << tabPiecesDetectees[indexMax].first.pos.y << "y rayon : " << tabPiecesDetectees[indexMax].first.radius << ", apparait " << maxPoints << " fois" << endl << "---------------------" << endl;

    // On prend toute les autres ieces qui ont un nb de points proche de la plus grande des pièces
    int seuil = maxPoints * 80 /100;
    // cout << "maxPoints : " << maxPoints << endl << "seuil : " << seuil << endl;
    for(int c = 0; c < tabPiecesDetectees.size(); c++){
        if(tabPiecesDetectees[c].second > seuil ){
            listePieceCourante.push_back(tabPiecesDetectees[c].first);
            //AFFICHAGE TEST
            cout << "Piece selectionee : " << tabPiecesDetectees[c].first.pos.x << "x | " << tabPiecesDetectees[c].first.pos.y << "y rayon : " << tabPiecesDetectees[c].first.radius << ", apparait " << tabPiecesDetectees[c].second << " fois" << endl << "---------------------" << endl;
        }
    }
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
        cout << "Ne peut pas ouvrir " << chemin << std::endl;
        return false;
    }
    else
    {
        cout << "fichier ouvert : " << chemin << std::endl;
        return true;
    }
}

vector< vector<Point> > Detection::tabContours()
{
    cv::Mat imageTapisNB;
    cv::Mat contours;
    cvtColor( imageTapis, imageTapisNB, CV_RGB2GRAY );
    cv::Canny(imageTapis,contours,100,500);

    //Affichage
    cv::namedWindow("Contours");
    cv::imshow("Contours", contours);

    vector< vector<Point> > tableaucontours;
    vector<Vec4i> hierarchy;

    findContours(contours, tableaucontours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );

    return tableaucontours;
}

 void Detection::afficherPieces()
{
    for(int i = 0; i < listePieceCourante.size(); i++){
        // AFFICHAGE graphique
        cv::Point centre(listePieceCourante[i].pos.x,listePieceCourante[i].pos.y);
        cv::circle(imageTapis, centre, listePieceCourante[i].radius, Scalar( 0, 255, 0 ), 5);
        // AFFICHAGE Console
        cout << " --- Piece courante" << i+1 << " ---" << endl;
        cout << "centre : " << listePieceCourante[i].pos.x << ", " << listePieceCourante[i].pos.y << " rayon : " << listePieceCourante[i].radius << endl;
    }

    namedWindow("Affichage");
    cv::imshow("Affichage", imageTapis );
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

 bool comparaison2Pieces(Piece piece1, Piece piece2){

 if ((piece1.pos.x<=piece2.pos.x +5 || piece1.pos.x>=piece2.pos.x-5) && (piece1.pos.y<=piece2.pos.y +5 || piece1.pos.y>=piece2.pos.y-5)) {

    if (piece1.radius<=piece2.radius +5 && piece1.radius>=piece2.radius-5)
        {
           return true;
        }
    }
    else return false;

}

Piece fusion2Pieces(Piece piece1, Piece piece2){

    Piece pieceFusionne;
    pieceFusionne.pos.x=(piece1.pos.x+piece2.pos.x)/2;
    pieceFusionne.pos.y=(piece1.pos.y+piece2.pos.y)/2;
    pieceFusionne.radius=(piece1.radius+piece2.radius)/2;

    return pieceFusionne;

}

