#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 800;

int main()
{
    constexpr int pointCount = 200;
    constexpr float circleRadius = 80;
    sf::Vector2f position = {400, 400};
    sf::Clock clock;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Moving Polar Rose",
        sf::Style::Default, settings);

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

        sf::ConvexShape polarRose;
        polarRose.setFillColor(sf::Color(0xFF, 0x09, 0x11));

        const float time = clock.getElapsedTime().asSeconds();
        const float wavePhase = time * float(2 * M_PI);

        sf::Vector2f offset = {
            circleRadius * std::sin(wavePhase),
            circleRadius * std::cos(wavePhase)};

        polarRose.setPosition(position + offset);

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

        window.clear();
        window.draw(polarRose);
        window.display();
    }
}