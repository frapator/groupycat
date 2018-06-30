#include <thread>
#include <iostream>
#include <unistd.h>

#include "../board/AMove.hpp"
#include "../board/Piece.hpp"
#include "../board/Board.hpp"
#include "../board/Variante.hpp"
#include "../common/Common.hpp"

#include "Engine.hpp"

using namespace std;
using namespace Common;

Engine::Engine() {
        thread_stop_command = false;
        depthLimit = 0;
        msLimit = 0;
        nodesLimit = 0;
        nodesCounter = 0;
        //mCurrentVariante = new Variante();
        //mBestVariante = new Variante();
    }
    
void Engine::SetStartPos() {
    board.SetStartPos(Color::white);
}

void Engine::SetFen(string fen) {
    board.SetFen(fen);
}

void Engine::Start() {
    // lance le moteur
    thread_stop_command = false;
    std::thread mainThread(&Engine::Run, this);
    mainThread.detach();
    if (Common::debug) cout << "started" << endl;
    
    // regarde les résultats du moteur
    for(auto runUntil = std::chrono::system_clock::now() + std::chrono::milliseconds(msLimit);
		std::chrono::system_clock::now() < runUntil;)	
    {
        // le moteur tourne
        // on récupere son résultat de temps en temps
        usleep(50*1000); // 50 ms
        ShowBestVariante();
        ShowCurrentVariante();
        ShowNodesCounter();
        
        if (nodesCounter >= nodesLimit) break;
    }
    
    // arrete le moteur
    Stop();
    ShowBestMove();
}

void Engine::Stop() {
    // stop process
    thread_stop_command = true;
    if (Common::debug) cout << "stopped" << endl;
}

void Engine::Move(AMove pMove) {
    board.Move(pMove);
}

void Engine::ShowPos() {
        board.Show();
}

void Engine::ShowBestMove() {
    if (mBestVariante.size() == 0) {
        cout << "Error : no best move" << endl;
    } else {
        cout << mBestVariante[0].to_string() << endl;
    }
}

void Engine::ShowNodesCounter() {
    cout << "nodes:" << nodesCounter << " (max " << nodesLimit << ")" << endl;
}

void Engine::ShowCurrentVariante() {
        cout << "current : ";
        cout << mCurrentVariante.to_string() << endl;
}

void Engine::ShowBestVariante() {
        cout << "best: " << mBestVariante.to_string() << endl;
}

// Main

void Engine::Run() {
    if (Common::debug) cout << "running ..." << endl;
    SearchBestMove();
    ShowBestVariante();
    ShowBestMove();
}

// Search

void Engine::SearchBestMove() {
    nodesCounter ++;
    if (Common::debug) cout << "searching best move node " << nodesCounter << endl;
    
    // recherche des coups
    std::vector <AMove> moves;
    moves = board.SearchMoves();
    
    // Si pas de coup trouvé, en prend un au hasard
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
        board.Move(moves[i]);
        mCurrentVariante.push_back(moves[i]);
        if (Common::debug) { ShowCurrentVariante(); }
        
        // gestion des conditions d'arret
        if (thread_stop_command) {
            // si on n'a plus de temps, on arrete la recherche et on evalue
            eval = board.Evaluate();
            return;
            
        } else {
            // on continue la recherche
            SearchBestMove();
        }

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
        
        // on annul le déplacement
        board.UnMove(moves[i]);
        mCurrentVariante.pop_back();
    }
    
    if (Common::debug) cout << "searchBestMove finished" << endl;
}
