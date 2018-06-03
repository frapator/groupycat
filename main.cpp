#include "src/uci/UciParser.hpp"
#include "src/board/AMove.hpp"
#include "src/common/Common.hpp"

int main(int argc, char **argv) {
    
    Common::debug = 0;
    
    UciParser uci_parser;
    
    uci_parser.ListenUci();
    
     return 0;
}
