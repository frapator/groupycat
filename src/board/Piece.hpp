#ifndef PIECE_HPP
#define PIECE_HPP

#include <iostream>

class Piece {
    
    private:
        int x;
        int y;
        char c;
    
    public:
        Piece(int i, int j, char _c) : x(i), y(j), c(_c) {};
        
        static bool IsPion(Piece _p) { return _p.c == 'p' || _p.c == 'P';};
        char ToChar() { return c; };
        std::string ToString() { return std::string(1, c);}; 
};

#endif
