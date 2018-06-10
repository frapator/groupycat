#include <iostream>
#include <boost/algorithm/string/join.hpp>

#include "Variante.hpp"
#include "AMove.hpp"

std::string Variante::to_string() {
    std::string s = "";
    
    for (int i=0; i<size(); i++) {
        s += this[i].to_string();
    }
    return s;
}
