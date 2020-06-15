#ifndef TICTACTOECONSOLE_H
#define TICTACTOECONSOLE_H
#include "common_defs.h"
#include "tictactoeabstractplayer.h"
#include <iostream>
class TicTacToeConsole : public TicTacToeAbstractPlayer
{
    char convert(Player p)
    {
        if (p == Player::cross)
            return 'x';
        if (p == Player::circle)
            return 'o';

        return '.';
    }

public:
    TicTacToeConsole(size_t size, Player player) : TicTacToeAbstractPlayer(size, player) {}
    virtual Position move()
    {
        int row, col;
        std::cin >> row >> col;
        return {row, col};
    }
    virtual void display()
    {
        for (const auto &row : board_) {
            for (const auto &el : row) {
                std::cout << convert(el);
            }
            std::cout << std::endl;
        }
    }
};

#endif // TICTACTOECONSOLE_H
