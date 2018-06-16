#include <iostream>

#include "Position.hpp"
#include "AMove.hpp"

// Constructeur

    AMove::AMove(Position _orig, Position _dest) {
        orig = new Position(_orig);
        dest = new Position(_dest);
        piece_prise = ' ';
        promotion = false;
        eval = 0;
    }

    AMove::AMove(std::string s) {
        //std::cout << "create move : " << s << std::endl;
        orig = new Position(s[0], s[1]);
        dest = new Position(s[2], s[3]);
    }

    std::string AMove::to_string() { 
        return orig.to_string() + dest.to_string();
    };
        
// Getters / setters
void AMove::SetPrise(char piece) {
    piece_prise = piece;
}
char AMove::GetPiecePrise() {
    return piece_prise;
}
