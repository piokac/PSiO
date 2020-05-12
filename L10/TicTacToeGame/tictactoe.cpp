#include "tictactoe.h"

TicTacToe::TicTacToe(size_t size)
    : size_(size), board_(size, std::vector<Player>(size, Player::null)),
      active_player_(Player::cross)
{}

TicTacToe::TicTacToe(const Board &board, Player player)
    : size_(board.size()), board_(board), active_player_(player)
{}

std::pair<Player, Status> TicTacToe::move(const Position &pos, Player player)
{
    auto [row, col] = pos;
    if (player == Player::null) {
        player = active_player_;
        if (active_player_ == Player::null)
            active_player_ = Player::cross;
    } else {
        if (player != active_player_) {
            return {active_player_, is_finished()}; //wrong player
        }
    }
    if (check_move(row, col, player)) {
        board_[row][col] = player;
        if (active_player_ == Player::cross) //change player
            active_player_ = Player::circle;
        else
            active_player_ = Player::cross;
    }
    return {active_player_, is_finished()};
}

bool TicTacToe::check_move(size_t row, size_t col, Player player) const
{
    return board_[row][col] == Player::null;
}

Status TicTacToe::is_finished() const
{
    bool is_full = true;
    bool sequence_diag_lr = board_[0][0] != Player::null,
         sequence_diag_rl = board_[0][size_ - 1] != Player::null;

    for (size_t dim = 0; dim < size_; dim++) {
        Player val = board_[dim][0];
        if (val != Player::null) {
            if (std::all_of(board_[dim].begin() + 1, board_[dim].end(), [val](const Player &field) {
                    return field == val;
                }))
                return Status::win;
        }
        val = board_[0][dim];

        if (val != Player::null) {
            if (std::all_of(board_.begin() + 1,
                            board_.end(),
                            [val, dim](const std::vector<Player> &row) { return row[dim] == val; }))
                return Status::win;
        }
        if (is_full) {
            is_full = !std::any_of(board_[dim].begin(), board_[dim].end(), [](const Player &field) {
                return field == Player::null;
            });
        }
        if (sequence_diag_lr) {
            if (board_[dim][dim] != board_[0][0]) {
                sequence_diag_lr &= false;
            }
        }
        if (sequence_diag_rl) {
            if (board_[dim][size_ - 1 - dim] != board_[0][size_ - 1]) {
                sequence_diag_rl &= false;
            }
        }
    }
    if (sequence_diag_rl || sequence_diag_lr)
        return Status::win;

    if (is_full)
        return Status::draw;
    return Status::move;
}

char TicTacToe::convert(Player p)
{
    if (p == Player::cross)
        return 'x';
    if (p == Player::circle)
        return 'o';

    return '.';
}

void TicTacToe::debug() const
{
    for (const auto &row : board_) {
        for (const auto &el : row) {
            std::cout << convert(el);
        }
        std::cout << std::endl;
    }
}
