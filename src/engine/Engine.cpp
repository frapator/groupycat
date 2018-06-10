#include <thread>
#include <iostream>
#include <unistd.h>

#include "../board/AMove.hpp"
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
    // start process
    thread_command = 1;
    std::thread mainThread(&Engine::Run, this);
    mainThread.detach();
    cout << "started" << endl;
    
    for(auto runUntil = std::chrono::system_clock::now() + std::chrono::seconds(2);
		std::chrono::system_clock::now() < runUntil;)	
    {
        // le moteur tourne
        // on récupere son résultat de temps en temps
        usleep(1000*1000); // 1 seconde
        cout << "best : ";
        ShowBestVariante();
        cout << "current : ";
        ShowCurrentVariante();
    }
    ShowBestMove();
}

void Engine::Stop() {
    // stop process
    thread_command = 0;
    cout << "stopped" << endl;
}

void Engine::Move(AMove pMove) {
    board.Move(pMove);
}

void Engine::ShowPos() {
        board.Show();
}

void Engine::ShowBestMove() {
    if (mBestVariante.size() <= 0) {
        cout << "no best move" << endl;
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
    SearchBestMove();
}

// Search

AMove Engine::SearchBestMove() {
    if (Common::debug) cout << "running" << endl;
    
    std::vector <AMove> moves;
    moves = board.SearchMoves();
    
    // vérifie si un coup a été trouvé !
    if (moves.empty()) {
        if (Common::debug) cout << "pas de coup trouvé !" << endl;
        AMove lMove = board.GetRandomMove();
        cout << lMove.to_string() << endl;
        return lMove;
    }
    
    if (Common::debug) cout << "evaluation des " << moves.size() << " coups trouvés" << endl;
    
    float max_eval =-1000;
    float min_eval =1000;
    float best_eval;
    int best_eval_index = -1;
    float eval;
    bool best_eval_found;
    AMove best_move = moves[0];
    
    for (int i = 0; i < moves.size(); i++) {
        if (Common::debug) cout << "move evaluated " << i << moves[i].to_string() << endl;
        
        mCurrentVariante.push_back(moves[i]);
        board.Move(moves[i]);
        
        bool stop_search;
        stop_search = ! thread_command;
        // TODO gestion du temps et de la profondeur
        
        if (stop_search) {
            eval = board.Evaluate();
        } else {
            AMove next_move = SearchBestMove();
        }

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
    
    if (Common::debug) cout << "finished" << endl;
    
    return best_move;
}

