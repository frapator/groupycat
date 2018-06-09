#ifndef POSITION_HPP
#define POSITION_HPP

#include <iostream>

class Position {
        private:
            int x;
            int y;
            
        public:
            std::string toString();
            std::vector <string> GetKDestinations();
    };

#endif
