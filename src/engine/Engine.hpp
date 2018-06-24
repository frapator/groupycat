#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "../board/AMove.hpp"
#include "../board/Variante.hpp"
#include "../board/Board.hpp"

class Engine  {
    private: 
        Board board;
        bool  thread_stop_command;
        int depthLimit;
        Variante mCurrentVariante;
        Variante mBestVariante;
    
    public:
        Engine();
        void Move(AMove pMove);    
    
    // init
    void SetStartPos();    
    void SetFen(string fen);
    void Start(int _seconds);

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
