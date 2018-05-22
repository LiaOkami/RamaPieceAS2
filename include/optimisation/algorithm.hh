/** \file algorithm.hh
 *  \brief Fichier contenant les fonction wrappant les algorithmes
 */

#ifndef _ALGORITHM_HH_
# define _ALGORITHM_HH_

# include <utility>
# include "Ramapiece.hh"

typedef void    (*t_func_algorithm)(Ramapiece &);
typedef std::pair<std::string, t_func_algorithm> t_algorithm;
typedef void    (*t_func_algorithm_param)(Ramapiece &, int);
typedef std::pair<std::string, t_func_algorithm_param> t_algorithm_param;

extern const t_algorithm funcs[];
extern const t_algorithm_param funcs_param[];

/** \brief Ouvre un menu terminal pour choisir son algorithme
 *  \param Ramapiece& ramapiece
 */
void    menu();

#endif // _ALGORITHM_HH_

