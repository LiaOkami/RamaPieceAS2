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

void Detection::detectionPieces(const string chemin, const int nbPieces){
    listePieceCourante.clear();
    // CONSTANTES
    //------------
    int     NB_ITERATIONS = 1000;
    double  ECART_PT_BLANC = 5.0;
    int     pctSEUIL = 75/100;

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

    for(int i = 0; i < NB_ITERATIONS; i++){
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
        if(pieceTracee.value > -1 && pieceTracee.radius < imageTapis.size().width/4 && pieceTracee.radius < imageTapis.size().height/4 ){  //si la pièce retournée n'as pas d'erreur
            for(int i = 0; i < (int) tabPointsContours.size(); i++){
                Position pointVerifie(tabPointsContours[i].x, tabPointsContours[i].y);
                double distance = getDistance(pieceTracee.pos, pointVerifie);
                if(pieceTracee.radius - ECART_PT_BLANC < distance && distance < pieceTracee.radius + ECART_PT_BLANC){
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
                i = 0;
                j = 1;
            }
            j++;
        }
    }

    //------------------------------------------------
    // ---     SÉLECTION DES PIÈCES COURANTES     ---
    // Si on connait le nb de pièces, on fait des tours de boucle
    // Sinon on fait avec un seuil p/r au max
    //------------------------------------------------
    int maxPoints = 0, indexMax = 0; // Piece MAX
    for(int i = 0; i <(int)tabPiecesDetectees.size(); i++){
        if(tabPiecesDetectees[i].second > maxPoints){
            maxPoints = tabPiecesDetectees[i].second;
            indexMax = i;
        }
    }
    listePieceCourante.push_back(tabPiecesDetectees[indexMax].first);
    //AFFICHAGE TEST
    cout << "SELEC MAX | " << tabPiecesDetectees[indexMax].first.pos.x << "x | " << tabPiecesDetectees[indexMax].first.pos.y << "y | RAYON " << tabPiecesDetectees[indexMax].first.radius << ", a " << maxPoints << " points" << endl << "---------------------" << endl;
    tabPiecesDetectees.erase(tabPiecesDetectees.begin() + indexMax);
    int rayonMoyen = listePieceCourante[0].radius;

    if(nbPieces > 0){
        for(int i = 0; i<nbPieces-1; i++){
            int maxPoints = 0, indexMax = 0;
            for(int j=0; j<(int)tabPiecesDetectees.size(); j++){
                if(tabPiecesDetectees[j].second > maxPoints){
                    maxPoints = tabPiecesDetectees[j].second;
                    indexMax = j;
                }
            }
            if(rayonMoyen/2 < tabPiecesDetectees[indexMax].first.radius && tabPiecesDetectees[indexMax].first.radius < rayonMoyen*2){
                listePieceCourante.push_back(tabPiecesDetectees[indexMax].first);
                //AFFICHAGE TEST
                cout << "SELEC NBPIECE | " << tabPiecesDetectees[indexMax].first.pos.x << "x | " << tabPiecesDetectees[indexMax].first.pos.y << "y | RAYON " << tabPiecesDetectees[indexMax].first.radius << ", a " << maxPoints << " points" << endl << "----------" << endl;
                tabPiecesDetectees.erase(tabPiecesDetectees.begin() + indexMax);
            } else {
                tabPiecesDetectees.erase(tabPiecesDetectees.begin() + indexMax);
            }
        }
    } else {
        // On prend les autres pieces qui ont un nb de points proche de la pièce MAX
        int seuil = maxPoints * pctSEUIL;
        for(int i = 0; i < (int)tabPiecesDetectees.size(); i++){
            if(tabPiecesDetectees[i].second > seuil){
                if(rayonMoyen/2 < tabPiecesDetectees[i].first.radius && tabPiecesDetectees[i].first.radius < rayonMoyen*2){
                    listePieceCourante.push_back(tabPiecesDetectees[i].first);
                    //AFFICHAGE TEST
                    cout << "SELEC SEUIL | " << tabPiecesDetectees[i].first.pos.x << "x | " << tabPiecesDetectees[i].first.pos.y << "y | RAYON " << tabPiecesDetectees[i].first.radius << ", a " << tabPiecesDetectees[i].second << " points" << endl << "---------------------" << endl;
                } else {
                    tabPiecesDetectees.erase(tabPiecesDetectees.begin() + i);
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

    Mat gaus;
    GaussianBlur( imageTapisNB, gaus, Size( 5, 5 ), 0, 0 );
    cv::Canny(gaus,contours,100,500);

    //cv::Canny(imageTapis,contours, 100, 800);


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
    double ECART = 10;
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
