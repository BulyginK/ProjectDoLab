//Задание sfml1.1

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({250, 600}), "Rectangles and circle");

    window.clear();

    sf::RectangleShape shape1;
    shape1.setSize({400, 140});
    shape1.setRotation(90);
    shape1.setPosition({200, 140});
    shape1.setFillColor(sf::Color(0x60, 0x60, 0x60));
    window.draw(shape1);

    sf::CircleShape shape2(60);
    shape2.setPosition({70, 150});
    shape2.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(shape2);

    sf::CircleShape shape3(60);
    shape3.setPosition({70, 280});
    shape3.setFillColor(sf::Color(0xFF, 0xFF, 0x0));
    window.draw(shape3);

    sf::CircleShape shape4(60);
    shape4.setPosition({70, 410});
    shape4.setFillColor(sf::Color(0x0, 0xFF, 0x0));
    window.draw(shape4);

    window.display();

    sf::sleep(sf::seconds(3));
}