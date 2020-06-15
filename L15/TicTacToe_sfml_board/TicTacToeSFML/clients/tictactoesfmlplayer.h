#ifndef TICTACTOESFMLPLAYER_H
#define TICTACTOESFMLPLAYER_H

#include "tictactoeabstractplayer.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
class TicTacToeSFMLPlayer : public TicTacToeAbstractPlayer, public sf::Sprite
{
    std::map<Player, sf::IntRect> symbols_;
    sf::Texture board_texture_;
    sf::Texture field_texture_;
    Position last_move;
    std::vector<std::vector<sf::Sprite>> fields_;
    sf::Sprite board_sprite_;
    float field_size_;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    void display() override{};

public:
    TicTacToeSFMLPlayer(int pixel_dimension, int bord_size = 3);
    void update(const Board &board) override;
    Position move() { return last_move; };
    bool is_clicked(sf::Vector2i);
};

#endif // TICTACTOESFMLPLAYER_H
