#include <iostream>

#include "AMove.hpp"

class Variante : public std::vector<AMove> {
 
private:
    
public:
    std::string to_string();
};
