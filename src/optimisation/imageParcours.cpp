#include <opencv2/opencv.hpp>
#include <iostream>

#include "imageParcours.h"
#include "Ramapiece.hh"
#include <vector>

using namespace std;
using namespace cv;

Image::Image(int width, int height){

    _imgBlanche = Mat(height, width, CV_8UC3, Scalar(255, 255, 255));

}

Image::~Image(){
}

Mat Image::getImageBlanche(){
    return _imgBlanche;
}

void Image::afficherImage(){
    imshow("Original image", this->getImageBlanche());
    waitKey(0);
}


void Image::placePieceImage(vector<Piece> *tabPiece){

    for(int i =0; i<tabPiece->size(); i++){

        Point centre((*tabPiece)[i].pos.x,(*tabPiece)[i].pos.y);
        MyFilledCircle(this->getImageBlanche(),centre);
    }
}

void MyFilledCircle(Mat img, Point center){

    circle(img, center, 5, Scalar(0, 0, 0), FILLED, LINE_8);
}
