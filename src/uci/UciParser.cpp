#include <iostream>
#include <boost/algorithm/string.hpp>

#include "UciParser.hpp"
#include "Uci.hpp"

using namespace std;

void UciParser::ListenUci() {
    string str;
    int quitFlag = 0;
    cin.clear();
    while (! quitFlag) {
        getline(cin, str);
        quitFlag = ParseLine(str);
    }
}    

int UciParser::ParseLine(string str) {
    if (debug > 0) std::cout << "starting parseline ..." << std::endl;
    
    int result = 0;
    
    if (str== "id") {
            out.Id();
    }
    
    if (str== "debug on") {
        debug = 1;
        std::cout << "debug on" << std::endl;
    }
    if (str== "debug off") {
        debug = 0;
    }
    
    if (str== "uci") {
        out.Id();
        out.OptionsList();
        out.UciOk();
    }
    
    if (str== "isready") {
        out.ReadyOk();
    }
    
    if (str== "setoption") {
            // later
    }
    
    if (str== "register") {
            // later
    }
    
    if (str== "ucinewgame") {
        engine.Stop();
    }
    
    std::vector<std::string> results;
    boost::split(results, str, [](char c){return c == ' ';});
    string param1 = results[0];
        
    if (param1 == "position") { //  position [fen <fenstring> | startpos ]  moves <move1> .... <movei>
        
        string param2 = results[1];
        int movesParamIndex = 2;
        if (param2 == "startpos") {
            engine.SetStartPos();
            
        } else if (param2 == "fen") {
            string fenstring = results[2];
            engine.SetFen(fenstring);
            movesParamIndex ++;
        }
        if (results.size()>= movesParamIndex) {
            return result;
        }
        if (results[movesParamIndex] == "moves") {
            // lecture des moves
            movesParamIndex ++;
            while (movesParamIndex < results.size()) {
                string s = results[movesParamIndex];
                AMove move = AMove(s);
                movesParamIndex ++;
                engine.Move(move);
            }
        }
        
        if (debug) engine.ShowPos();
    }
    
    if (str== "go") {
        boost::split(results, str, [](char c){return c == ' ';});
        // TODO param de go
        int seconds = 2;
        engine.Start(seconds);
    }
    
    if (str== "stop") {
        engine.Stop();
    }
    
    if (str== "ponderhit") {
        // TODO
    }
    
    if (str == "quit") {
        engine.Stop();
        result = 1;
    }
    
    // ==============
    // non UCI
    // ==============
    
    if (str== "showpos") engine.ShowPos();
    if (str == "1") {
        ParseLine("position startpos");
        std::cout << "parsed" << std::endl;
        ParseLine("showpos");
    }
    if (str == "2") {
        ParseLine("position startpos moves e2e4 e7e5 d2d4 e5d4 c2c4");
        ParseLine("showpos");
    }    
    return result;
}

