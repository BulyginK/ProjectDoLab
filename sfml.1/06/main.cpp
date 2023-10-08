//Задание sfml1.3

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    //каркас
    sf::RectangleShape shape1;
    shape1.setSize({800, 400});
    shape1.setRotation(0);
    shape1.setPosition({200, 500});
    shape1.setFillColor(sf::Color(0x60, 0x60, 0x60));

    //крыша
    sf::ConvexShape trapeze;
    trapeze.setFillColor(sf::Color(0xFF, 0x80, 0xFF));
    trapeze.setPosition(200, 350);
    trapeze.setPointCount(4);
    trapeze.setPoint(0, {0, 0});
    trapeze.setPoint(1, {+800, 0});
    trapeze.setPoint(2, {+920, 150});
    trapeze.setPoint(3, {-120, 150});

    //дверь
    sf::RectangleShape shape2;
    shape2.setSize({100, 300});
    shape2.setRotation(0);
    shape2.setPosition({300, 600});
    shape2.setFillColor(sf::Color(0xFF, 0x80, 0xFF));

    //труба
    sf::RectangleShape shape3;
    shape3.setSize({150, 80});
    shape3.setRotation(0);
    shape3.setPosition({800, 250});
    shape3.setFillColor(sf::Color(0x60, 0x60, 0x60));

    sf::RectangleShape shape4;
    shape4.setSize({100, 100});
    shape4.setRotation(0);
    shape4.setPosition({825, 300});
    shape4.setFillColor(sf::Color(0x60, 0x60, 0x60));

    //дым
    sf::CircleShape shape5(40);
    shape5.setPosition({850, 150});
    shape5.setFillColor(sf::Color(0x90, 0x90, 0x90));
    sf::CircleShape shape6(50);
    shape6.setPosition({870, 100});
    shape6.setFillColor(sf::Color(0x90, 0x90, 0x90));
    sf::CircleShape shape7(50);
    shape7.setPosition({920, 50});
    shape7.setFillColor(sf::Color(0x90, 0x90, 0x90));

    sf::RenderWindow window(sf::VideoMode({1500, 900}), "Convex Shapes");
    window.clear();
    window.draw(shape1);
    window.draw(trapeze);
    window.draw(shape2);
    window.draw(shape3);
    window.draw(shape4);
    window.draw(shape5);
    window.draw(shape6);
    window.draw(shape7);
    window.display();

    sf::sleep(sf::seconds(5));
}