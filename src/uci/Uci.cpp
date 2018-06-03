#include <iostream>
#include <string>

#include "Uci.hpp" 

using namespace std;

//private: enum class Commands { id = 1 };

void Uci::Id()  {
        static string name = "id name Groupycat 0.1";
        static string author = "id author Mathieu Pigois";
        cout << name << endl;
        cout << author << endl;
}

void Uci::OptionsList() {
        cout << "option name Style type combo default Normal var Solid var Normal var Risky" << endl;
}

void Uci::UciOk() {
    cout << "uciok" << endl;
}

void Uci::ReadyOk() {
    cout << "readyok" << endl;
}

void Uci::BestMove() {
    
}

void Uci::CopyProtection() {
    
}

void Uci::Registration() {
    
}
void Uci::Info() {
    
}
