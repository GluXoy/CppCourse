#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 110, 320 }), "Lighter", sf::Style::None);

    window.clear();

    sf::CircleShape shape1(40);
    shape1.setPosition({ 15, 20 }); 
    shape1.setFillColor(sf::Color::Green); 
    window.draw(shape1);

    sf::CircleShape shape2(40);
    shape2.setPosition({ 15, 120 }); 
    shape2.setFillColor(sf::Color::Yellow);
    window.draw(shape2);

    sf::CircleShape shape3(40);
    shape3.setPosition({ 15, 220 });
    shape3.setFillColor(sf::Color::Red);
    window.draw(shape3);

    window.display();

    sf::sleep(sf::seconds(5));

}