#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

void initArrow(sf::ConvexShape &arrow)
{
    arrow.setPosition({400, 300});
    arrow.setPointCount(7);
    arrow.setPoint(0, {70, 0});
    arrow.setPoint(1, {10, 60});
    arrow.setPoint(2, {10, 30});
    arrow.setPoint(3, {-50, 30});
    arrow.setPoint(4, {-50, -30});
    arrow.setPoint(5, {10, -30});
    arrow.setPoint(6, {10, -60});
    arrow.setRotation(-80);
    arrow.setFillColor(sf::Color(0xFF, 0xFF, 0x00));
    arrow.setOutlineColor(sf::Color(0x00, 0x00, 0x00));
    arrow.setOutlineThickness(3.0f);
};

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

void redrawFrame(sf::RenderWindow &window, sf::ConvexShape &arrow)
{
    window.clear(sf::Color::White);
    window.draw(arrow);
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
        "Arrow", sf::Style::Default, settings);

    sf::ConvexShape arrow;

    initArrow(arrow);

    while (window.isOpen())
    {
        pollEvents(window);
        redrawFrame(window, arrow);
    }
}