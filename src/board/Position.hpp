#ifndef POSITION_HPP
#define POSITION_HPP

#include <vector>
#include <iostream>

#include "../common/Common.hpp"

class Position {
        private:
            int x;
            int y;
            
        public:
            Position(int i, int j) : x(i), y(j) { };
            std::string toString();
            std::vector <Position> GetPawnDestinations(Common::Color _c);
            std::vector <Position> GetNightDestinations();
            std::vector <Position> GetBishopDestinations();
            std::vector <Position> GetRookDestinations();
            std::vector <Position> GetQueenDestinations();
            std::vector <Position> GetKingDestinations();
    };

#endif
