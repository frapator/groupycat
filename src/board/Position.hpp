#ifndef POSITION_HPP
#define POSITION_HPP

#include <vector>
#include <iostream>

class Position {
        private:
            int x;
            int y;
            
        public:
            std::string toString();
            std::vector <std::string> GetKDestinations();
    };

#endif
