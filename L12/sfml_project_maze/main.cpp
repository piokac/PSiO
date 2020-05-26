#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <memory>
#include <vector>
class LabiryntAbstract
{
public:
    virtual void rysuj() const = 0;
    //    virtual void ustaw_sciane(int x, int y, int w, int h) = 0;
};
class Decorator : public sf::Sprite
{
    std::unique_ptr<sf::Sprite> base_;
    sf::RectangleShape rect_;

public:
    Decorator(std::unique_ptr<sf::Sprite> &el) : base_(std::move(el)), rect_(sf::Vector2f(10, 10))
    {
        rect_.setFillColor(sf::Color::Red);
    }
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(*base_, states);
        target.draw(rect_, states);
    }
};
class Decorator_blue : public sf::Sprite
{
    std::unique_ptr<sf::Sprite> base_;
    sf::RectangleShape rect_;

public:
    Decorator_blue(std::unique_ptr<sf::Sprite> &&el)
        : base_(std::move(el)), rect_(sf::Vector2f(10, 10))
    {
        rect_.setFillColor(sf::Color::Blue);
        rect_.setPosition(10, 50);
    }
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        target.draw(*base_, states);
        target.draw(rect_, states);
    }
};

class Labirynt : public LabiryntAbstract
{
    std::vector<std::unique_ptr<sf::Sprite>> obiekty_;
    std::vector<std::unique_ptr<sf::Texture>> textury_;
    sf::RenderWindow *window_;

public:
    Labirynt(sf::RenderWindow *w) : window_(w)
    {
        // create some shapes
        std::unique_ptr<sf::Texture> texture = std::make_unique<sf::Texture>();
        if (!texture->loadFromFile("../tex/grass.png")) {
            std::cerr << "Could not load texture" << std::endl;
            throw("Could not load texture");
        }
        texture->setRepeated(true);
        textury_.emplace_back(std::move(texture));

        std::unique_ptr<sf::Sprite> sprite_grass = std::make_unique<sf::Sprite>();
        sprite_grass->setTexture(**(textury_.end() - 1));
        sprite_grass->setTextureRect(sf::IntRect(0, 0, 800, 600));
        obiekty_.emplace_back(std::move(sprite_grass));

        std::unique_ptr<sf::Texture> texture_guy = std::make_unique<sf::Texture>();
        if (!texture_guy->loadFromFile("../tex/guy.png")) {
            throw("Could not load texture");
        }

        std::unique_ptr<sf::Sprite> guy = std::make_unique<sf::Sprite>();
        textury_.emplace_back(std::move(texture_guy));
        guy->setTexture(**(textury_.end() - 1));

        std::unique_ptr<Decorator> guy_decorated = std::make_unique<Decorator>(guy);
        obiekty_.emplace_back(std::move(guy_decorated));

        std::unique_ptr<sf::Texture> texture_wall = std::make_unique<sf::Texture>();
        if (!texture_wall->loadFromFile("../tex/wall.png")) {
            throw("Could not load texture");
        }
        texture_wall->setRepeated(true);

        std::unique_ptr<sf::Sprite> wall = std::make_unique<sf::Sprite>();
        textury_.emplace_back(std::move(texture_wall));

        wall->setTexture(**(textury_.end() - 1));
        wall->setScale(0.3, 0.3);
        wall->setTextureRect(sf::IntRect(0, 0, 40, 400));

        std::unique_ptr<Decorator> wall_decorated = std::make_unique<Decorator>(wall);
        std::unique_ptr<Decorator_blue> wall_decorated_2 = std::make_unique<Decorator_blue>(
            std::move(wall_decorated));

        wall_decorated_2->setPosition(100, 100);
        obiekty_.emplace_back(std::move(wall_decorated_2));
        //        obiekty_.emplace_back(std::move(wall));

        std::unique_ptr<sf::Sprite> wall_2 = std::make_unique<sf::Sprite>();

        wall_2->setTexture(**(textury_.end() - 1));
        wall_2->setScale(0.3, 0.3);
        wall_2->setTextureRect(sf::IntRect(0, 0, 40, 400));

        wall_2->setPosition(300, 200);

        obiekty_.emplace_back(std::move(wall_2));
    }
    void rysuj() const
    {
        for (auto &el : obiekty_) {
            window_->draw(*el);
        }
    }
};
class ScenaAbstract
{
public:
    virtual void rysuj() = 0;
    //    virtual void create_window(int w, int h) = 0;
    virtual void loop() = 0;
    virtual LabiryntAbstract *create(int level) = 0;
};

class Scena : public ScenaAbstract
{
    sf::RenderWindow window_;
    LabiryntAbstract *labirynt_;

public:
    Scena(int W, int H) : window_(sf::VideoMode(W, H), "SFML app")
    {
        sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
        labirynt_ = create(0);
    }
    LabiryntAbstract *create(int level)
    {
        if (level == 0)
            return new Labirynt(&window_);
        else
            return new Labirynt(&window_);
    }
    void rysuj()
    {
        window_.clear(sf::Color::Black);
        // draw everything here...

        labirynt_->rysuj();

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
