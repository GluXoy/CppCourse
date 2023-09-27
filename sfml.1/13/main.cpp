#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1200, 800 }), "house");
    
    float x = 300;
    float y = 460;

    window.clear();

    sf::RectangleShape foundation;
    foundation.setSize({ 600, 330 });
    foundation.setPosition({ x, y });
    foundation.setFillColor(sf::Color(0x5e, 0x2f, 0x0d));
    window.draw(foundation);

    sf::ConvexShape trapeze;
    trapeze.setFillColor(sf::Color(0x5e, 0x14, 0x0d));
    trapeze.setPosition(600, 320);
    trapeze.setPointCount(4);
    trapeze.setPoint(0, {-150, 0});
    trapeze.setPoint(1, {+150, 0});
    trapeze.setPoint(2, {+380, 140});
    trapeze.setPoint(3, {-380, 140});
    window.draw(trapeze);

    sf::RectangleShape door;
    door.setSize({ 110, 230 });
    door.setPosition({ 460, 790 });
    door.setRotation(180);
    door.setFillColor(sf::Color(0x14, 0x14, 0x14));
    window.draw(door);

    sf::RectangleShape chimneyVertical;
    chimneyVertical.setSize({ 50, 100 });
    chimneyVertical.setPosition({ 740, 405 });
    chimneyVertical.setRotation(180);
    chimneyVertical.setFillColor(sf::Color(0x2a, 0x2a, 0x2a));
    window.draw(chimneyVertical);

    sf::RectangleShape chimneyHorizontal;
    chimneyHorizontal.setSize({ 90, 48 });
    chimneyHorizontal.setPosition({ 669, 263 });
    chimneyHorizontal.setFillColor(sf::Color(0x2a, 0x2a, 0x2a));
    window.draw(chimneyHorizontal);

    sf::CircleShape shape1(19);
    shape1.setPosition({ 718, 226 }); 
    shape1.setFillColor(sf::Color(0x83, 0x83, 0x83));
    window.draw(shape1);

    sf::CircleShape shape2(25);
    shape2.setPosition({ 726, 198 }); 
    shape2.setFillColor(sf::Color(0x83, 0x83, 0x83));
    window.draw(shape2);

    sf::CircleShape shape3(36);
    shape3.setPosition({ 740, 155 }); 
    shape3.setFillColor(sf::Color(0x83, 0x83, 0x83));
    window.draw(shape3);

    sf::CircleShape shape4(42);
    shape4.setPosition({ 758, 110 }); 
    shape4.setFillColor(sf::Color(0x83, 0x83, 0x83));
    window.draw(shape4);

    window.display();

    sf::sleep(sf::seconds(5));

}