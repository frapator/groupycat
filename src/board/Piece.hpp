#ifndef PIECE_HPP
#define PIECE_HPP

#include <iostream>
#include "../common/Common.hpp"
#include "Position.hpp"

class Piece {
    
    private:
        int x;
        int y;
        char c;
        
    public:
        Piece() : x(-1), y(-1), c('.') {};
        Piece(int i, int j, char _c) : x(i), y(j), c(_c) {};
        Piece(Position p, char _c) : x(p.x), y(p.y), c(_c) {};
        
        Position GetPosition() { return Position(x, y); };
        Common::Color GetColor();
        
        bool IsPawn() { return c == 'p' || c == 'P';};
        bool IsQueen() { return c == 'q' || c == 'Q';};
        bool IsKing() { return c == 'k' || c == 'K';};
        bool IsRook() { return c == 'r' || c == 'R';};
        bool IsBishop() { return c == 'b' || c == 'B';};
        bool IsNight() { return c == 'n' || c == 'N';};
        
        char to_char() { return c; };
        std::string to_string() { return std::string(1, c) + GetPosition().to_string();}; 
};

#endif
