#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>

// Инициализирует фигуру-указатель
void init(sf::ConvexShape& pointer) {
    pointer.setPointCount(3);
    pointer.setPoint(0, {40, 0});
    pointer.setPoint(1, {-20, -20});
    pointer.setPoint(2, {-20, 20});
    pointer.setPosition({400, 300});
    pointer.setFillColor(sf::Color(0xFF, 0x80, 0x00));
}

float toDegrees(float radians) {
    return float(double(radians) * 180.0 / M_PI);
}

void onMouseMove(const sf::Event::MouseMoveEvent& event, sf::Vector2f& mousePosition) {
    mousePosition = { float(event.x), float(event.y) };
}

// Опрашивает и обрабатывает доступные события в цикле. 
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

// Обновляет фигуру, указывающую на мышь 
void update(const sf::Vector2f& mousePosition, sf::ConvexShape& pointer, sf::Clock& clock) {
    const sf::Vector2f delta = mousePosition - pointer.getPosition();
    const float angle = toDegrees(atan2(delta.y, delta.x));
    const float maxRotationSpeed = 45.0f;

    const float dTime = clock.restart().asSeconds();
    float currentRotation = pointer.getRotation();
    std::cout << "rot: " << 360 - currentRotation << std::endl;
    float targetRotation = angle;

    float rotationDiff = targetRotation - currentRotation;

    if (rotationDiff > 180.0) {
        rotationDiff -= 360.0;
    } else if (rotationDiff < -180.0) {
        rotationDiff += 360.0;
    }

    float maxRotationDiff = maxRotationSpeed * dTime;

    rotationDiff = std::max(-maxRotationDiff, std::min(maxRotationDiff, rotationDiff));

    float newRotation = currentRotation + rotationDiff;
    pointer.setRotation(newRotation);
}

// Рисует и выводит один кадр
void redrawFrame(sf::RenderWindow& window, sf::ConvexShape& pointer) {
    window.clear();
    window.draw(pointer);
    window.display();
}

int main() {

    constexpr unsigned WINDOW_WIDTH = 800; 
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), 
        "Pointer follows mouse", sf::Style::Default, settings);

    sf::ConvexShape pointer;
    sf::Vector2f mousePosition;

    sf::Clock clock;
    init(pointer);    
    while (window.isOpen()) {
        pollEvents(window, mousePosition);
        update(mousePosition, pointer, clock);
        redrawFrame(window, pointer);
    }
}
