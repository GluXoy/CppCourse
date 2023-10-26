#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>


sf::Vector2f toEuclidean(float radius, float angle) {
    return {
        radius * cos(angle),
        radius * sin(angle)
    };
}

float toDegrees(float radians) {
    return float(double(radians) * 180.0 / M_PI);
}

void initArrow(sf::ConvexShape& arrow) {
    arrow.setPosition({ 400, 300 });
    arrow.setPointCount(7);
    arrow.setPoint(0, { 60, 0 });
    arrow.setPoint(1, { 0, -60 });
    arrow.setPoint(2, { 0, -30 });
    arrow.setPoint(3, { -70, -30 });
    arrow.setPoint(4, { -70, 30 });
    arrow.setPoint(5, { 0, 30 });
    arrow.setPoint(6, { 0, 60 });

    arrow.setFillColor(sf::Color::Yellow);
    arrow.setOutlineColor(sf::Color::Black);  
    arrow.setOutlineThickness(2); 
    arrow.setRotation(0.0f);
}

void onMouseMove(const sf::Event::MouseMoveEvent& event, sf::Vector2f& mousePosition) {
    std::cout << "mouse x=" << event.x << ", y=" << event.y << std::endl;
    mousePosition = { float(event.x), float(event.y) };
}

void pollEvents(sf::RenderWindow& window, sf::Vector2f& mousePosition) {
  
    sf::Event event;
    while (window.pollEvent(event)){
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
}

void redrawFrame(sf::RenderWindow& window, sf::ConvexShape& arrow) {
    window.clear(sf::Color::White);
    window.draw(arrow);
    window.display();
}

void update(const sf::Vector2f& mousePosition, sf::ConvexShape& arrow, sf::Clock& clock) {

    const float dTime = clock.restart().asSeconds();
    constexpr float maxRotationSpeed = 90.0f;      
    constexpr float speed = 20.0f;

    const sf::Vector2f motion = mousePosition - arrow.getPosition(); 
    const float targetRotation = toDegrees(atan2(motion.y, motion.x));

    float currentRotation = arrow.getRotation();
    float rotationDiff = targetRotation - currentRotation;
    if (rotationDiff > 180.0) {
        rotationDiff -= 360.0;
    } else if (rotationDiff < -180.0) {
        rotationDiff += 360.0;
    }
    float maxRotationDiff = maxRotationSpeed * dTime;
    rotationDiff = std::max(-maxRotationDiff, std::min(maxRotationDiff, rotationDiff));
    float newRotation = currentRotation + rotationDiff;
    arrow.setRotation(newRotation);

    const float offset = speed * dTime;
    const sf::Vector2f direction =
        {
            (motion.x / std::abs(std::sqrt(motion.x * motion.x + motion.y * motion.y))),
            (motion.y / std::abs(std::sqrt(motion.x * motion.x + motion.y * motion.y))) 
        };

    sf::Vector2f newPosition = arrow.getPosition() + direction * offset;

    if ((newPosition.x <= mousePosition.x && newPosition.y <= mousePosition.y) ||
        (newPosition.x >= mousePosition.x && newPosition.y <= mousePosition.y) ||
        (newPosition.x <= mousePosition.x && newPosition.y >= mousePosition.y) ||
        (newPosition.x >= mousePosition.x && newPosition.y >= mousePosition.y))
    {
        arrow.setPosition(newPosition);
    }
}

int main() {

    constexpr unsigned WINDOW_WIDTH = 800; 
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), 
        "Arrow", sf::Style::Default, settings);

    sf::ConvexShape arrow;
    sf::Vector2f mousePosition;
    initArrow(arrow);  

    sf::Clock clock; 
      
    while (window.isOpen()) {
        pollEvents(window, mousePosition);
        update(mousePosition, arrow, clock);
        redrawFrame(window, arrow);
    }
}