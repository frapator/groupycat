#include <vector>

#include "Position.hpp"

std::string Position::toString() {
        char coords [2];
        coords[0] = 'a' + x;
        coords[1] = '0' + y;
        return std::string(coords);
    }
    
std::vector <Position> Position::GetKDestinations() {
    std::vector <Position> pos_list;
    
    if (x+2 < 8 && y + 1 < 8) pos_list.push_back(Position(x+2, y+1));
    if (x+2 < 8 && y - 1 >= 0) pos_list.push_back(Position(x+2, y-1));
    if (x+1 < 8 && y + 2 < 8) pos_list.push_back(Position(x+1, y+2));
    if (x+1 < 8 && y - 2 >= 0) pos_list.push_back(Position(x+1, y-2));
    if (x-1 >= 0 && y + 2 < 8) pos_list.push_back(Position(x-1, y+2));
    if (x-1 >= 0 && y - 2 >= 0) pos_list.push_back(Position(x-1, y-2));
    if (x-2 >= 0 && y + 1 < 8) pos_list.push_back(Position(x-2, y+1));
    if (x-2 >= 0 && y - 1 >= 0) pos_list.push_back(Position(x-2, y-1));
    
    return pos_list;
};
