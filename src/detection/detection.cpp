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

void Detection::detectionPieces(const string chemin, const int nbPieces)
{
    //------------------------------------------------
    // Charge l'image dans l'attribut imageTapis
    //------------------------------------------------
    this->ouvertureFichier(chemin);

    //------------------------------------------------
    // Transforme en tableau de points blancs
    //------------------------------------------------
    vector<Point> tabPointsContours = this->tabContours();

    //------------------------------------------------
    // TRACÉ ALÉATOIRE, On cherche les pièce du tapis
    //------------------------------------------------
    srand(time(NULL));
    vector< std::pair<Piece, int> > tabPiecesDetectees; // pièce, nb de pts qui appartiennet à son contour (accès std::pair : .first, .second)

    for(int i = 0; i < 1000; i++){
        // On trace un cercle avec trois points tirés aléatoirement du tableau de contours
        //--------------------------------------------
        int MIN = 0, MAX = tabPointsContours.size();
        cv::Point pointsTires[3];

        for(int cpt = 0; cpt < 3; cpt ++){
            int indexAlea = rand()%(MAX-MIN) + MIN;
            pointsTires[cpt] = tabPointsContours[indexAlea];
        }
        Position pos1(pointsTires[0].x, pointsTires[0].y), pos2(pointsTires[1].x, pointsTires[1].y), pos3(pointsTires[2].x, pointsTires[2].y);
        Piece pieceTracee = tracerPiece3points(pos1, pos2, pos3);

        // Comptage des points du Cercle
        //--------------------------------------------
        int nbPointsAppartenance = 0;
        if(pieceTracee.value > -1){// && pieceTracee.radius < imageTapis.size().width/4 && pieceTracee.radius < imageTapis.size().height/4 ){  //si la pièce retournée n'as pas d'erreur
            for(int i = 0; i < (int) tabPointsContours.size(); i++){
                Position pointVerifie(tabPointsContours[i].x, tabPointsContours[i].y);
                double distance = getDistance(pieceTracee.pos, pointVerifie);
                if(pieceTracee.radius - 5.0 < distance && distance < pieceTracee.radius + 5.0){
                    nbPointsAppartenance++;
                }
            }
            tabPiecesDetectees.push_back(make_pair(pieceTracee, nbPointsAppartenance));
            //AFFICHAGE TEST
            //cout << "PIECE TRACEE : " << pieceTracee.pos.x << "x | " << pieceTracee.pos.y << "y | RAYON " << pieceTracee.radius << " | " << nbPointsAppartenance << " PTS" << endl << "--------------" << endl;
        }
    }

    //------------------------------------------------
    // ÉLIMINE LES DOUBLONS
    //------------------------------------------------
    for(int i=0; i<(int)tabPiecesDetectees.size(); i++){
        bool correspondance = false;
        int j= i+1;
        while(j<(int)tabPiecesDetectees.size() && !correspondance){
            if(comparaison2Pieces(tabPiecesDetectees[i].first, tabPiecesDetectees[j].first)){
                correspondance = true;
                tabPiecesDetectees.push_back(make_pair(fusion2Pieces(tabPiecesDetectees[i].first, tabPiecesDetectees[j].first), tabPiecesDetectees[i].second + tabPiecesDetectees[j].second/2));
                tabPiecesDetectees.erase(tabPiecesDetectees.begin() + i);
                tabPiecesDetectees.erase(tabPiecesDetectees.begin() + j-1);
                i--;
            }
            j++;
        }
    }

    //------------------------------------------------
    // ---     SÉLECTION DES PIÈCES COURANTES     ---
    // Si on connait le nb de pièces, on fait des tours de boucle
    // Sinon on fait avec un seuil p/r au max
    //------------------------------------------------
    if(nbPieces > 0){
        for(int c=0; c<nbPieces; c++){
            int maxPoints = 0, indexMax = 0;
            for(int i=0; i<(int)tabPiecesDetectees.size(); i++){
                if(tabPiecesDetectees[i].second > maxPoints){
                    maxPoints = tabPiecesDetectees[i].second;
                    indexMax = i;
                }
            }
            listePieceCourante.push_back(tabPiecesDetectees[indexMax].first);
            //AFFICHAGE TEST
            cout << "SELEC | " << tabPiecesDetectees[indexMax].first.pos.x << "x | " << tabPiecesDetectees[indexMax].first.pos.y << "y | RAYON " << tabPiecesDetectees[indexMax].first.radius << ", a " << maxPoints << " points" << endl << "----------" << endl;
            tabPiecesDetectees.erase(tabPiecesDetectees.begin() + indexMax);
        }
    } else {
        //On Cherche le cercle avec le plus de points
        int maxPoints = 0, indexMax = 0;
        for(int i = 0; i <(int)tabPiecesDetectees.size(); i++){
            if(tabPiecesDetectees[i].second > maxPoints){
                maxPoints = tabPiecesDetectees[i].second;
                indexMax = i;
            }
        }
        listePieceCourante.push_back(tabPiecesDetectees[indexMax].first);
        //AFFICHAGE TEST
        cout << "SELEC MAX | " << tabPiecesDetectees[indexMax].first.pos.x << "x | " << tabPiecesDetectees[indexMax].first.pos.y << "y | RAYON " << tabPiecesDetectees[indexMax].first.radius << ", a " << maxPoints << " points" << endl << "---------------------" << endl;

        // On prend toute les autres pieces qui ont un nb de points proche de la plus grande des pièces
        int seuil = maxPoints * 50 /100;
        int rayonMoyen = listePieceCourante[0].radius;
        for(int c = 0; c < (int)tabPiecesDetectees.size(); c++){
            if(tabPiecesDetectees[c].second > seuil){
                if (rayonMoyen/2 < tabPiecesDetectees[c].first.radius && tabPiecesDetectees[c].first.radius < rayonMoyen*2){
                    listePieceCourante.push_back(tabPiecesDetectees[c].first);
                    //AFFICHAGE TEST
                    cout << "SELEC SEUIL | " << tabPiecesDetectees[c].first.pos.x << "x | " << tabPiecesDetectees[c].first.pos.y << "y | RAYON " << tabPiecesDetectees[c].first.radius << ", a " << tabPiecesDetectees[c].second << " points" << endl << "---------------------" << endl;
                }else{
                    tabPiecesDetectees.erase(tabPiecesDetectees.begin() + c);
                }
            }
        }
    }

    tapisVide = false;
    this->afficherPieces();
}

vector<Piece> Detection::getListePieceCourante(){
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

vector<Point> Detection::tabContours(){
    cv::Mat imageTapisNB;
    cv::Mat contours;
    cvtColor( imageTapis, imageTapisNB, CV_RGB2GRAY );
<<<<<<< HEAD
    Mat gaus;
    GaussianBlur( imageTapisNB, gaus, Size( 5, 5 ), 0, 0 );
    cv::Canny(gaus,contours,100,500);
=======
    cv::Canny(imageTapis,contours,50,150);
>>>>>>> 77bdfb71765b302aa975dafbc24c262a8180b6f8

    //Affichage
    cv::namedWindow("Contours");
    cv::imshow("Contours", contours);

    vector< vector<Point> > tableaucontours;
    vector<Vec4i> hierarchy;
    findContours(contours, tableaucontours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, Point(0, 0) );
    vector<Point> tableauretour;

    for(int i= 0; i < tableaucontours.size(); i++){
        for(int j= 0; j < tableaucontours[i].size();j++){
            tableauretour.push_back(tableaucontours[i][j]);
        }
    }
    return tableauretour;
}

 void Detection::afficherPieces(){
    srand(time(NULL));
    for(int i = 0; i < (int)listePieceCourante.size(); i++){
        int MIN=0, MAX=255, tabCouleur[3];
        for(int cpt=1; cpt<3; cpt++){
            tabCouleur[cpt-1] = rand()%(MAX-MIN) + MIN;
        }
        // AFFICHAGE graphique
        cv::Point centre(listePieceCourante[i].pos.x,listePieceCourante[i].pos.y);
        cv::circle(imageTapis, centre, listePieceCourante[i].radius, Scalar( tabCouleur[0], tabCouleur[1], tabCouleur[2]), 5);
        // AFFICHAGE Console
        //cout << " --- Piece Courante " << i+1 << " ---" << endl << "centre : " << listePieceCourante[i].pos.x << ", " << listePieceCourante[i].pos.y << " rayon : " << listePieceCourante[i].radius << endl;
    }

    namedWindow("Affichage");
    cv::imshow("Affichage", imageTapis );
    cv::waitKey();
}

Piece tracerPiece3points(Position A, Position B, Position C){
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
    double ECART = 5;
    double ECARTRAYON = 40;
    //cout << "ECART : p1(" << piece1.radius << ") + p2(" << piece2.radius << ") = "<< ECART <<endl;
    if (piece1.pos.x < piece2.pos.x + ECART && piece1.pos.x > piece2.pos.x - ECART) {
        if(piece1.pos.y < piece2.pos.y + ECART && piece1.pos.y > piece2.pos.y - ECART){
            if (piece1.radius < piece2.radius + ECARTRAYON && piece1.radius > piece2.radius - ECARTRAYON || piece2.radius < piece1.radius + ECARTRAYON && piece2.radius > piece1.radius - ECARTRAYON){
                return true;
            }
        }
    }
    return false;
}

Piece fusion2Pieces(Piece piece1, Piece piece2){

    Piece pieceFusionne;
    pieceFusionne.pos.x = (piece1.pos.x+piece2.pos.x)/2;
    pieceFusionne.pos.y = (piece1.pos.y+piece2.pos.y)/2;
    pieceFusionne.radius= (piece1.radius+piece2.radius)/2;

    return pieceFusionne;
}
