#include <vector>
#include <boost/algorithm/string.hpp>
#include <iomanip>
#include <iostream>

#include "Board.hpp"

#include "../common/Common.hpp"
#include "AMove.hpp"
#include "Position.hpp"

using namespace std;
using namespace Common;

    // clouage
    
        std::vector <Position> Board::SearchPinPositions(Color color) {
        // identification/recherche des pions passés de la couleur en parametre
        // pion passé = pion de la couleur  sans pion adverse devant sur la meme colonne ou les colonnes adjacentes
            std::vector <Position> pos_list;
        
        return pos_list;
    }
    
        std::vector <AMove> Board::SearchPinAttackMoves(Color color, Position pos) {
                std::vector <AMove>  moves;
            
            return moves;
    }
    
        std::vector <AMove> Board::SearchPinDefenseMoves(Color color, Position pos) {
                std::vector <AMove> moves;
            
            return moves;
    }
