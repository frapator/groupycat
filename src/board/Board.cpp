#include <vector>
#include <boost/algorithm/string.hpp>
#include <iomanip>
#include <iostream>

#include "Board.hpp"

#include "../common/Common.hpp"
#include "Piece.hpp"
#include "Position.hpp"
#include "AMove.hpp"

using namespace std;
using namespace Common;

    Color Board::nextColor() {
        return (trait == Color::white) ? Color::black : Color::white;
    }

     Piece Board::GetPiece(int i, int j) {  return pos[i][j]; }
     Piece Board::GetPiece(Position p) { return pos[p.x][p.y]; }
     
    std::vector<Piece> Board::GetPieces() {
        std::vector<Piece> lPieces;
        for (int i=0; i<8; i++) {
            for (int j=0; j<8; j++) {
                lPieces.push_back(pos[i][j]);
            }
        }
        return lPieces;
    }
      
    char Board::PionAdverse() {
        return (trait== Color::white) ? 'p' : 'P';
    }

    void Board::SetStartPos(Color ptrait) {
        if (debug > 0) std::cout << "starting pos ..." << std::endl;
        trait = ptrait;
        for (int i=0; i<8; i++) {
            for (int j=0; j<8; j++) {
                pos[i][j] = Piece(i, j, startpos[i][j]);
            }
        }
    }
    
    void Board::SetFen(string fen) {
        // TODO a coder
    }
    
    void Board::Move(AMove pMove) {
        // on copie la piece sur la cible
        Piece lOrig = GetPiece(pMove.orig);
        SetPiece(pMove.dest, lOrig.ToChar());
        
        // on efface la position initiale
        SetPiece(lOrig.GetPosition(), '.');
        
        // ajouter les cas spéciaux
        
        // prise en passant
        
        // roque
        
        // promotion
        
        // echec
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
                cout << GetPiece(i,j).ToChar();
            }
            cout << endl;
        }
    }
