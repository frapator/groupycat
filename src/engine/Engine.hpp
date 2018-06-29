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
    
        bool ItsTimeToStopCompute();
        
    public:
        int depthLimit;
        int msLimit;
        int nodesLimit;
        int nodesCounter;
        
        Engine();
        void Move(AMove pMove);    
    
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
    void ShowBestMove();
    void ShowBestVariante();
    void ShowCurrentVariante();
};

#endif
