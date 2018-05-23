#include "detection/detection.h"
#include "Piece.hh"

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <vector>
#include <iostream>
using namespace std;

int main()
{
    cout << "Detection" << endl;
    Detection detect;
    detect.detectionPieces();

    //Test tracerCercle
    //Position pos1(5.0,7.0), pos2(-2.0,6.0), pos3(2.0, -8.0);
    //Position pos1(5.0,7.0), pos2(5.0,6.0), pos3(2.0, -8.0);
    /*Position pos1(5.0,7.0), pos2(4.0,6.0), pos3(2.0, 6.0);

    Piece p = tracerPiece3points(pos1, pos2, pos3);
    cout << "Résultat : " << p.pos.x << " " << p.pos.y << endl;*/
    return (0);
}
