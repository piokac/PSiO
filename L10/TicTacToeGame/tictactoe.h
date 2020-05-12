#ifndef TICTACTOE_H
#define TICTACTOE_H
#include "common_defs.h"
#include <algorithm>
#include <iostream>
#include <vector>
class TicTacToe
{
protected:
    size_t size_;
    Board board_;
    Player active_player_;

public:
    TicTacToe(size_t size);
    TicTacToe(const Board &board, Player player = Player::null);
    ///
    /// \brief move performs player movement
    /// \param pos std::pair representing row and columns of the gameboard <0;size_)
    /// \param player id of the player performing move
    /// \return std::pair consisted of: the active player id (if the move was correct the id of the next player, if not the active player is not changed). The Status represents the game state Status:move - move is possible, or Status:win or Status::drawn
    std::pair<Player, Status> move(const Position &pos, Player player = Player::null);
    ///
    /// \brief active_player geter for active player
    /// \return player id Player::cross or Player::circle
    ///
    Player active_player() const { return active_player_; }
    ///
    /// \brief field geter for particular field of the game board
    /// \param row
    /// \param col
    /// \return field state Player::null field is empty, Player::cross, Player::circle - represent the player id
    ///
    const Player &field(const size_t &row, const size_t &col) const { return board_[row][col]; }

    ///
    /// \brief state geter for board
    /// \return 2d std::vector representing board
    ///
    const std::vector<std::vector<Player>> &state() const { return board_; }

    ///
    /// \brief convert converts Player enum to char symbol
    /// \param p player enum (corss circle or empty)
    /// \return character symbol of the player
    ///
    static char convert(Player p);
    ///
    /// \brief debug prints board to std out
    ///
    void debug() const;

protected:
    ///
    /// \brief check_move verifies whether the move is possible
    /// \param row row of the board <0..size_)
    /// \param col column of the board <0..size_)
    /// \param player player id
    /// \return true - if move is correct, otherwise false
    ///
    bool check_move(size_t row, size_t col, Player player) const;
    ///
    /// \brief is_finished virifies whether the game was finished (win or drawn)
    /// \return Status::win if active layer won, Status::drawn if drawn occured, Status::move if the game can be continued
    ///
    Status is_finished() const;
};

#endif // TICTACTOE_H
