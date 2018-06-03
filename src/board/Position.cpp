#include "Position.hpp"

std::string Position::toString() {
        char coords [2];
        coords[0] = 'a' + i;
        coords[1] = '0' + j;
        return std::string(coords);
    }
