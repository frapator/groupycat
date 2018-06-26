#include <vector>
#include <boost/algorithm/string.hpp>
#include <iomanip>
#include <iostream>

#include "Board.hpp"

#include "../common/Common.hpp"
#include "Piece.hpp"
#include "AMove.hpp"

using namespace std;
using namespace Common;

     // fonctions de recherche

    bool Board::IsEmpty(int i, int j) {
            Piece p = GetPiece(i, j);
            
            return p.IsEmpty();
    }
    
    bool Board::IsPieceAdverse(int i, int j) {
            Piece p = GetPiece(i, j);
            
            return trait != p.GetColor();
    }
    
    std::vector <AMove> Board::GetPossibleMoves() {
        std::vector <AMove> lMoves;
        
        if (Common::debug) cout << " searching possible moves from following position : " << endl;
        if (Common::debug) Show();
        
        for (int x=0; x<8; x++) {
            for (int y=0; y<8; y++) {
                // si case vide
                if (IsEmpty(x,y)) {
                    continue;
                }
                // si case avec piece adverse
                if (IsPieceAdverse(x,y)) {
                    continue;
                }
                // si case avec piece du joueur
                Piece lPiece = GetPiece(x,y);
                Position lPiecePosition = Position(x,y);
                if (Common::debug) cout << lPiece.to_char() << lPiecePosition.to_string();
                std::vector <Position> lDestinations;
                
                if (lPiece.IsPawn()) {
                    if (Common::debug) cout << " (pawn)" << lPiecePosition.to_string() << endl;
                    // ajout des déplacements sans prise
                    std::vector <Position> lMoveDestinations = lPiecePosition.GetPawnMoveDestinations(trait);
                    lDestinations.insert(lDestinations.end(), lMoveDestinations.begin(), lMoveDestinations.end());
                    
                    // ajout des prises
                    std::vector <Position> lTakeDestinations = lPiecePosition.GetPawnTakeDestinations(trait);
                    for (int i=0; i<lTakeDestinations.size(); i++) {
                        if (IsPieceAdverse(lTakeDestinations[i])) {
                            lDestinations.push_back(lTakeDestinations[i]);
                        }
                    }
                } else {
                    if (Common::debug) cout << " (not pwan) " << lPiecePosition.to_string() << endl;
                }
                //if (Common::debug) cout << " peut aller en : ";
                for (int j=0; j<lDestinations.size(); j++) {
                    AMove lMove = AMove(lPiecePosition, lDestinations[j]);
                    lMoves.push_back(lMove);
                    if (Common::debug) cout << " " << lDestinations[j].to_string();
                }
                if (Common::debug) cout << endl;
            }
        }
        return lMoves;
    }
    
    AMove Board::GetRandomMove(std::vector <AMove> pMovesList) {
            if (Common::debug) cout << pMovesList.size() << " coups possibles trouvés" << endl;
            int r = rand() % pMovesList.size();
            if (Common::debug) cout << "coup choisi : " << pMovesList[r].to_string() << endl;
            return pMovesList[r];
    }
    
    // cherche les coups en fonction des caracteristiques
    
    std::vector <AMove> Board::SearchMoves() {
        std::vector <Position> positions; // les positions clefs pour la recherche de coups
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
    

