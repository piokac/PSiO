#include "tictactoesfmlplayer.h"
#include <iostream>
void TicTacToeSFMLPlayer::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(board_sprite_, states);
    int columns = fields_.size();
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < columns; j++) {
            target.draw(fields_[i][j], states);
        }
    }
}

void TicTacToeSFMLPlayer::update(const Board &board)
{
    int columns = fields_.size();
    TicTacToeAbstractPlayer::update(board);
    for (int i = 0; i < columns; i++) {
        for (int j = 0; j < columns; j++) {
            fields_[i][j].setTextureRect(symbols_[board_[i][j]]);
        }
    }
}

bool TicTacToeSFMLPlayer::is_clicked(sf::Vector2i pos)
{
    sf::FloatRect rect = getGlobalBounds();
    int x_range = pos.x - rect.left;
    int y_range = pos.y - rect.top;
    if (x_range > 0 && x_range < rect.width && y_range > 0 && y_range < rect.height) {
        last_move = Position(x_range / field_size_, y_range / field_size_);
        ///
        //        static int symbol_id = 0;
        //        fields_[last_move.first][last_move.second].setTextureRect(
        //            symbols_[(symbol_id % 2) ? Player::cross : Player::circle]);
        //        symbol_id++;
        return true;
    }
}

TicTacToeSFMLPlayer::TicTacToeSFMLPlayer(int pixel_dimension, int size)
    : TicTacToeAbstractPlayer(size, Player::cross), field_size_(pixel_dimension / 3)
{
    this->setTextureRect(sf::IntRect(0, 0, pixel_dimension, pixel_dimension));
    if (!board_texture_.loadFromFile("../tex/board.png")) {
        std::cerr << "Could not load texture" << std::endl;
        throw("Could not load texture");
    }
    board_texture_.setSmooth(true);
    sf::Vector2u tex_size = board_texture_.getSize();
    board_sprite_.setScale(static_cast<float>(pixel_dimension) / tex_size.x,
                           static_cast<float>(pixel_dimension) / tex_size.x);
    board_sprite_.setTexture(board_texture_);
    board_sprite_.setTextureRect(sf::IntRect(0, 0, tex_size.x, tex_size.y));

    if (!field_texture_.loadFromFile("../tex/symbols.png")) {
        std::cerr << "Could not load texture" << std::endl;

        throw("Could not load texture");
    }
    symbols_[Player::null] = sf::IntRect(0, 0, 40, 48);
    symbols_[Player::cross] = sf::IntRect(55, 0, 40, 48);
    symbols_[Player::circle] = sf::IntRect(110, 0, 40, 48);
    sf::Vector2u tex_size_g = field_texture_.getSize();
    fields_ = std::vector<std::vector<sf::Sprite>>(
        size,
        std::vector<sf::Sprite>(pixel_dimension,
                                sf::Sprite(field_texture_, symbols_[Player::null])));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            fields_[i][j].setPosition(i * field_size_, j * field_size_);
            fields_[i][j].setScale(field_size_ / 48, field_size_ / 48);
        }
    }
}
