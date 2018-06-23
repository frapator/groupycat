#ifndef PIECE_HPP
#define PIECE_HPP

#include <iostream>

#include "../common/Common.hpp"

class Piece {
    
    private:
        char c;
        static const char EMPTY_PIECE  = '.';
        
    public:
        Piece() : c(Piece::EMPTY_PIECE) {}; // vide au départ
        Piece(char _c) : c(_c) {};
        
        void Clear() { c = Piece::EMPTY_PIECE; };
        
        //Position GetPosition() { return Position(x, y); };
        Common::Color GetColor();
        
        bool IsEmpty() { return c == Piece::EMPTY_PIECE; };
        bool IsPawn() { return c == 'p' || c == 'P'; };
        bool IsQueen() { return c == 'q' || c == 'Q'; };
        bool IsKing() { return c == 'k' || c == 'K'; };
        bool IsRook() { return c == 'r' || c == 'R'; };
        bool IsBishop() { return c == 'b' || c == 'B'; };
        bool IsNight() { return c == 'n' || c == 'N'; };
        
        char to_char() { return c; };
        std::string to_string() { return std::string(1, c); }; 
};

#endif
