#include <couleur.h>
#include <math.h>       /* sqrt */
#include <stdio.h>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

void couleur(cv::Mat img[], Piece &p){
    //initialisation des valeurs
    double a0 =0;
    double a1=0;
    double b0=0;
    double b1=0;

    double r2 = 3*p.radius/4; //rayon du cercle interieur sur des pièce de 1 et 2 euros

    int nb_pix_ext = 0;
    int nb_pix_int = 0;

    for( int i = p.pos.x-p.radius; i< p.pos.x+p.radius; i+=10){
            //on ne regarde pas les pixels en dehors du carré entourant exactement la pièce
        for(int j = p.pos.y-p.radius; j < p.pos.y+p.radius; j+=10){
            double dist = (i - p.pos.x)*(i- p.pos.x) + (j- p.pos.y)*(j-p.pos.y);
            if( dist< p.radius*p.radius && dist > r2*r2){
                //pixel appartient à la pièce, dans l'anneau extérieur
                nb_pix_ext++;
                int nv_a = img[1].at<short int>(j,i);
                a0 += nv_a;
                int nv_b = img[2].at<short int>(j,i);
                b0 += nv_b;
            }else if(dist < r2*r2){
                // le pixel appartient au disque intérieur de la pièce
                nb_pix_int++;
                int nv_a = img[1].at<short int>(j,i);
                a1 += nv_a;
                int nv_b = img[2].at<short int>(j,i);
                b1 += nv_b;
            }
        }
    }

    p.moyA[0] = a0/nb_pix_ext;
    p.moyA[1] = a1/nb_pix_int;
    p.moyB[0] = b0/nb_pix_ext;
    p.moyB[1] = b1/nb_pix_int;
}

int traitementImg(std::string nom, int choix){

    //ouverture du fichier
    const std::string img_file = nom;

    // Verifie si on peut ouvrir le fichier
    cv::Mat piece = cv::imread(img_file, CV_LOAD_IMAGE_COLOR);
    if(!piece.data) {
        std::cout << "Can't open file " << img_file << std::endl;
        return -1;
    }

    cv::Mat imgLAB;
    cvtColor(piece, imgLAB, cv::COLOR_BGR2Lab);
    cv::Mat img_lab[3];
    split(imgLAB, img_lab);

    //mes images de références sont faites de manière à ce que la pièce soit parfaitement contenue dedans
    //les bords de la pièce touchent le bord de l'image
    int centre[2];
    centre[0] = piece.size().width /2;
    centre[1] = piece.size().height /2;

    double ray = centre[0] < centre[1] ? centre[0] : centre[1];

    Piece p(0,centre[0],centre[1], ray);

    couleur(img_lab, p);

    switch(choix){
    case 4: //code couleur pièce jaune
        p.couleur = 10;
        jaune.push_back(p);
        break;
    case 3: //code pièce rouge
        p.couleur = 1;
        rouge.push_back(p);
        break;
    case 1: //code pièce 1 euro
        p.couleur = 100;
        euro.push_back(p);
        break;
    case 2: //code pièce 2 euros
        p.couleur = 100;
        euro.push_back(p);
        break;
    default:
        break;
    }
    return 0;

}

void distance(Piece p, std::vector<std::vector<double> >& dist){

    //je n'ai pas pu utiliser le faite que je calculais des moyennes differentes pour l'extérieur et l'intérieur de la pièce
    std::vector<double> val;
    val.push_back((p.moyA[0]+p.moyA[1])/2);
    val.push_back((p.moyB[0]+p.moyB[1])/2);

    for(unsigned int i=0; i<rouge.size(); i++){
        double moyA = (rouge[i].moyA[0]+rouge[i].moyA[1])/2;
        double moyB = (rouge[i].moyB[0]+rouge[i].moyB[1])/2;
        double d = std::sqrt((val[0]-moyA)*(val[0]-moyA)+(val[1]-moyB)*(val[1]-moyB));
        dist[0].push_back(d);
    }

    for(unsigned int i=0; i<jaune.size(); i++){
        double moyA = (jaune[i].moyA[0]+jaune[i].moyA[1])/2;
        double moyB = (jaune[i].moyB[0]+jaune[i].moyB[1])/2;
        double d = std::sqrt((val[0]-moyA)*(val[0]-moyA)+(val[1]-moyB)*(val[1]-moyB));
        dist[1].push_back(d);
    }

    for(unsigned int i=0; i<euro.size(); i++){
        double moyA = (euro[i].moyA[0]+euro[i].moyA[1])/2;
        double moyB = (euro[i].moyB[0]+euro[i].moyB[1])/2;
        double d = std::sqrt((val[0]-moyA)*(val[0]-moyA)+(val[1]-moyB)*(val[1]-moyB));
        dist[2].push_back(d);
    }
}

int mini(std::vector<std::vector<double> >& d){
    double minimum = d[0][0];
    int tab = 0;
    int ind =0;
    for(int i =0; i<3; i++){
        for(unsigned int j = 0; i<d[i].size(); j++){
            if(d[i][j]<minimum){
                minimum = d[i][j];
                tab = i;
                ind = j;
            }
        }
    }
    d[tab].erase(d[tab].begin()+ind);
    switch(tab){
    case 0:
        //tab de pièces rouges
        tab = 1;
        break;
    case 1:
        //tab de pièces jaunes
        tab = 10;
        break;
    case 2:
        //tab de pièces d'euro
        tab = 100;
    default:
        //si le tableau est vide
        tab = 1; // choix arbitraire pour pouvoir donner une valeur quand même
        break;

    }
    return tab;
}

void quelCouleur(std::string nom, std::vector<Piece>& pieces){

    //creation de "base de données"
    const int taillenomImgEuro = 9;
    const std::string nomImgEuro[taillenomImgEuro] = {"200_1.png","200_2.png","100_3.png","100_1.png","100_2.png","100_4.png","100_5.png","100_6.png","100_7.png"};
    std::string pathE = "../../images/euros/";
    for(int i = 0; i<taillenomImgEuro; i++){
        traitementImg(pathE+nomImgEuro[i],1);
    }

    const int taillenomImg1 = 16;
    const std::string nomImg1[taillenomImg1] = {"1_1.png","1_2.png","1_3.png", "1_4.png","2_1.png","2_2.png","2_3.png","2_4.png","2_5.png","2_6.png","2_7.png", "5_1.png","5_2.png","5_3.png","5_4.png","5_5.png"};
    std::string pathR = "../../images/rouge/";
    for(int i=0; i<taillenomImg1; i++){
        traitementImg(pathR+nomImg1[i],3);
    }

    const int taillenomImg10 = 16;
    const std::string nomImg10[taillenomImg10] = {"10_1.png","10_2.png","10_3.png","10_4.png","10_5.png","20_1.png","20_2.png","20_3.png","20_4.png","20_5.png","20_6.png","20_7.png","20_8.png","20_9.png","50_1.png", "50_2.png" };
    std::string pathJ = "../../images/jaune/";
    for(int i=0; i<taillenomImg10; i++){
        traitementImg(pathJ+nomImg10[i],4);
    }

    // début traitement des pièces inconnues

    //ouverture du fichier
    const std::string img_file = nom;

    // Verifie si on peut ouvrir le fichier
    //si on ne peut pas ouvrir le fichier, pour que le reste du programme puisse se faire quand même
    // la valeur des pièces est mise à 0
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

    for(unsigned int i=0; i<pieces.size(); i++){
        //determiner les valeurs pour chaque pièce
        couleur(img_lab, pieces[i]);

        //calculer les distances
        std::vector<std::vector<double> > dist;
        distance(pieces[i], dist);

        //ressortir les 3 minis
        int tab1 = mini(dist);
        int tab2 = mini(dist);
        int tab3 = mini(dist);

        int sum = tab1+tab2+tab3;
        if(sum/100>1){
            pieces[i].couleur = 100;
        }else if(sum/10 != 11 && sum/10>1){
            pieces[i].couleur = 10;
        }else{
            pieces[i].couleur = 1;
        }

    }

}

void donnerValeur(std::vector<Piece>& pieces){
    // n'ayant pas la partie de détection de chiffre, nous choisissons aléatoirement un chiffre entre 1, 2 et 5 pour attribuer une valeur aux pièces
    srand (time(NULL));

    for(unsigned int i=0; i<pieces.size(); i++){
        int val;
        if(pieces[i].couleur>10){
                //la pièce est une pièce d'euro le chiffre ne peut etre que 1 ou 2
            val = rand()%2 +1;
        }else{
            val = rand()%3 +1;
            val = val==3? 5: val;
        }
        pieces[i].chiffre = val;
        pieces[i].value= val * pieces[i].couleur;

    }
}
