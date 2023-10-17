#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>

// Опрашивает и обрабатывает доступные события в цикле.
void init(sf::ConvexShape &pointer)
{
    pointer.setPointCount(3);
    pointer.setPoint(0, {40, 0});
    pointer.setPoint(1, {-20, -20});
    pointer.setPoint(2, {-20, 20});
    pointer.setPosition({400, 300});
    pointer.setFillColor(sf::Color(0xFF, 0x80, 0x00));
}

// Переводит радианы в градусы
float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
}

// Обрабатывает событие MouseMove, обновляя позицию мыши
void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    std::cout << "mouse x=" << event.x << ", y=" << event.y << std::endl;
    mousePosition = {float(event.x), float(event.y)};
}

// Опрашивает и обрабатывает доступные события в цикле.
void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
            break;
        default:
            break;
        }
    }
}

// Обновляет фигуру, указывающую на мышь
void update(const sf::Vector2f &mousePosition, sf::ConvexShape &pointer, sf::Clock &clock, float &angle)
{
    const float deltaTime = clock.restart().asSeconds();
    const float turningSpeed = 15 * deltaTime;

    float deltaAngle;

    const sf::Vector2f delta = mousePosition - pointer.getPosition();
    float radAngle = atan2(delta.y, delta.x);
    float degreesAngleActual = toDegrees(radAngle);

    deltaAngle = degreesAngleActual - angle;

    if (deltaAngle < -180)
        deltaAngle = deltaAngle + 360;
    if (deltaAngle > 180)
        deltaAngle = deltaAngle - 360;

    if (deltaAngle > 0)
        deltaAngle = std::min(deltaAngle, turningSpeed);
    else
        deltaAngle = std::min(-deltaAngle, -turningSpeed);

    angle = angle + deltaAngle;

    pointer.setRotation(angle);
}

// Рисует и выводит один кадр
void redrawFrame(sf::RenderWindow &window, sf::ConvexShape &pointer)
{
    window.clear();
    window.draw(pointer);
    window.display();
}

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}),
        "Pointer follows mouse", sf::Style::Default, settings);

    sf::ConvexShape pointer;
    sf::Vector2f mousePosition;
    sf::Clock clock;
    float angle = 0;

    init(pointer);

    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, pointer, clock, angle);
        redrawFrame(window, pointer);
    }
}