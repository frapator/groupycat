#ifndef COMMON_HPP
#define COMMON_HPP

#include <iostream>

namespace Common {
    extern int debug;
    
    enum class Color { white, black};   

    static Color nextColor(Color pColor);

}

#endif
