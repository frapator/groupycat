#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "../board/Variante.hpp"
#include "../board/AMove.hpp"
#include "../board/Board.hpp"

class Engine  {
    private: 
        Board board;
        int thread_command;
        Variante mCurrentVariante;
        Variante mBestVariante;
    
    public:
        void Move(AMove pMove);    
    
    // init
    void SetStartPos();    
    void SetFen(string fen);
    void Start(int _seconds);

    //démarrage recherche
    void Run();
    AMove SearchBestMove();
    
    // arret
    void Stop();
    
    // display
    void ShowPos();
    void ShowBestMove();
    void ShowBestVariante();
    void ShowCurrentVariante();
};

#endif
