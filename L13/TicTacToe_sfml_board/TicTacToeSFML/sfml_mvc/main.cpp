#include "../../../L10/TicTacToeGame/tictactoe.h"
#include "../../../L10/TicTacToeGame/tictactoebot.h"
#include <iostream>
#include <tictactoesfmlplayer.h>
using namespace std;
class Controller
{
    sf::RenderWindow window_;
    TicTacToeSFMLPlayer player_;
    TicTacToeBot bot_;
    TicTacToe game_engine_;
    sf::Texture game_over_texture;
    sf::Sprite game_over_sprite;

public:
    Controller(int width = 800, int height = 600)
        : window_(sf::VideoMode(width, height), "TicTacToe Client"), player_(height, 3),
          game_engine_(3), bot_(3, Player::circle)
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
                        Status status = game_engine_.is_finished();
                        switch (status) {
                        case Status::move: {
                            if (player_.is_clicked(mouse_pos)) {
                                //react to click
                                auto [player, status] = game_engine_.move(player_.move());
                                player_.update(game_engine_.state());
                                if (status != Status::move) {
                                    cout << "game over ";
                                    cout.flush();
                                }
                                if (player == bot_.player()) {
                                    bot_.update(game_engine_.state());
                                    game_engine_.move(bot_.move());
                                    player_.update(game_engine_.state());
                                }
                            }
                            break;
                        }
                        default: {
                            game_engine_ = TicTacToe(3);
                            player_.update(game_engine_.state());
                        }
                        }
                    }
                }
            }
            window_.clear(sf::Color::Black);
            Status status = game_engine_.is_finished();
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
    Controller ctrl;
    ctrl.loop();
    return 0;
}
