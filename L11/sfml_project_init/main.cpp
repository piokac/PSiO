#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <memory>
#include <vector>
int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");

    // create some shapes
    sf::Texture texture;
    if (!texture.loadFromFile("../tex/grass.png")) {
        std::cerr << "Could not load texture" << std::endl;
        return 1;
    }

    sf::Sprite sprite_grass;
    sprite_grass.setTexture(texture);
    texture.setRepeated(true);

    sf::Texture texture_guy;
    if (!texture_guy.loadFromFile("../tex/guy.png")) {
        return 1;
    }

    sf::Sprite guy;
    guy.setTexture(texture_guy);
    sprite_grass.setTextureRect(sf::IntRect(0, 0, 800, 600));

    sf::Texture texture_wall;
    if (!texture_wall.loadFromFile("../tex/wall.png")) {
        return 1;
    }
    texture_wall.setRepeated(true);

    sf::Sprite wall;
    wall.setTexture(texture_wall);
    wall.setScale(0.3, 0.3);
    wall.setTextureRect(sf::IntRect(0, 0, 40, 400));
    wall.setPosition(100, 100);

    sf::Sprite wall_2;
    wall_2.setTexture(texture_wall);
    wall_2.setScale(0.3, 0.3);
    wall_2.setTextureRect(sf::IntRect(0, 0, 40, 400));
    wall_2.setPosition(300, 200);
    //    wall.setRotation(70);
    // run the program as long as the window is open
    sf::Clock clock;
    while (window.isOpen()) {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event)) {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Space) {
                    guy.setTextureRect(sf::IntRect(10, 20, 20, 15));

                    std::cout << "Space released" << std::endl;
                }
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
                    std::cout << "Mouse clicked: " << mouse_pos.x << ", " << mouse_pos.y
                              << std::endl;
                }
            }
        }

        window.clear(sf::Color::Black);
        // draw everything here...

        window.draw(sprite_grass);
        window.draw(wall);
        window.draw(wall_2);
        window.draw(guy);

        // end the current frame
        window.display();
    }

    return 0;
}
