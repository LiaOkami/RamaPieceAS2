#ifndef PARCOURS_H_INCLUDED
#define PARCOURS_H_INCLUDED

vector<piece> triDistancePieceBras(Ramapiece p);
vector<piece> triDistancePiecePiece(const std::vector<int> & tabP);
vector<Piece> triValeur(const std::vector<int> & tabP);
int rechercheDicho(const std::vector<int> & tabP, int val);

void parcoursSimple(Ramapiece p);
void parcoursDesVoisins(Ramapiece p);
void parcoursCirculaire(Ramapiece p);
void parcoursZone(Ramapiece p);

#endif // PARCOURS_H_INCLUDED
