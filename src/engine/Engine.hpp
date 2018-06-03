#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "../board/Board.hpp"

class Engine  {
    private: Board board;
    private: int thread_command;
    
    public: void SetStartPos();    
    public: void SetFen(string fen);
    public: void Start();
    
    public: void Stop();
    public:void Move(AMove pMove);    
    public: void ShowPos();
    public: void Run();
    public: AMove SearchBestMove();

};

#endif
