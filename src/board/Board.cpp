#include <vector>
#include <boost/algorithm/string.hpp>
#include <iomanip>
#include <iostream>

#include "Board.hpp"

#include "../common/Common.hpp"
#include "AMove.hpp"

using namespace std;
using namespace Common;

    Color Board::nextColor() {
        return (trait == Color::white) ? Color::black : Color::white;
    }

    char Board::PionAdverse() {
        return (trait== Color::white) ? 'p' : 'P';
    }

    void Board::SetStartPos(Color ptrait) {
        if (debug > 0) std::cout << "starting pos ..." << std::endl;
        trait = ptrait;
        for (int i=0; i<8; i++) {
            for (int j=0; j<8; j++) {
                pos[i][j] = startpos[i][j];
            }
        }
    }
    
    void Board::SetFen(string fen) {
        //later
    }
    
    string Board::Position(int i, int j) { // TODO class position ?
        char coords [2];
        coords[0] = 'a' + i;
        coords[1] = '0' + j;
        return string(coords);
    }
    
    void Board::Move(AMove pMove) {
        //const char *cstr = pMove.c_str();
        int i1 = pMove[0]  - 'a';
        int j1 = pMove[1] - '1';
        int i2 = pMove[2] - 'a';
        int j2 = pMove[3] - '1';

        pos[i2][j2] = pos[i1][j1];
        pos[i1][j1] = '.';
        
        // ajouter les cas spéciaux
    }
    
    void Board::UnMove(AMove pMove) {
        //TODO a coder
        // cas normal
        
        // roque
        
        // car promotion 
        if (pMove.promotion) {
            
        }
        
        // cas prise en passant
        
        // cas prise
        
    }
    
    void Board::Show() {
        for (int i=0; i<8; i++) {
            for (int j=0; j<8; j++) {
                cout << pos[i][j];
            }
            cout << endl;
        }
    }
    
    // les caracteristiques
    // exemples : clouage, pion passé, case de fourchette, piece non protegee, 
    // pour chacune, des coups candidats doivent etre proposés
    
     // fonctions de recherche
    bool Board::IsPieceAdverse(int x, int y) {
            return trait == Color::white ? pos[x][y] >= 'a' && pos[x][y] <= 'z' : pos[x][y] >= 'A' && pos[x][y] <= 'Z'; 
    }
    
        // Fourchettes
    
        std::vector <string> Board::SearchForkPositions(Color color) {
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
            
            std::vector <string> pos_list;
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
    
        std::vector <AMove> Board::SearchForkAttackMoves(Color color, string pos) {
                std::vector <AMove> moves;
            
            return moves;
    }
    
        std::vector <AMove> Board::SearchForkDefenseMoves(Color color, string pos) {
                std::vector <AMove> moves;
            
            return moves;
    }
    
    // clouage
    
        std::vector <string> Board::SearchPinPositions(Color color) {
        // identification/recherche des pions passés de la couleur en parametre
        // pion passé = pion de la couleur  sans pion adverse devant sur la meme colonne ou les colonnes adjacentes
            std::vector <string> pos_list;
        
        return pos_list;
    }
    
        std::vector <AMove> Board::SearchPinAttackMoves(Color color, string pos) {
                std::vector <AMove>  moves;
            
            return moves;
    }
    
        std::vector <AMove> Board::SearchPinDefenseMoves(Color color, string pos) {
                std::vector <AMove> moves;
            
            return moves;
    }
    
    std::vector <AMove> Board::SearchMoves() {
        std::vector <string> positions; // les positions clefs pour la recherche de coups
        std::vector <AMove> moves;
        std::vector <AMove> lMoves;
        Color lNextColor = nextColor();
        
        // Ajout des coups d'attaque des pions passés
        if (Common::debug) cout << "SearchPionsPassesPositions ..." << endl;
        positions = SearchPionsPassesPositions(trait);
        for (int i=0; i<positions.size(); i++) {
            lMoves = SearchPionPasseAttackMoves(trait, positions[i]);
            for (int j=0; j<lMoves.size(); j++) {
                moves.push_back(lMoves[j]);
            }
        }
        // Ajout des coups de defense des pions passés adverses
        if (Common::debug) cout << "SearchPionsPassesPositions ..." << endl;
        positions = SearchPionsPassesPositions(lNextColor);
        for (int i=0; i<positions.size(); i++) {
            lMoves = SearchPionPasseDefenseMoves(lNextColor, positions[i]);
            for (int j=0; j<lMoves.size(); j++) {
                moves.push_back(lMoves[j]);
            }
        }
        
        // Ajout des coups d'attaque des cases de fourchette
        if (Common::debug) cout << "SearchForkPositions ..." << endl;
        positions = SearchForkPositions(trait);
        for (int i=0; i<positions.size(); i++) {
            lMoves = SearchForkAttackMoves(trait, positions[i]);
            for (int j=0; j<lMoves.size(); j++) {
                moves.push_back(lMoves[j]);
            }
        }
        // Ajout des coups de defense des cases de fourchette averses
        if (Common::debug) cout << "SearchForkPositions ..." << endl;
        positions = SearchForkPositions(lNextColor);
        for (int i=0; i<positions.size(); i++) {
            lMoves = SearchForkDefenseMoves(lNextColor, positions[i]);
            for (int j=0; j<lMoves.size(); j++) {
                moves.push_back(lMoves[j]);
            }
        }
        
        // Ajout des coups d'attaque des clouages
        if (Common::debug) cout << "SearchPinPositions ..." << endl;
        positions = SearchPinPositions(trait);
        for (int i=0; i<positions.size(); i++) {
            lMoves = SearchForkAttackMoves(trait, positions[i]);
            for (int j=0; j<lMoves.size(); j++) {
                moves.push_back(lMoves[j]);
            }
        }
        // Ajout des coups de defense des clouages adverses
        if (Common::debug) cout << "SearchPinPositions ..." << endl;
        positions = SearchPinPositions(lNextColor);
        for (int i=0; i<positions.size(); i++) {
            lMoves = SearchPinDefenseMoves(lNextColor, positions[i]);
            for (int j=0; j<lMoves.size(); j++) {
                moves.push_back(lMoves[j]);
            }
        }
        
        return moves;
    }
    
// Evaluation
    
float Board::EvaluatePassedPawns(std::vector <string> pos_list)  {
    if (pos_list.empty()) return 0;
    
    return pos_list.size();
}

float Board::EvaluateForkPositions(std::vector <string> pos_list)  {
    if (pos_list.empty()) return 0;
    return pos_list.size();
}

float Board::EvaluatePinPositions(std::vector <string> pos_list)  {
    if (pos_list.empty()) return 0;
    return pos_list.size();
}

float Board::Evaluate() {
    float eval = 0; 
    Color lNextColor = nextColor();
    
    std::vector <string> positions; // les positions clefs pour la recherche de coups
    positions = SearchPionsPassesPositions(trait);
    eval += EvaluatePassedPawns(positions);  
    positions = SearchPionsPassesPositions(lNextColor);
    eval += EvaluatePassedPawns(positions);  
    
    positions = SearchForkPositions(trait);
    eval += EvaluateForkPositions(positions);
    positions = SearchForkPositions(lNextColor);
    eval += EvaluateForkPositions(positions);
    
    positions = SearchPinPositions(trait);
    eval += EvaluatePinPositions(positions);
    positions = SearchPinPositions(lNextColor);
    eval += EvaluatePinPositions(positions);
            
    return eval;
}
