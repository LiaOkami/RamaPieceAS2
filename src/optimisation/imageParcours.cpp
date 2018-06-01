/** \file imageParcours.cpp
 *  \brief fonction de gestion d'images
 */

 /**
 *  \author Stephane Achari
 */
#include <opencv2/opencv.hpp>
#include <iostream>

#include "imageParcours.h"
#include "Ramapiece.hh"
#include <vector>
#include <string>

using namespace std;
using namespace cv;

Image::Image(int width, int height){

    _img = Mat(height, width, CV_8UC3, Scalar(255, 255, 255));
}

Image::~Image(){
}

Mat Image::getImage(){
    return _img;
}

void Image::afficherImage(){
    imshow("Original image", this->getImage());
    waitKey(0);
}

void Image::sauvegardeImage(string filename){
    /*string chemin = "./images/";
    string extension = ".jpg";
    chemin += filename;
    chemin += extension*/


    imwrite(filename, this->getImage());

}

void Image::placePieceImage(vector<Piece> *tabPiece){

    for(int i =0; i<tabPiece->size(); i++){

        Point centre((*tabPiece)[i].pos.x,(*tabPiece)[i].pos.y);
        MyFilledCircle(this->getImage(),centre);
    }
}

void Image::placePieceParcourus(int x, int y){
        Point centre(x,y);
        MyFilledCircleRamasse(this->getImage(),centre);
}

void MyFilledCircle(Mat img, Point center){
    circle(img, center, 5, Scalar(0, 0, 0), FILLED, LINE_8);
}

void MyFilledCircleRamasse(Mat img, Point center){
    circle(img, center, 5, Scalar(255, 0, 0), FILLED, LINE_8);
}

