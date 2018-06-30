#include <iostream>
#include <boost/algorithm/string/join.hpp>

#include "Piece.hpp"
#include "Position.hpp"
#include "AMove.hpp"
#include "Variante.hpp"

std::string Variante::to_string() {
    std::string s = "";
    
    for (int i=0; i<size(); i++) {
        
        s += vector<AMove>::at(i).to_string();
    }
    return s;
}
