#ifndef POSITION_HPP
#define POSITION_HPP

#include <vector>
#include <iostream>

#include "../common/Common.hpp"

class Position {
private:        
public:
    int x;
    int y;
            
public:
    // constructeurs
    Position() : x(-1), y(-1) { };
    Position(int i, int j) : x(i), y(j) { };
    Position(char i, char j) : x(i - 'a'), y(j - '1') { };
    Position(std::string s);
    
    // copy constructeurs
    Position(Position* other) : x(other->x), y(other->y) { };
        
    //
    std::string to_string();
    std::vector <Position> GetPawnDestinations(Common::Color _c);
    std::vector <Position> GetNightDestinations();
    std::vector <Position> GetBishopDestinations();
    std::vector <Position> GetRookDestinations();
    std::vector <Position> GetQueenDestinations();
    std::vector <Position> GetKingDestinations();
};

#endif
