#include "tictactoe.h"
#include "tictactoebot.h"
#include <iostream>
#include <memory>
#include <tictactoesfmlplayer.h>
#include <tictactoetcpproxy.h>
using namespace std;
class Controller
{
    sf::RenderWindow window_;
    TicTacToeSFMLPlayer player_;
    Player player_type_;
    //    TicTacToeBot bot_;
    std::unique_ptr<TicTacToeAbstract> game_engine_;
    sf::Texture game_over_texture;
    sf::Sprite game_over_sprite;

public:
    Controller(Player player_type, int width = 800, int height = 600)
        : window_(sf::VideoMode(width, height), "TicTacToe Client"), player_(height, 3),
          player_type_(player_type), game_engine_(new TicTacToeTcpProxy(3, "127.0.0.1", 2000))
    {
        if (!game_over_texture.loadFromFile("../tex/game_over.png")) {
            std::cerr << "Could not load texture" << std::endl;
            throw("Could not load texture");
        }
        game_over_sprite.setTexture(game_over_texture);
    }

    void loop()
    {
        Status state = Status::move;
        while (window_.isOpen()) {
            // check all the window's events that were triggered since the last iteration of the loop
            sf::Event event;
            while (window_.pollEvent(event)) {
                // "close requested" event: we close the window
                if (event.type == sf::Event::Closed)
                    window_.close();
                if (event.type == sf::Event::KeyReleased) {
                    if (event.key.code == sf::Keyboard::Space) {
                        std::cout << "Space released" << std::endl;
                    }
                }

                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2i mouse_pos = sf::Mouse::getPosition(window_);
                        std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y
                                  << std::endl;
                        Status status = game_engine_->is_finished();
                        switch (status) {
                        case Status::move: {
                            if (player_.is_clicked(mouse_pos)) {
                                //react to click
                                auto [player, status] = game_engine_->move(player_.move(),
                                                                           player_type_);
                                player_.update(game_engine_->state());
                                if (status != Status::move) {
                                    cout << "game over ";
                                    cout.flush();
                                }
                                //                                if (player == bot_.player()) {
                                //                                    bot_.update(game_engine_->state());
                                //                                    game_engine_->move(bot_.move());
                                //                                    player_.update(game_engine_->state());
                                //                                }
                            }
                            break;
                        }
                        default: {
                            game_engine_ = std::make_unique<TicTacToe>(3);
                            player_.update(game_engine_->state());
                        }
                        }
                    }
                }
            }
            window_.clear(sf::Color::Black);
            player_.update(game_engine_->state());
            Status status = game_engine_->is_finished();
            switch (status) {
            case Status::move:
                window_.draw(player_);
                break;
            case Status::win:
                window_.draw(game_over_sprite);
                break;

            case Status::draw:
                window_.draw(game_over_sprite);
                break;

            } // end the current frame

            window_.display();
            sf::sleep(sf::milliseconds(1));
        }
    };
};

int main()
{
    // create the window
    Controller ctrl(Player::cross);
    ctrl.loop();
    return 0;
}
