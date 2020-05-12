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
                std::list<Position> movements = movements_list(board);

                std::pair<Position, Score> best_score_min = {pos, {2, board}};

                for (auto const &pos : movements) {
                    auto res = max(pos, board, player);
                    if (res.second.score < best_score_min.second.score) {
                        best_score_min = res;
                        best_score_min.first = pos;
                    }
                }
                return best_score_min;
            }
            case Status::win: {
                //                std::cout << "other player won";
                //                board.debug();
                return {pos, {1, board}}; //other player won
            }
            case Status::draw:
                //                std::cout << "draw";
                //                board.debug();
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
            if (player != player_)
                throw("wrong player");
        }
        switch (current_status) {
            {
            case Status::move: {
                std::list<Position> movements = movements_list(board);

                std::pair<Position, Score> best_score = {pos, {-2, board}};
                for (auto const &pos : movements) {
                    auto res = min(pos, board, player);
                    if (res.second.score > best_score.second.score) {
                        best_score = res;
                        best_score.first = pos;
                    }
                }

                return best_score;
            }
            case Status::win: {
                return {pos, {-1, board}}; //player won
            }
            case Status::draw:

                return {pos, {0, board}};
            }
        }
    }
};

#endif // TICTACTOEBOT_H
