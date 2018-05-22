#include "detection/detection.h"
#include "Piece.hh"

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <cstdlib>
#include <ctime>

#include <vector>
#include <iostream>

#include <iostream>
using namespace std;

int main()
{
    cout << "detection" << endl;
    Detection detect;
    detect.detectionPieces();
    return (0);
}
