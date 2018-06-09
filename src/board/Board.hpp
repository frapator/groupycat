#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <boost/algorithm/string.hpp>
#include <iomanip>

#include "../common/Common.hpp"
#include "Piece.hpp"
#include "AMove.hpp"
#include "Position.hpp"

using namespace std;
using namespace Common;

class Board  {
    private: 
        static const char empty_square = '.';
        static const char pawn = 'p';
        
        /*const Piece pieces[2][6] = {
                {'R', 'N', 'B', 'Q', 'K', 'P'},
                {'r', 'n', 'b', 'q', 'k', 'p'}
        };*/
        
        char pos[8][8];
        //std::vector <Piece> pos2;
        
        char startpos[8][8] = {
            {'R','P','.','.','.','.','p','r'},
            {'N','P','.','.','.','.','p','n'},
            {'B','P','.','.','.','.','p','b'},
            {'Q','P','.','.','.','.','p','q'},
            {'K','P','.','.','.','.','p','k'},
            {'B','P','.','.','.','.','p','b'},
            {'N','P','.','.','.','.','p','n'},
            {'R','P','.','.','.','.','p','r'}
        };
    
    public:
        
        Color trait;
        Piece GetPiece(int i, int j);
        std::vector <Piece> GetPieces();
        char PionAdverse();
        void SetStartPos(Color ptrait);
        void SetFen(string fen);
        void Move(AMove pMove);
        void UnMove(AMove pMove);
        void Show();
        
        // commun
        Color nextColor();
        bool IsPawn(int x, int y) { return GetPiece(x,y).IsPawn(); };
        bool IsPieceAdverse(int x, int y);
        bool IsPionAdverse(int x, int y) { return IsPieceAdverse(x, y) && IsPawn(x,y); }
        std::vector <AMove> GetPossibleMoves();
        AMove GetRandomMove();
                
        // pion passé
        bool IsPassedPawn(Color color, int x, int y);
        std::vector <Position> SearchPionsPassesPositions(Color color);
        std::vector <AMove> SearchPionPasseAttackMoves(Color color, Position pos);
        std::vector <AMove> SearchPionPasseDefenseMoves(Color color, Position pos);
        
         // Fourchettes
        
          std::vector <Position> SearchForkPositions(Color color);
         std::vector <AMove> SearchForkAttackMoves(Color color, Position pos);
         std::vector <AMove> SearchForkDefenseMoves(Color color, Position pos);
        
        // clouage        
         std::vector <Position> SearchPinPositions(Color color);
         std::vector <AMove> SearchPinAttackMoves(Color color, Position pos);
         std::vector <AMove> SearchPinDefenseMoves(Color color, Position pos);
       std::vector <AMove> SearchMoves();
           
    // Evaluation
        
    float EvaluatePassedPawns(std::vector <Position> pos_list);
    float EvaluateForkPositions(std::vector <Position> pos_list);
    float EvaluatePinPositions(std::vector <Position> pos_list);
    float Evaluate();
};

#endif
