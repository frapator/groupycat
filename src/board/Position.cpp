#include "Position.hpp"

std::string Position::toString() {
        char coords [2];
        coords[0] = 'a' + x;
        coords[1] = '0' + y;
        return std::string(coords);
    }
    
std::vector <string> Position::GetKDestinations() {
    std::vector <string> pos_list;
    
    // x+2,y-1 etc
    
    // TODO
    
    return pos_list;
};