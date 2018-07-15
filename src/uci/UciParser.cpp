#include <iostream>
#include <boost/algorithm/string.hpp>

#include "UciParser.hpp"
#include "Uci.hpp"

using namespace std;

void UciParser::ListenUci() {
    string str;
    int errorCode;
    cin.clear();
    while (true) {
        getline(cin, str);
        errorCode = ParseLine(str);
    }
}    

int UciParser::ParseLine(string str) {
    if (debug > 0) std::cout << "starting parseline ..." << std::endl;
    
    std::vector<std::string> results;
    boost::split(results, str, [](char c){return c == ' ';});
    
    // vérification de la présence de parametres
    if (results.size() == 0) return 1;
    
    // la commande
    string lCommand = results[0];
    
    // le premier parametre
    string lMainParam = results.size() > 1 ? results[1] : "";
    
    // l'interpretation
    if (lCommand== "id") {
            out.Id();
    }
    
    if (lCommand== "debug") {
        if (lMainParam == "on") {
            debug = 1;
            std::cout << "debug on" << std::endl;
        }
        if (lMainParam == "off") {
            debug = 0;
        }
    }
    
    if (lCommand== "uci") {
        out.Id();
        out.OptionsList();
        out.UciOk();
    }
    
    if (lCommand== "isready") {
        out.ReadyOk();
    }
    
    if (lCommand== "setoption") {
            // later
    }
    
    if (lCommand== "register") {
            // later
    }
    
    if (lCommand== "ucinewgame") {
        engine.Stop();
    }
    
    if (lCommand == "position") { //  position [fen <fenstring> | startpos ]  moves <move1> .... <movei>
        
        int movesParamIndex = 2;
        if (lMainParam == "startpos") {
            engine.SetStartPos();
        } else if (lMainParam == "fen") {
            if (results.size() <= 2) return 1; // fen non fourni
            string fenstring = results[2];
            engine.SetFen(fenstring);
            movesParamIndex ++;
        }
        
        if (results.size() <= movesParamIndex) {
            // commande position terminée sans moves derriere
            return 1;
        }
        
        if (results[movesParamIndex] == "moves") {
            // lecture des moves
            if (Common::debug) cout << "moves parsing ..." << endl;
            movesParamIndex ++;
            while (movesParamIndex < results.size()) {
                string s = results[movesParamIndex];
                AMove move = AMove(s);
                if (Common::debug) cout << "move found " << move.to_string() << endl;
                movesParamIndex ++;
                engine.MoveCurrent(move);
            }
        } else {
            // parametre inconnu
        }
        
        if (debug) engine.ShowPos();
    }
    
    if (lCommand== "go") {
        int lParamIndex = 1;
        while (lParamIndex + 1 < results.size()) {
            string lParam = results[lParamIndex];
            if (results.size() < 2) {
                cout << "erreur : missing go value for parameter  " << lParam << endl;
                return 1;
            }
            string lValue = results[lParamIndex+1];
            
            if (lParam == "ponder") {
            }
            if (lParam == "searchmoves") {
            }
            if (lParam == "wtime") {
                if (results.size() < 2) return 1;
            }
            if (lParam == "btime") {
                
            }
            if (lParam == "winc") {
                
            }
            if (lParam == "binc") {
                
            }
            if (lParam == "movestogo") {
            }
            if (lParam == "infinite") {
            }
            if (lParam == "mate") {
            }
            if (lParam == "depth") {
                engine.depthLimit = stoi(lValue);
            }
            if (lParam == "nodes") {
                engine.nodesLimit = stoi(lValue);
            }
            if (lParam == "movetime") {
                engine.msLimit = stoi(results[1]);
            }
            lParamIndex += 2;
        }
        engine.Start();
    }
    
    if (lCommand== "stop") {
        engine.Stop();
    }
    
    if (lCommand== "ponderhit") {
        // TODO
    }
    
    if (lCommand == "quit") {
        engine.Stop();
    }
    
    // ==============
    // non UCI
    // ==============
    
    if (lCommand== "showpos") engine.ShowPos();
    if (lCommand == "1") {
        ParseLine("position startpos");
        ParseLine("showpos");
    }
    if (lCommand == "2") {
        ParseLine("position startpos moves e2e4 e7e5 d2d4 e5d4 c2c4");
        ParseLine("showpos");
    }   
    
    return 0;
}

