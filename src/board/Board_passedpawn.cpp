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

    // fonctions de recherche
    bool Board::IsPassedPawn(Color color, int x, int y) {
        int xmin = x - 1 < 0 ? 0 : x - 1;
        int xmax = x + 1 > 7 ? 7 : x + 1;
        int ymin = (color == Color::white) ? (y + 1 > 7 ? 7 : y + 1) : 0;
        int ymax = (color == Color::white) ? 7 : (y - 1 < 0 ? 0 : y - 1);
        bool found_pion_adverse = false;
        char pion_adverse = (color == Color::white) ? 'p' : 'P';
        for (int i=xmin; i<xmax; i++) {
            for (int j=ymin; j<ymax; j++) {
                if (IsPionAdverse(i,j)) {
                    found_pion_adverse = true;
                }
            }
        }
        return ! found_pion_adverse;
    }
    
    // pion passé
        std::vector <Position> Board::SearchPionsPassesPositions(Color color) {
        // identification/recherche des pions passés de la couleur en parametre
        // pion passé = pion de la couleur  sans pion adverse devant sur la meme colonne ou les colonnes adjacentes
            std::vector <Position> pos_list;
        char pion = (color == Color::white) ? 'P' : 'p';
        // pour chaque pion 
        for (int i=0; i<8; i++) {
            for (int j=0; j<8; j++) {
                if (IsPion(i,j)) {
                    // pour chaque pion
                    if (IsPassedPawn(color, i,j)) {
                        // pion passé
                            if (Common::debug) cout << "pion passé : " << i << "," << j << endl;
                        pos_list.push_back(Position(i,j));
                    }
                }
            }
        }
            
        return pos_list;
    }
    
    // recherches de coups
    
        std::vector <AMove> Board::SearchPionPasseAttackMoves(Color color, Position pos) {
        // recherche les coups pour appuyer le pion passé en attaque/Defense
        
        
        // pour chacun des pions passés en déduire une liste de coups
            std::vector <AMove> moves;
            
        return moves;
    }
    
        std::vector <AMove> Board::SearchPionPasseDefenseMoves(Color color, Position pos) {
        // recherche les coups pour appuyer le pion passé en attaque/Defense
        
        
        // pour chacun des pions passés en déduire une liste de coups
            std::vector <AMove> moves;
            
        return moves;
    }
