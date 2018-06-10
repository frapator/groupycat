#include <iostream>

#include "Position.hpp"
#include "AMove.hpp"

// Constructeur

    AMove::AMove(Position _orig, Position _dest) {
        orig = _orig;
        dest = _dest;
        piece_prise = ' ';
        promotion = false;
        eval = 0;
    }

    AMove::AMove(std::string s) {
        Position p1 = Position(0, 0); // TODO
        Position p2 = Position(1, 1); // TODO
        AMove(p1, p2);
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
