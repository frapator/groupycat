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
            return 0;
    }
    
    if (lCommand== "debug") {
        if (lMainParam == "on") {
            debug = 1;
            std::cout << "debug on" << std::endl;
        }
        if (lMainParam == "off") {
            debug = 0;
        }
        return 0;
    }
    
    if (lCommand== "uci") {
        out.Id();
        out.OptionsList();
        out.UciOk();
        return 0;
    }
    
    if (lCommand== "isready") {
        out.ReadyOk();
        return 0;
    }
    
    if (lCommand== "setoption") {
            // later
        return 0;
    }
    
    if (lCommand== "register") {
            // later
        return 0;
    }
    
    if (lCommand== "ucinewgame") {
        engine.Stop();
        return 0;
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
        } else {
            return 1; // position non reconnue
        }
        
        if (results.size() <= movesParamIndex) {
            // commande position terminée sans moves derriere
            return 0;
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
                engine.Move(move);
            }
        } else {
            // parametre inconnu
            return 1;
        }
        
        if (debug) engine.ShowPos();
        return 0; // fin commande position
    }
    
    if (lCommand== "go") {
        int lParamIndex = 1;
        while (lParamIndex + 1 < results.size()) {
            string lParam = results[lParamIndex];
            string lValue = results[lParamIndex+1],
            if (lParam == "wtime") {
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
            }
            if (lParam == "nodes") {
            }
            if (lParam == "movetime") {
                if (results.size() < 2) return 1;
                int seconds = stoi(results[1]);
                engine.Start(seconds);
            }
            
            lParamIndex += 2;
        }
        return 0;
    }
    
    if (lCommand== "stop") {
        engine.Stop();
        return 0;
    }
    
    if (lCommand== "ponderhit") {
        // TODO
        return 0;
    }
    
    if (lCommand == "quit") {
        engine.Stop();
        return 0;
    }
    
    // ==============
    // non UCI
    // ==============
    
    if (lCommand== "showpos") engine.ShowPos();
    if (lCommand == "1") {
        ParseLine("position startpos");
        ParseLine("showpos");
        return 0;
    }
    if (lCommand == "2") {
        ParseLine("position startpos moves e2e4 e7e5 d2d4 e5d4 c2c4");
        ParseLine("showpos");
        return 0;
    }    
    return 1; // commande non reconnue
}

