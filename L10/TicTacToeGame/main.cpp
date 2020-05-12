#include <iostream>
#include <tictactoe.h>
#include <tictactoebot.h>
using namespace std;

int main()
{
    TicTacToe game(3);
    TicTacToeBot bot(3, Player::circle);
    Status res;

    do {
        int row, col;
        std::cin >> row >> col;
        auto [player, status] = game.move({row, col});
        res = status;

        game.debug();
        bot.update(game.state());
        auto [player2, status2] = game.move(bot.move());
        game.debug();
        if (status2 != Status::move) {
            res = status2;
        }
    } while (res == Status::move);

    return 0;
}
