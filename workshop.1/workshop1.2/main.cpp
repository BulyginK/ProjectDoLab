#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>

void initArrow(sf::ConvexShape &arrow, sf::Vector2f &position)
{
    arrow.setPosition(position);
    arrow.setPointCount(7);
    arrow.setPoint(0, {70, 0});
    arrow.setPoint(1, {10, 60});
    arrow.setPoint(2, {10, 30});
    arrow.setPoint(3, {-50, 30});
    arrow.setPoint(4, {-50, -30});
    arrow.setPoint(5, {10, -30});
    arrow.setPoint(6, {10, -60});
    arrow.setRotation(0);
    arrow.setFillColor(sf::Color(0xFF, 0xFF, 0x00));
    arrow.setOutlineColor(sf::Color(0x00, 0x00, 0x00));
    arrow.setOutlineThickness(3.0f);
};

void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    std::cout << "mouse x=" << event.x << ", y=" << event.y << std::endl;
    mousePosition = {float(event.x), float(event.y)};
};

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
};

float toDegrees(float radians)
{
    return float(double(radians) * 180.0 / M_PI);
};

void updateAngle(const sf::Vector2f &mousePosition, sf::ConvexShape &arrow, float deltaTime, float &angle)
{
    const float maxTurningSpeed = 90.f;
    const float turningSpeed = maxTurningSpeed * deltaTime;
    float deltaAngle;

    const sf::Vector2f delta = mousePosition - arrow.getPosition();
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

    if (angle > 360)
        angle = angle - 360;
    if (angle < -360)
        angle = angle + 360;

    arrow.setRotation(angle);
};

void updatePosition(const sf::Vector2f &mousePosition, sf::ConvexShape &arrow, float deltaTime, sf::Vector2f &position)
{
    const float maxSpeed = 20.f;
    const float speed = maxSpeed * deltaTime;

    const sf::Vector2f offset = mousePosition - arrow.getPosition();

    if (offset.x != 0 && offset.y != 0)
    {
        float offsetLenght = sqrt(offset.y * offset.y + offset.x * offset.x);
        sf::Vector2f direction = {offset.x / offsetLenght, offset.y / offsetLenght};
        position = arrow.getPosition() + direction * speed;
    }

    arrow.setPosition(position);
};

void update(const sf::Vector2f &mousePosition, sf::ConvexShape &arrow, sf::Clock &clock, float &angle, sf::Vector2f &position)
{
    float deltaTime = clock.restart().asSeconds();
    updateAngle(mousePosition, arrow, deltaTime, angle);
    updatePosition(mousePosition, arrow, deltaTime, position);
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
    sf::Vector2f mousePosition;
    sf::Vector2f position = {400.f, 300.f};
    float angle = 0;
    sf::Clock clock;

    initArrow(arrow, position);

    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, arrow, clock, angle, position);
        redrawFrame(window, arrow);
    }
}