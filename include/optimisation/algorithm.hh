/** \file algorithm.hh
 *  \brief Structure Algorithm
 */

#ifndef _ALGORITHM_HH_
# define _ALGORITHM_HH_

# include <utility>
# include "parcours.hh"
# include "Ramapiece.hh"

typedef void    (*t_func_algorithm)(Ramapiece &);
typedef std::pair<std::string, t_func_algorithm> t_algorithm;
typedef void    (*t_func_algorithm_money)(Ramapiece &, int);
typedef std::pair<std::string, t_func_algorithm_money> t_algorithm_money;

/** \brief Structure contenant les différents algorithmes
*   \author Pierrick Garcia
*/
struct RamapieceAlgorithm {
    static const t_algorithm    algos[];
    static const t_algorithm_money  algosMoney[];
};

#endif // _ALGORITHM_HH_

