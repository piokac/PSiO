#include "common_defs.h"
#include "tictactoe.h"
#include "tictactoebot.h"
#include <iostream>
using namespace std;

int main()
{
    TicTacToe game(3);

    Status res;

    do {
        int row, col;
        std::cin >> row >> col;
        auto [player, status] = game.move({row, col});
        res = status;

        game.debug();

    } while (res == Status::move);

    return 0;
}
