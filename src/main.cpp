#include <vector>
#include "Ramapiece.hh"

int main(int ac, char **av)
{
    srand(time(NULL));
    std::vector<Piece>  *pieces = partie1();
    Ramapiece ramapiece(pieces, Robot(Position(0, 0)));
    menu(ramapiece);
    return (0);
}
