#include <thread>
#include <iostream>
#include <unistd.h>

#include "../board/AMove.hpp"
#include "../board/Piece.hpp"
#include "../board/Board.hpp"
#include "../common/Common.hpp"

#include "Engine.hpp"

using namespace std;
using namespace Common;

void Engine::SetStartPos() {
    board.SetStartPos(Color::white);
}

void Engine::SetFen(string fen) {
    board.SetFen(fen);
}

void Engine::Start(int _seconds) {
    // lance le moteur
    thread_command = 1;
    std::thread mainThread(&Engine::Run, this);
    mainThread.detach();
    if (Common::debug) cout << "started" << endl;
    
    // regarde les résultats du moteur
    for(auto runUntil = std::chrono::system_clock::now() + std::chrono::seconds(_seconds);
		std::chrono::system_clock::now() < runUntil;)	
    {
        // le moteur tourne
        // on récupere son résultat de temps en temps
        usleep(100*1000); // 0,1 seconde
         if (Common::debug) cout << "best : ";
        ShowBestVariante();
         if (Common::debug) cout << "current : ";
        ShowCurrentVariante();
    }
    
    // arrete le moteur
    Stop();
    ShowBestMove();
}

void Engine::Stop() {
    // stop process
    thread_command = 0;
    if (Common::debug) cout << "stopped" << endl;
}

void Engine::Move(AMove pMove) {
    board.Move(pMove);
}

void Engine::ShowPos() {
        board.Show();
}

void Engine::ShowBestMove() {
    if (mBestVariante.size() <= 0) {
        cout << "Error : no best move" << endl;
    } else {
        cout << mBestVariante[0].to_string() << endl;
    }
}

void Engine::ShowCurrentVariante() {
        cout << mCurrentVariante.to_string() << endl;
}

void Engine::ShowBestVariante() {
        cout << mBestVariante.to_string() << endl;
}

// Main

void Engine::Run() {
    if (Common::debug) cout << "running ..." << endl;
    SearchBestMove();
    ShowBestMove();
}

// Search

void Engine::SearchBestMove() {
    if (Common::debug) cout << "searching best move ..." << endl;
    
    // recherche des coups
    std::vector <AMove> moves;
    moves = board.SearchMoves();
    
    // vérifie pas trouvé : renvoit un coup au hasard parmi les coups possibles
    if (moves.empty()) {
        if (Common::debug) cout << "pas de meilleur coup trouvé !" << endl;
        std::vector <AMove> lPossibleMoves = board.GetPossibleMoves();
        
        // si pas de coup possible
        if (lPossibleMoves.size() == 0) {
            return;
        }
        
        AMove lRandomMove = board.GetRandomMove(lPossibleMoves);
        if (Common::debug) cout << "random move : " << lRandomMove.to_string() << endl;
        moves.push_back(lRandomMove);
    }
    
    // il y a des coups trouvés
    if (Common::debug) cout << "évaluation des " << moves.size() << " coups trouvés" << endl;
    
    float max_eval =-1000;
    float min_eval =1000;
    float best_eval;
    int best_eval_index = -1;
    float eval;
    bool best_eval_found;
    AMove best_move = moves[0];
    
    for (int i = 0; i < moves.size(); i++) {
        if (Common::debug) cout << "move evaluated n°" << i << " : " << moves[i].to_string() << endl;
        
        // on réalise le déplacement
        mCurrentVariante.push_back(moves[i]);
        board.Move(moves[i]);
        
        bool stop_search;
        stop_search = ! thread_command;

        // TODO gestion du temps et de la profondeur
        
        if (stop_search) {
            // si on n'a plus de temps, on arrete la recherche et on evalue
            eval = board.Evaluate();
        } else {
            // on continue la recherche
            SearchBestMove();
        }

        // on annul le déplacement
        board.UnMove(moves[i]);
        mCurrentVariante.pop_back();
        
        // verifie si on a trouvé un meilleur coup
        if (board.trait == Color::white) {
            best_eval_found = best_move.eval > max_eval;
        } else {
            best_eval_found = best_move.eval < min_eval;
        }
        if (best_eval_found) {
                best_eval = eval;
                best_eval_index = i;
                best_move = moves[i];
                best_move.eval = eval;
        }
    }
    
    if (Common::debug) cout << "searchBestMove finished" << endl;
}

