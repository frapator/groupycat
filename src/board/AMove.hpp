#ifndef AMOVE_HPP
#define AMOVE_HPP

#include <string>

class AMove : public std::string {
    private: 
        char piece_prise;
    
    public:
        bool promotion;
        float eval;
    
    // constructeur
        AMove(std::string s);
    
    public:
        void SetPrise(char piece);
        char GetPiecePrise();
};

#endif
