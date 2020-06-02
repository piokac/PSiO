#ifndef TICTACTOEBOT_H
#define TICTACTOEBOT_H

#include "common_defs.h"
#include "tictactoe.h"
#include "tictactoeabstractplayer.h"
#include <list>

class TicTacToeBot : public TicTacToeAbstractPlayer
{
    struct Score
    {
        int score;
        TicTacToe game_result;
    };

public:
    TicTacToeBot(size_t size, Player player) : TicTacToeAbstractPlayer(size, player) {}
    Position move();
    void display();

private:
    std::list<Position> movements_list(const TicTacToe &board);
    std::pair<Position, Score> min(const Position &pos, TicTacToe board, Player player);
    std::pair<Position, Score> max(const Position &pos, TicTacToe board, Player player);
};

#endif // TICTACTOEBOT_H
