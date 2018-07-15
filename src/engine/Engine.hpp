#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "../board/AMove.hpp"
#include "../board/Variante.hpp"
#include "../board/Board.hpp"

class Engine  {
    private: 
        Board board;
        bool  thread_stop_command;
        
        Variante mCurrentVariante;
        Variante mBestVariante;
    
    public:
        int depthLimit;
        unsigned long long msLimit;
        unsigned long long nodesLimit;
        unsigned long long nodesCounter;
        
        Engine();
        void MoveCurrent(AMove pMove);
        void UnMoveCurrent();
    
    // init
    void SetStartPos();    
    void SetFen(string fen);
    void Start();

    //démarrage recherche
    void Run();
    void SearchBestMove();
    
    // arret
    void Stop();
    
    // display
    void ShowPos();
    void ShowNodesCounter();
    void ShowBestMove();
    void ShowBestVariante();
    void ShowCurrentVariante();
};

#endif
