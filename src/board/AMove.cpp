#include <string>

#include "Position.hpp"
#include "AMove.hpp"

// Constructeurs
AMove::AMove(std::string s) : std::string(s) {
    piece_prise = ' ';
    promotion = false;
    eval = 0;
}

AMove::AMove(Position _orig, Position _dest) {
    AMove(_orig.toString() + _dest.toString());
}
    
// Getters / setters
void AMove::SetPrise(char piece) {
    piece_prise = piece;
}
char AMove::GetPiecePrise() {
    return piece_prise;
}
