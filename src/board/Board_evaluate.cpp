#include "Board.hpp"
#include "../common/Common.hpp"

using namespace std;
using namespace Common;

// Evaluation
    
float Board::EvaluatePassedPawns(std::vector <Position> pos_list)  {
    if (pos_list.empty()) return 0;
    
    return pos_list.size();
}

float Board::EvaluateForkPositions(std::vector <Position> pos_list)  {
    if (pos_list.empty()) return 0;
    return pos_list.size();
}

float Board::EvaluatePinPositions(std::vector <Position> pos_list)  {
    if (pos_list.empty()) return 0;
    return pos_list.size();
}

float Board::Evaluate() {
    float eval = 0; 
    Color lNextColor = nextColor();
    
    std::vector <Position> positions; // les positions clefs pour la recherche de coups
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

