#include <vector>
#include <iostream>

#include "../common/Common.hpp"
#include "Board.hpp"
#include "Position.hpp"

// constructeur

// to_string

std::string Position::to_string() {
    char coords [2];
    coords[0] = 'a' + x;
    coords[1] = '1' + y;
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

std::vector <Position> Position::GetPawnMoveDestinations(Common::Color _c) {
    std::vector <Position> pos_list;
    
    // déplacement dépend de la couleur
    if (_c == Common::Color::white) {
        if (y + 1 < 8) {
            // avance
            pos_list.push_back(Position(x, y+1));
        }
        // coup de départ
        if (y == 2) pos_list.push_back(Position(x, y+2));
    } else {
        // TODO factoriser avec le if (pas si simple a cause des tests qui ne sont pas commutatifs < >, sauf a faire plus generique en testant les 2 bornes tout le temps)
        if (y - 1 >=0) {
            // avance
            pos_list.push_back(Position(x, y-1));
        }
        // coup de départ
        if (y == Board::size - 1) pos_list.push_back(Position(x, y-2));
    }
    return pos_list;
}

std::vector <Position> Position::GetPawnTakeDestinations(Common::Color _c) {
    std::vector <Position> pos_list;
    
    // déplacement dépend de la couleur
    if (_c == Common::Color::white) {
        if (y + 1 < 8) {
            // prise a droite
            if (x + 1 < 8) pos_list.push_back(Position(x+1, y+1));
            // prise a gauche
            if (x - 1 >=0) pos_list.push_back(Position(x-1, y+1));
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
        }
    }
    
    return pos_list;
}

std::vector <Position> Position::GetBishopDestinations() {
    std::vector <Position> pos_list;
    
    // ne dépend pas de la couleur
    
    for (int i=0; i<7; i++) {
        // vers a8
        if (x-1 >= 0 && y+1 < Board::size) pos_list.push_back(Position(x-1, y+1));
        
        // vers h8
        if (x+1 >= 0 && y+1 < Board::size) pos_list.push_back(Position(x+1, y+1));
        
        // vers h1
        if (x+1 < Board::size && y-1 >= 0) pos_list.push_back(Position(x+1, y-1));
        
        // vers a1
        if (x-1 >= 0 && y-1 >= 0) pos_list.push_back(Position(x-1, y-1));
    }
    
    return pos_list;
}
std::vector <Position> Position::GetRookDestinations() {
    std::vector <Position> pos_list;
    
    // ne dépend pas de la couleur
    
     for (int i=0; i<7; i++) {
        // vers a8
        if (x-1 >= 0 && y+1 < Board::size) pos_list.push_back(Position(x-1, y+1));
        
        // vers h8
        if (x+1 >= 0 && y+1 < Board::size) pos_list.push_back(Position(x+1, y+1));
        
        // vers h1
        if (x+1 < Board::size && y-1 >= 0) pos_list.push_back(Position(x+1, y-1));
        
        // vers a1
        if (x-1 >= 0 && y-1 >= 0) pos_list.push_back(Position(x-1, y-1));
    }
    
    return pos_list;
}
std::vector <Position> Position::GetQueenDestinations() {
    std::vector <Position> pos_list;
    
    // ne dépend pas de la couleur
    
    //GetBishopDestinations
    //GetRookDestinations
    //retirer les doublons
    
    return pos_list;
}

std::vector <Position> Position::GetKingDestinations() {
    std::vector <Position> pos_list;
    
    // le roque dépend de la couleur
    // TODO ajouter le roque
    
    // les autres coups ne dépendent pas de la couleur
    
    // monter (y+1)
    if (y+1 < Board::size) {
        if (x-1 >= 0) pos_list.push_back(Position(x-1, y+1));
        pos_list.push_back(Position(x, y+1));
        if (x+1 < Board::size) pos_list.push_back(Position(x+1, y+1));
    }
    
    // latéral (y constant)
    if (x-1 >= 0) pos_list.push_back(Position(x-1, y));
    if (x+1 < Board::size) pos_list.push_back(Position(x+1, y));
    
    // descendre (y-1)
    if (y-1 >= 0) {
        if (x-1 >= 0) pos_list.push_back(Position(x-1, y-1));
        pos_list.push_back(Position(x, y-1));
        if (x+1 < Board::size) pos_list.push_back(Position(x+1, y-1));
    }
        
    return pos_list;
}
