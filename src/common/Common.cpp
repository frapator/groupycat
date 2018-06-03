#include <iostream>

#include "Common.hpp"

namespace Common {
   
    int debug = 1;
    
    static Color nextColor(Color pColor) {
        return (pColor == Color::white) ? Color::black : Color::white;
    }

};
