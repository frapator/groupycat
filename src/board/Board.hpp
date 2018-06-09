#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <boost/algorithm/string.hpp>
#include <iomanip>

#include "../common/Common.hpp"
#include "AMove.hpp"

using namespace std;
using namespace Common;

class Board  {
    private: 
        static const char empty_square = '.';
        static const char pawn = 'p';
        
        const char pieces[2][6] = {
                {'R', 'N', 'B', 'Q', 'K', 'P'},
                {'r', 'n', 'b', 'q', 'k', 'p'}
        };
        
        char pos[8][8];
        
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
        char PionAdverse();
        void SetStartPos(Color ptrait);
        void SetFen(string fen);
        string Position(int i, int j);
        void Move(AMove pMove);
        void UnMove(AMove pMove);
        void Show();
        
        // commun
        Color nextColor();
        bool IsPieceAdverse(int x, int y);
        
        // pion passé
        bool IsPassedPawn(Color color, int x, int y);
        std::vector <string> SearchPionsPassesPositions(Color color);
        std::vector <AMove> SearchPionPasseAttackMoves(Color color, string pos);
        std::vector <AMove> SearchPionPasseDefenseMoves(Color color, string pos);
        
         // Fourchettes
        
          std::vector <string> SearchForkPositions(Color color);
         std::vector <AMove> SearchForkAttackMoves(Color color, string pos);
         std::vector <AMove> SearchForkDefenseMoves(Color color, string pos);
        
        // clouage        
         std::vector <string> SearchPinPositions(Color color);
         std::vector <AMove> SearchPinAttackMoves(Color color, string pos);
         std::vector <AMove> SearchPinDefenseMoves(Color color, string pos);
       std::vector <AMove> SearchMoves();
           
    // Evaluation
        
    float EvaluatePassedPawns(std::vector <string> pos_list);
    float EvaluateForkPositions(std::vector <string> pos_list);
    float EvaluatePinPositions(std::vector <string> pos_list);
    float Evaluate();
      
};

#endif
