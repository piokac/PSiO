#include "common_defs.h"
#include "tictactoe.h"
#include "tictactoebot.h"
#include <iostream>
using namespace std;
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
class Game
{
    TicTacToeAbstractPlayer *players_[2];
    TicTacToe game_;

public:
    Game() : game_(3)
    {
        players_[0] = new TicTacToeConsole(3, Player::cross);
        players_[1]
            = new TicTacToeConsole(3, Player::circle); /*new TicTacToeConsole(3, Player::circle);*/
    }
    Game(size_t size, TicTacToeAbstractPlayer *p1, TicTacToeAbstractPlayer *p2) : game_(size)
    {
        players_[0] = p1;
        players_[1] = p2;
    }
    void loop()
    {
        Status res;
        do {
            //        int row, col;
            //        std::cin >> row >> col;
            for (int i = 0; i < 2; i++) {
                players_[i]->update(game_.state());
                auto [player, status] = game_.move(players_[i]->move(), players_[i]->player());
                players_[i]->update(game_.state());
                players_[i]->display();
                res = status;
                if (res != Status::move)
                    break;
            }

        } while (res == Status::move);
    }
};

int main()
{
    Game game(3, new TicTacToeConsole(3, Player::cross), new TicTacToeBot(3, Player::circle));
    game.loop();

    return 0;
}
