#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

void pollEvents(sf::RenderWindow &window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        default:
            break;
        }
    }
};

void redrawFrame(sf::RenderWindow &window, sf::Sprite sprite)
{
    window.clear(sf::Color::White);
    window.draw(sprite);
    window.display();
};

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Cat in window", sf::Style::Default, settings);

    sf::Texture texture;
    if (!texture.loadFromFile("cat.png"))
    {
        std::cout << "file not found!" << std::endl;
        return 1;
    }
    sf::Sprite cat;
    cat.setTexture(texture);
    cat.setPosition({100.f, 100.f});

    while (window.isOpen())
    {
        pollEvents(window);
        redrawFrame(window, cat);
    }
}