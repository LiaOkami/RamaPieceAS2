#ifndef PARCOURS_H_INCLUDED
#define PARCOURS_H_INCLUDED

#include "Ramapiece.hh"

void    triDistancePieceBras(Ramapiece &p);
void    triDistancePiecePiece(Ramapiece &p);
void    triValeur(std::vector<Piece> * tabP);
int     rechercheDicho(std::vector<Piece> * tabP, int val);

void    parcoursSimple(Ramapiece &p);
void    parcoursDesVoisins(Ramapiece &p);
void    parcoursZone(Ramapiece &p);
void    parcoursDesVoisinsZone(Ramapiece &p);

#endif // PARCOURS_H_INCLUDED
