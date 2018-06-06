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
    detect.detectionPieces("images/01.jpg", 8);

    //Détection multiple
    int NBIMAGES = 11;
    pair<string,int> tabTapis[] = {make_pair("images/01.jpg", 8), make_pair("images/02.jpg", 1), make_pair("images/03.jpg", 1), make_pair("images/04.jpg", 1), make_pair("images/05.jpg", 1)
                                , make_pair("images/test-02.jpg", 2), make_pair("images/test-03.jpg", 2), make_pair("images/test-04.jpg", 2), make_pair("images/test-05.jpg", 2), make_pair("images/test-06.jpg", 2), make_pair("images/test-07.jpg", 2)
                                };
    for(int i=0; i<NBIMAGES; i++){
        detect.detectionPieces(tabTapis[i].first, tabTapis[i].second);
    }
    //*/
    return (0);
}

