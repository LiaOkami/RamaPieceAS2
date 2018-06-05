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
    detect.detectionPieces("images/01.jpg", 30);

    return (0);
}
