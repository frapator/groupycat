#ifndef AMOVE_HPP
#define AMOVE_HPP

#include <iostream>

#include "Position.hpp"

class AMove {
    private: 
        char piece_prise;
    
    public:
        bool promotion;
        float eval;
        Position orig, dest;
    
        // constructeurs
        AMove(Position _orig, Position _dest);
        AMove(std::string s);
        AMove() : AMove("") { };

    public:
        void SetPrise(char piece);
        char GetPiecePrise();

        std::string to_string();
};

#endif
