#include <vector>

#include "../common/Common.hpp"
#include "Board.hpp"
#include "Position.hpp"

std::string Position::toString() {
        char coords [2];
        coords[0] = 'a' + x;
        coords[1] = '0' + y;
        return std::string(coords);
    }
    
// Destinations : ne regarde pas si le coup est possible

std::vector <Position> Position::GetNightDestinations() {
    std::vector <Position> pos_list;
    
    // ne depend pas de la couleur
    
    if (x+2 < Board::size && y + 1 < Board::size) pos_list.push_back(Position(x+2, y+1));
    if (x+2 < Board::size && y - 1 >= 0) pos_list.push_back(Position(x+2, y-1));
    if (x+1 < Board::size && y + 2 < Board::size) pos_list.push_back(Position(x+1, y+2));
    if (x+1 < Board::size && y - 2 >= 0) pos_list.push_back(Position(x+1, y-2));
    if (x-1 >= 0 && y + 2 < Board::size) pos_list.push_back(Position(x-1, y+2));
    if (x-1 >= 0 && y - 2 >= 0) pos_list.push_back(Position(x-1, y-2));
    if (x-2 >= 0 && y + 1 < Board::size) pos_list.push_back(Position(x-2, y+1));
    if (x-2 >= 0 && y - 1 >= 0) pos_list.push_back(Position(x-2, y-1));
    
    return pos_list;
};

std::vector <Position> Position::GetPawnDestinations(Common::Color _c) {
    std::vector <Position> pos_list;
    
    // déplacement dépend de la couleur
    if (_c == Common::Color::white) {
        if (y + 1 < 8) {
            // avance
            pos_list.push_back(Position(x, y+1));
            // prise a droite
            if (x + 1 < 8) pos_list.push_back(Position(x+1, y+1));
            // prise a gauche
            if (x - 1 >=0) pos_list.push_back(Position(x-1, y+1));
        } else {
            // coup de départ
            if (y == 2) pos_list.push_back(Position(x, y+2));
        }
    } else {
        // TODO factoriser avec le if (pas si simple a cause des tests qui ne sont pas commutatifs < >, sauf a faire plus generique en testant les 2 bornes tout le temps)
        if (y - 1 >=0) {
            // avance
            pos_list.push_back(Position(x, y-1));
            // prise aile roi
            if (x + 1 < 8) pos_list.push_back(Position(x+1, y-1));
            // prise aile dame
            if (x - 1 >=0) pos_list.push_back(Position(x-1, y-1));
        } else {
            // coup de départ
            if (y == Board::size - 1) pos_list.push_back(Position(x, y-2));
        }
    }
    
    return pos_list;
}
std::vector <Position> Position::GetBishopDestinations() {
    std::vector <Position> pos_list;
    
    // ne dépend pas de la couleur
    
    return pos_list;
}
std::vector <Position> Position::GetRookDestinations() {
    std::vector <Position> pos_list;
    
    // ne dépend pas de la couleur
    
    return pos_list;
}
std::vector <Position> Position::GetQueenDestinations() {
    std::vector <Position> pos_list;
    
    // ne dépend pas de la couleur
    
    return pos_list;
}

std::vector <Position> Position::GetKingDestinations() {
    std::vector <Position> pos_list;
    
    // ne dépend pas de la couleur
    
    return pos_list;
}
