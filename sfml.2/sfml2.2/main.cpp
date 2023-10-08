#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;

int main()
{
    constexpr int pointCount = 2000;
    //const sf::Vector2f polarRoseRadius = {200.f, 10.f};

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({800, 600}), "Polar Rose",
        sf::Style::Default, settings);

    sf::ConvexShape polarRose;
    polarRose.setPosition({400, 320});
    polarRose.setFillColor(sf::Color(0xFF, 0x09, 0x11));

    polarRose.setPointCount(pointCount);

    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        float rad = 200 * sin(6 * angle);
        sf::Vector2f point = {
            rad * std::sin(angle),
            rad * std::cos(angle)};
        polarRose.setPoint(pointNo, point);
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.draw(polarRose);
        window.display();
    }
}