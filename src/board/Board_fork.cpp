#include <vector>
#include <boost/algorithm/string.hpp>
#include <iomanip>
#include <iostream>

#include "Board.hpp"

#include "../common/Common.hpp"
#include "AMove.hpp"
#include "Piece.hpp"
#include "Position.hpp"

using namespace std;
using namespace Common;

        std::vector <Position> Board::SearchForkPositions(Color color) {
        // fourchette = piece sur une case ou plusieurs pieces adverses sont attaquées
            
        // algo 1 : fourchettes niveau 1 (déclinable niveau 2)
            // parcourir les pieces de la couleur et chercher les coups possibles
            // puis regarder apres chaque coup combien il y a de prises possibles
            // si plusieurs prises possibles alors la case intermédiaire est une case de fourchette
            // NON IMPLEMENTE
            
        // algo 2 : cases de fourchette (pas de notion de niveau pour l'atteindre)
            // partir des pieces adverses et tagguer les cases d'ou peuvent venir chaque type de pieces
            // si une case a plusieurs tags de meme piece, c'est une case de fourchette
            
            int cf[6][8][8];
            for (int i=0; i<8; i++) {
                for (int j=0; j<8; j++) {
                    if (IsPieceAdverse(i,j)) {
                        Position p = Position(i,j);
                        // pour chaque type de piece
                        for (int t=0; t<6; t++) {
                            // chercher les cases a portée de [i][j]
                            /*
                             for (each case a portée de i,j) {
                                // les tagguer
                                cf[t][x][y] ++;
                            }*/
                        }
                    }
                }
            }
            
            std::vector <Position> pos_list;
            for (int i=0; i<8; i++) {
                for (int j=0; j<8; j++) { 
                    for (int t=0; t<6; t++) {
                        if (cf[t][i][j] >= 2) {
                            pos_list.push_back(Position(i,j));
                        }
                    }
                }
            }
                
        return pos_list;
    }
    
        std::vector <AMove> Board::SearchForkAttackMoves(Color color, Position pos) {
                std::vector <AMove> moves;
            
            return moves;
    }
    
        std::vector <AMove> Board::SearchForkDefenseMoves(Color color, Position pos) {
                std::vector <AMove> moves;
            
            return moves;
    }
