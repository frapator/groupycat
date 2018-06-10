#include <iostream>
#include <boost/algorithm/string/join.hpp>

#include "Variante.hpp"
#include "AMove.hpp"

std::string Variante::to_string() {
    std::vector<std::string> list (begin(), end());
    
    return boost::algorithm::join(list, ", ");
}
