#include <opencv2/opencv.hpp>
#include <vector>
#include <string.h>
#include <couleur.h>

void quelCouleur(std::string nom, vector<Piece> pieces){
    //ouverture du fichier
    const std::string img_file = nom;

    // Verifie si on peut ouvrir le fichier
    //si on ne peut pas ouvrir le fichier, pour que le reste du programme puisse se faire quand même, la valeur des pièces est mise à 0
    cv::Mat piece = cv::imread(img_file, CV_LOAD_IMAGE_COLOR);
    if(!piece.data) {
        std::cout << "Can't open file " << img_file << std::endl;

        for(unsigned int i=0; i<pieces.size(); i++){
            pieces[i].value = 0;
        }
        exit(-1);
    }

    cv::Mat imgLAB;
    cvtColor(piece, imgLAB, cv::COLOR_BGR2Lab); //conversion de la décomposition de la couleur en CIELab
    cv::Mat img_lab[3];
    split(imgLAB, img_lab);

    double moyA[2];
    double moyB[2];

    couleur(img_lab, centre, ray, moyA, moyB);
}
