/** \file imageParcours.cpp
 *  \brief fonction de gestion d'images
 */

 /**
 *  \author Stephane Achari
 */
#include <opencv2/opencv.hpp>

#include "imageParcours.h"
#include <string>

using namespace std;
using namespace cv;

Image::Image(int width, int height){
    _img = Mat(height, width, CV_8UC3, Scalar(255, 255, 255));
}

Image::~Image(){
}

const Mat & Image::getImage(){
    return _img;
}

void Image::afficherImage(){
    imshow("Original image", this->getImage());
    waitKey(0);
}

void Image::sauvegardeImage(const string &filename){
    imwrite(filename, this->getImage());
}

void Image::placeRobotStart(const Position &pos){
    Point centre(pos.x, pos.y);
    MyFilledCircle(this->getImage(),centre);
}

void Image::placePieceImage(vector<Piece> *tabPiece){
    for(unsigned int i = 0 ; i < tabPiece->size() ; i++) {
        Point centre((*tabPiece)[i].pos.x,(*tabPiece)[i].pos.y);
        MyFilledCircle(this->getImage(),centre);
    }
}

void Image::placePieceParcourus(const Position &pos){
    Point centre(pos.x, pos.y);
    MyFilledCircleRamasse(this->getImage(),centre);
}

void Image::deplaceRobot(Position depart, Position arrivee, int r, int g, int b){

    Point dep(depart.x,depart.y);
    Point arri(arrivee.x,arrivee.y);

    line(this->getImage(), dep, arri, Scalar(r,g,b), 1, 8, 0);
}

void MyFilledCircle(const Mat &img, Point center){
    circle(img, center, 5, Scalar(0, 0, 0), FILLED, LINE_8);
}

void MyFilledCircleRamasse(const Mat &img, Point center){
    circle(img, center, 5, Scalar(255, 0, 0), FILLED, LINE_8);
}

void Image::placerobotDepart(const Position & pos){
    Point pt1(pos.x-10, pos.y-10);
    Point pt2(pos.x+10, pos.y+10);
    rectangle(this->getImage(),pt1, pt2, Scalar(139, 0, 0), 1, 8, 0);
}
