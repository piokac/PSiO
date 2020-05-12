#include "tictactoebot.h"

Position TicTacToeBot::move()
{
    TicTacToe current_state(board_, player_);
    auto [pos, score] = max({-1, -1}, current_state, player_);
    std::cout << "best move: " << pos.first << ", " << pos.second << "score: " << score.score
              << std::endl;
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
