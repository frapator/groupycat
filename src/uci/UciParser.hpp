#ifndef UCI_PARSER_HPP
#define UCI_PARSER_HPP

#include "../engine/Engine.hpp"

#include "Uci.hpp"

class UciParser {
     protected: 
        const int id = 1023;
        int debug = 0;
    
    private: Uci out; 
    private: Engine engine;
    
    private: int ParseLine(string str);
    
    public: void ListenUci();
};

#endif
