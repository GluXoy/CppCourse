#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>

int main() {
    constexpr int pointCount = 1000;
    constexpr float maxRadius = 200;
    constexpr float leafs = 6;
    constexpr float rotationSpeed = 2.0; 

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Rose", sf::Style::Default, settings);

    sf::ConvexShape rose;
    sf::Vector2f startPos = {400, 320};
    rose.setPosition(startPos);
    rose.setFillColor(sf::Color(0xFF, 0x09, 0x80));

    rose.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo) {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        float radius = maxRadius * std::sin(leafs * angle);
        sf::Vector2f point = {
            radius * std::cos(angle),
            radius * std::sin(angle)
        };
        rose.setPoint(pointNo, point);
    }

    sf::Clock clock; 

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Time elapsed = clock.getElapsedTime();
        float angle = elapsed.asSeconds() * rotationSpeed; 

        sf::Vector2f newPosition = {
            startPos.x + 80 * std::cos(angle), 
            startPos.y + 80 * std::sin(angle)  
        };
        rose.setPosition(newPosition);

        window.clear();
        window.draw(rose);
        window.display();
    }
}