//Задание sfml1.2

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({2000, 1000}), "Rectangles and circle");

    window.clear();

    //B
    sf::CircleShape shape1(200);
    shape1.setPosition({100, 100});
    shape1.setFillColor(sf::Color(0x0, 0xFF, 0x0));
    window.draw(shape1);

    sf::CircleShape shape2(200);
    shape2.setPosition({100, 500});
    shape2.setFillColor(sf::Color(0x0, 0xFF, 0x0));
    window.draw(shape2);

    sf::CircleShape shape3(100);
    shape3.setPosition({200, 200});
    shape3.setFillColor(sf::Color(0x0, 0x0, 0x0));
    window.draw(shape3);

    sf::CircleShape shape4(100);
    shape4.setPosition({200, 600});
    shape4.setFillColor(sf::Color(0x0, 0x0, 0x0));
    window.draw(shape4);

    sf::RectangleShape shape5;
    shape5.setSize({100, 800});
    shape5.setRotation(0);
    shape5.setPosition({200, 100});
    shape5.setFillColor(sf::Color(0x0, 0xFF, 0x0));
    window.draw(shape5);

    sf::RectangleShape shape6;
    shape6.setSize({100, 800});
    shape6.setRotation(0);
    shape6.setPosition({100, 100});
    shape6.setFillColor(sf::Color(0x0, 0x00, 0x0));
    window.draw(shape6);

    //K
    sf::RectangleShape shape7;
    shape7.setSize({100, 800});
    shape7.setRotation(0);
    shape7.setPosition({600, 100});
    shape7.setFillColor(sf::Color(0x0, 0xFF, 0x0));
    window.draw(shape7);

    sf::RectangleShape shape8;
    shape8.setSize({100, 600});
    shape8.setRotation(30);
    shape8.setPosition({900, 100});
    shape8.setFillColor(sf::Color(0x0, 0xFF, 0x0));
    window.draw(shape8);

    sf::RectangleShape shape9;
    shape9.setSize({100, 500});
    shape9.setRotation(150);
    shape9.setPosition({1000, 840});
    shape9.setFillColor(sf::Color(0x0, 0xFF, 0x0));
    window.draw(shape9);

    //A
    sf::RectangleShape shape10;
    shape10.setSize({100, 800});
    shape10.setRotation(15);
    shape10.setPosition({1300, 100});
    shape10.setFillColor(sf::Color(0x0, 0xFF, 0x0));
    window.draw(shape10);

    sf::RectangleShape shape11;
    shape11.setSize({100, 810});
    shape11.setRotation(345);
    shape11.setPosition({1300, 100});
    shape11.setFillColor(sf::Color(0x0, 0xFF, 0x0));
    window.draw(shape11);

    sf::RectangleShape shape12;
    shape12.setSize({2000, 100});
    shape12.setRotation(0);
    shape12.setPosition({0, 0});
    shape12.setFillColor(sf::Color(0x0, 0x0, 0x0));
    window.draw(shape12);

    sf::RectangleShape shape13;
    shape13.setSize({320, 100});
    shape13.setRotation(0);
    shape13.setPosition({1200, 600});
    shape13.setFillColor(sf::Color(0x0, 0xFF, 0x0));
    window.draw(shape13);

    window.display();

    sf::sleep(sf::seconds(5));
}