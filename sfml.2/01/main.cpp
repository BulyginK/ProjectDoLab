#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;
    sf::Vector2f speed = {50.f * 10, 15.f * 10};
    constexpr float BALL_SIZE = 40;

    sf::RenderWindow window(sf::VideoMode({800, 600}), "Moving Ball");
    sf::Clock clock;

    sf::CircleShape shape(BALL_SIZE);
    shape.setPosition({WINDOW_WIDTH, WINDOW_HEIGHT});
    shape.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));

    while (window.isOpen())
    {
        //  Обработка событий
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        //  Обработка состояния
        const float dt = clock.restart().asSeconds();

        sf::Vector2f position = shape.getPosition();
        position += speed * dt;

        if ((position.x + 2 * BALL_SIZE >= WINDOW_WIDTH) && (speed.x > 0))
        {
            speed.x = -speed.x;
        }
        if ((position.x < 0) && (speed.x < 0))
        {
            speed.x = -speed.x;
        }
        if ((position.y + 2 * BALL_SIZE >= WINDOW_HEIGHT) && (speed.y > 0))
        {
            speed.y = -speed.y;
        }
        if ((position.y < 0) && (speed.y < 0))
        {
            speed.y = -speed.y;
        }

        shape.setPosition(position);

        window.clear();
        window.draw(shape);
        window.display();
    }
}