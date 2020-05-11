#ifndef TICTACTOEABSTRACTPLAYER_H
#define TICTACTOEABSTRACTPLAYER_H
#include "common_defs.h"
#include <vector>
class TicTacToeAbstractPlayer
{
protected:
    size_t size_;
    Player player_;
    Board board_;

public:
    TicTacToeAbstractPlayer(size_t size, Player player);
    virtual void update(const Board &board) { board_ = board; }
    virtual Position move() = 0;
    virtual void display() = 0;
    virtual ~TicTacToeAbstractPlayer();
};

#endif // TICTACTOEABSTRACTPLAYER_H
