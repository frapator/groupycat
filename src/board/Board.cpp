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
     
     void Board::SetPiece(Position _pos, Piece _piece) {
        if (debug>0) std::cout << "set " << _pos.to_string() << " = " << _piece.to_char() << endl;
        pos[_pos.x][_pos.y] = _piece;
        if (debug>0) std::cout << "SetPiece :  pos " << _pos.x << "," << _pos.y << " = " << pos[_pos.x][_pos.y].to_string() << endl;
    }
    
    void Board::ClearPosition(Position _pos)  {
        Piece piece = Piece();
        piece.Clear();
        SetPiece(_pos, piece);
    }
    
    bool Board::IsPawn(int x, int y) {
        return GetPiece(x,y).IsPawn();
    };
    
    char Board::PionAdverse() {
        return (trait== Color::white) ? 'p' : 'P';
    }

    void Board::SetStartPos(Color ptrait) {
        if (debug > 0) std::cout << "starting pos ..." << std::endl;
        trait = ptrait;
        for (int i=0; i<8; i++) {
            for (int j=0; j<8; j++) {
                //std::cout << "i,j : " << i << "," << j << endl;
                SetPiece(Position(i, j), startpos[i][j]);
            }
        }
    }
    
    void Board::SetFen(string fen) {
        // TODO a coder
    }
    
    void Board::Move(AMove pMove) {
        if (debug > 0) std::cout << "moving " << pMove.to_string() << std::endl;
        
        // on copie la piece sur la cible
        Piece lOrigPiece = GetPiece(pMove.orig);
        if (debug > 0) std::cout << "piece " << lOrigPiece.to_string() << std::endl;
        SetPiece(pMove.dest, lOrigPiece.to_char());
        
        // on efface la position initiale
        ClearPosition(pMove.orig);
                
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
                cout << GetPiece(i,j).to_char();
            }
            cout << endl;
        }
    }
