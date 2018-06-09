#ifndef AMOVE_HPP
#define AMOVE_HPP

#include <string>

#include "Position.hpp"

class AMove : public std::string {
    private: 
        char piece_prise;
    
    public:
        bool promotion;
        float eval;
    
    // constructeurs
        AMove(std::string s);
        AMove(Position _orig, Position _dest);
        
    public:
        void SetPrise(char piece);
        char GetPiecePrise();
};

#endif
