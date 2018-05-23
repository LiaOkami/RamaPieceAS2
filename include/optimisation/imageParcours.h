#ifndef IMAGEPARCOURS_H_INCLUDED
#define IMAGEPARCOURS_H_INCLUDED

#include <opencv2/opencv.hpp>
#include "Ramapiece.hh"
#include <vector>

using namespace std;
using namespace cv;

class Image{

    private:
        Mat _imgBlanche;

    public:
        Image(int width, int height);//hauteur et largeur du tapis
        ~Image();
        void afficherImage();
        Mat getImageBlanche();
        void placePieceImage(vector<Piece> *tabPiece);
};

void MyFilledCircle(Mat img, Point center);

#endif // IMAGEPARCOURS_H_INCLUDED
