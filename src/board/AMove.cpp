#include <string>

#include "AMove.hpp"

AMove::AMove(std::string s) : std::string(s) {
    piece_prise = ' ';
    promotion = false;
    eval = 0;
}
    
void AMove::SetPrise(char piece) {
    piece_prise = piece;
}
char AMove::GetPiecePrise() {
    return piece_prise;
}
