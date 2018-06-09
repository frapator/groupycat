#ifndef PIECE_HPP
#define PIECE_HPP

#include <iostream>
#include "Position.hpp"

class Piece {
    
    private:
        int x;
        int y;
        char c;
    
    public:
        Piece(int i, int j, char _c) : x(i), y(j), c(_c) {};
        Position GetPosition() { return Position(x, y); };
        bool IsPawn() { return c == 'p' || c == 'P';};
        bool IsQueen() { return c == 'q' || c == 'Q';};
        bool IsKing() { return c == 'k' || c == 'K';};
        bool IsRook() { return c == 'r' || c == 'R';};
        bool IsBishop() { return c == 'b' || c == 'B';};
        bool IsNight() { return c == 'n' || c == 'N';};
        char ToChar() { return c; };
        std::string ToString() { return std::string(1, c);}; 
};

#endif
