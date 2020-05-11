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
    std::pair<Position, Score> min(const Position &pos, TicTacToe board, Player player)
    {
        Status current_status = Status::move;
        if (pos.first < size_ && pos.second < size_) {
            auto res = board.move(pos, player); //other player move
            current_status = res.second;
            player = res.first;
        }
        switch (current_status) {
            {
            case Status::move: {
                //TODO: to implement
            }
            case Status::win: {
                return {pos, {1, board}}; //other player won
            }
            case Status::draw:

                return {pos, {0, board}};
            }
        }
    }
    std::pair<Position, Score> max(const Position &pos, TicTacToe board, Player player)
    {
        Status current_status = Status::move;
        if (pos.first < size_ && pos.second < size_) {
            auto res = board.move(pos, player); //other player move

            current_status = res.second;
            player = res.first;
        }
        switch (current_status) {
            {
            case Status::move: {
                //TODO:
            }
            case Status::win: {
                return {pos, {-1, board}};
            }
            case Status::draw:

                return {pos, {0, board}};
            }
        }
    }
};

#endif // TICTACTOEBOT_H
