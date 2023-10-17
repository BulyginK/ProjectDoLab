#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>

struct Eyes
{
    sf::ConvexShape leftEye;
    sf::ConvexShape rightEye;
    sf::ConvexShape leftPupil;
    sf::ConvexShape rightPupil;
    sf::Vector2f leftEyePosition = {330.f, 300.f};
    sf::Vector2f rightEyePosition = {470.f, 300.f};
    sf::Vector2f eyeRadius = {50.f, 120.f};
    sf::Vector2f pupilRadius = {10.f, 30.f};
    float leftSight = 0;
    float rightSight = 0;
};

void getSetPointEye(sf::ConvexShape &eye, sf::Vector2f &eyeRadius)
{
    constexpr int pointCount = 200;

    eye.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = {
            eyeRadius.x * std::sin(angle),
            eyeRadius.y * std::cos(angle)};
        eye.setPoint(pointNo, point);
    }
}

//Инициализация глаз
void initEyes(Eyes &eyes)
{
    eyes.leftEye.setPosition(eyes.leftEyePosition);
    eyes.rightEye.setPosition(eyes.rightEyePosition);
    eyes.leftEye.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    eyes.rightEye.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));

    getSetPointEye(eyes.leftEye, eyes.eyeRadius);
    getSetPointEye(eyes.rightEye, eyes.eyeRadius);
};

// Обрабатывает событие MouseMove, обновляя позицию мыши
void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    //std::cout << "mouse x=" << event.x << ", y=" << event.y << std::endl;
    mousePosition = {float(event.x), float(event.y)};
};

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
};

// Обновляет позиции зрачков согласно текущему состоянию
void updatePupilEye(sf::Vector2f &position, sf::ConvexShape &pupil, sf::Vector2f &radius, float sight)
{
    const float circleRadius = 25;

    sf::Vector2f offset = {
        circleRadius * std::cos(sight),
        circleRadius * std::sin(sight)};

    constexpr int pointCount = 50;

    pupil.setPosition(position + offset);
    pupil.setFillColor(sf::Color(0x00, 0x00, 0x00));

    pupil.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        sf::Vector2f point = {
            radius.x * std::sin(angle),
            radius.y * std::cos(angle)};
        pupil.setPoint(pointNo, point);
    }
};

// Обновляет зрачки, смотрящие на мышь
void update(const sf::Vector2f &mousePosition, Eyes &eyes)
{
    const sf::Vector2f deltaForLeftEye = mousePosition - eyes.leftEyePosition;
    const sf::Vector2f deltaForRightEye = mousePosition - eyes.rightEyePosition;
    eyes.leftSight = atan2(deltaForLeftEye.y, deltaForLeftEye.x);
    eyes.rightSight = atan2(deltaForRightEye.y, deltaForRightEye.x);
    updatePupilEye(eyes.leftEyePosition, eyes.leftPupil, eyes.pupilRadius, eyes.leftSight);
    updatePupilEye(eyes.rightEyePosition, eyes.rightPupil, eyes.pupilRadius, eyes.rightSight);
};

// Рисует и выводит один кадр
void redrawFrame(sf::RenderWindow &window, Eyes &eyes)
{
    window.clear();
    window.draw(eyes.leftEye);
    window.draw(eyes.rightEye);
    window.draw(eyes.leftPupil);
    window.draw(eyes.rightPupil);
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
        "Eye follows mouse", sf::Style::Default, settings);

    Eyes eyes;
    sf::Vector2f mousePosition;

    initEyes(eyes);

    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, eyes);
        redrawFrame(window, eyes);
    }
}