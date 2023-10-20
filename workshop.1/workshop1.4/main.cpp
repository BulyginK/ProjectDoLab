#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

/*
void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    std::cout << "mouse x=" << event.x << ", y=" << event.y << std::endl;
    mousePosition = {float(event.x), float(event.y)};
};
*/

void onMouseClick(const sf::Event::MouseButtonEvent &event, sf::Vector2f &mousePositionClick)
{
    mousePositionClick = {float(event.x), float(event.y)};
}

void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePositionClick, bool &caught)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseButtonPressed:
            onMouseClick(event.mouseButton, mousePositionClick);
            caught = false;
            break;
        default:
            break;
        }
    }
};

void updateAngle(const sf::Vector2f &mousePositionClick, sf::Sprite &cat)
{
    if ((mousePositionClick.x - cat.getPosition().x) < 0)
        cat.setScale(-1, 1);
    else
        cat.setScale(1, 1);
};

void updatePosition(
    const sf::Vector2f &mousePositionClick,
    sf::Sprite &cat,
    sf::Vector2f &position,
    float deltaTime,
    bool &caught)
{
    const float maxSpeed = 150.f;
    const float speed = maxSpeed * deltaTime;

    const sf::Vector2f offset = mousePositionClick - cat.getPosition();
    float offsetLenght = sqrt(offset.y * offset.y + offset.x * offset.x);

    if (offsetLenght >= 1)
    {
        caught = false;
        sf::Vector2f direction = {offset.x / offsetLenght, offset.y / offsetLenght};
        position = cat.getPosition() + direction * speed;
        cat.setPosition(position);
    }
    else
    {
        caught = true;
    }
};

void update(
    const sf::Vector2f &mousePositionClick,
    sf::Sprite &cat,
    sf::Sprite &pointer,
    sf::Vector2f &position,
    sf::Clock &clock,
    bool &caught)
{
    float deltaTime = clock.restart().asSeconds();
    pointer.setPosition(mousePositionClick);
    if (!caught)
    {
        updatePosition(mousePositionClick, cat, position, deltaTime, caught);
        updateAngle(mousePositionClick, cat);
    }
};

void redrawFrame(sf::RenderWindow &window, sf::Sprite cat, sf::Sprite pointer, bool &caught)
{
    window.clear(sf::Color::White);
    window.draw(cat);
    if (!caught)
        window.draw(pointer);
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
        "The cat follows a pointer", sf::Style::Default, settings);

    sf::Texture textureCat;
    if (!textureCat.loadFromFile("cat.png"))
    {
        std::cout << "File for Cat not found!" << std::endl;
        return 1;
    }
    sf::Sprite cat;
    cat.setTexture(textureCat);
    cat.setPosition({100.f, 100.f});
    cat.setOrigin({19.f, 12.f});

    sf::Texture texturePointer;
    if (!texturePointer.loadFromFile("pointer.png"))
    {
        std::cout << "File for Pointer not found!" << std::endl;
        return 1;
    }
    sf::Sprite pointer;
    pointer.setTexture(texturePointer);
    pointer.setPosition({700.f, 500.f});
    pointer.setOrigin({16.f, 16.f});

    sf::Vector2f position;
    sf::Clock clock;
    sf::Vector2f mousePositionClick;
    bool caught = false;

    while (window.isOpen())
    {
        pollEvents(window, mousePositionClick, caught);
        update(mousePositionClick, cat, pointer, position, clock, caught);
        redrawFrame(window, cat, pointer, caught);
    }
}