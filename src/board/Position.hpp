#ifndef POSITION_HPP
#define POSITION_HPP

#include <vector>
#include <iostream>

class Position {
        private:
            int x;
            int y;
            
        public:
            Position(int i, int j) : x(i), y(j) { };
            std::string toString();
            std::vector <Position> GetKDestinations();
    };

#endif
