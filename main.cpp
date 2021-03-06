#include "src/uci/UciParser.hpp"
#include "src/board/AMove.hpp"
#include "src/common/Common.hpp"

int main(int argc, char **argv) {
   
    Common::debug = argc > 1 ? stoi(argv[1]) : 0;
    if (debug) std::cout << "debug on" << std::endl;
    
    UciParser uci_parser;
    
    uci_parser.ListenUci();
    
    return 0;
}
