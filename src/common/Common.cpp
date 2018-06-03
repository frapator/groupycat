#include <iostream>

#include "Common.hpp"

namespace Common {
   
    int debug = 1;
    
    static Color nextColor(Color pColor) {
        return (pColor == Color::white) ? Color::black : Color::white;
    }

    std::string Position::toString() {
        char coords [2];
        coords[0] = 'a' + i;
        coords[1] = '0' + j;
        return std::string(coords);
    }
};
