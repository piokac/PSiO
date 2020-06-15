#include "tictactoebot.h"

Position TicTacToeBot::move()
{
    TicTacToe current_state(board_, player_);
    auto [pos, score] = max({-1, -1}, current_state, player_);
    //    std::cout << "best move: " << pos.first << ", " << pos.second << "score: " << score.score
    //              << std::endl;
    //    score.game_result.debug();
    return pos;
}

void TicTacToeBot::display()
{
    for (const auto &row : board_) {
        for (const auto &el : row) {
            std::cout << TicTacToe::convert(el);
        }
        std::cout << std::endl;
    }
}

std::list<Position> TicTacToeBot::movements_list(const TicTacToe &board)
{
    std::list<Position> movements;
    for (size_t i = 0; i < size_; i++) {
        for (size_t j = 0; j < size_; j++)
            if (board.state()[i][j] == Player::null) {
                movements.emplace_back(i, j);
            }
    }
    return movements;
}

std::pair<Position, TicTacToeBot::Score> TicTacToeBot::min(const Position &pos,
                                                           TicTacToe board,
                                                           Player player)
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

std::pair<Position, TicTacToeBot::Score> TicTacToeBot::max(const Position &pos,
                                                           TicTacToe board,
                                                           Player player)
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
