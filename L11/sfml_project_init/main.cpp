#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <memory>
#include <vector>
class Scena
{
    std::vector<sf::Sprite> obiekty_;
    std::vector<std::unique_ptr<sf::Texture>> textury_;
    sf::RenderWindow window_;

public:
    Scena(int W, int H) : window_(sf::VideoMode(W, H), "SFML app")
    {
        sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

        // create some shapes
        std::unique_ptr<sf::Texture> texture = std::make_unique<sf::Texture>();
        if (!texture->loadFromFile("../tex/grass.png")) {
            std::cerr << "Could not load texture" << std::endl;
            throw("Could not load texture");
        }
        texture->setRepeated(true);
        textury_.emplace_back(std::move(texture));

        sf::Sprite sprite_grass;
        sprite_grass.setTexture(**(textury_.end() - 1));
        sprite_grass.setTextureRect(sf::IntRect(0, 0, 800, 600));
        obiekty_.emplace_back(sprite_grass);

        std::unique_ptr<sf::Texture> texture_guy = std::make_unique<sf::Texture>();
        if (!texture_guy->loadFromFile("../tex/guy.png")) {
            throw("Could not load texture");
        }

        sf::Sprite guy;
        textury_.emplace_back(std::move(texture_guy));
        guy.setTexture(**(textury_.end() - 1));

        obiekty_.emplace_back(guy);

        std::unique_ptr<sf::Texture> texture_wall = std::make_unique<sf::Texture>();
        if (!texture_wall->loadFromFile("../tex/wall.png")) {
            throw("Could not load texture");
        }
        texture_wall->setRepeated(true);

        sf::Sprite wall;
        textury_.emplace_back(std::move(texture_wall));

        wall.setTexture(**(textury_.end() - 1));
        wall.setScale(0.3, 0.3);
        wall.setTextureRect(sf::IntRect(0, 0, 40, 400));
        wall.setPosition(100, 100);
        obiekty_.emplace_back(wall);

        sf::Sprite wall_2;
        wall_2.setTexture(**(textury_.end() - 1));
        wall_2.setScale(0.3, 0.3);
        wall_2.setTextureRect(sf::IntRect(0, 0, 40, 400));
        wall_2.setPosition(300, 200);
        obiekty_.emplace_back(wall_2);
    }
    void rysuj()
    {
        window_.clear(sf::Color::Black);
        // draw everything here...

        for (auto &el : obiekty_) {
            window_.draw(el);
        }

        // end the current frame
        window_.display();
    }
    void loop()
    {
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
                    }
                }
            }

            sf::sleep(sf::milliseconds(1));
            this->rysuj();
        }
    }
};
int main()
{
    Scena s(800, 600);
    s.loop();

    return 0;
}
