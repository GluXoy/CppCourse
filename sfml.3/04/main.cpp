#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <algorithm>

struct Eye
{
    sf::ConvexShape outerEye;
    sf::ConvexShape innerEye;
    sf::Vector2f position;
    sf::Vector2f outerEyeRadius = { 70.f, 170.f };
    sf::Vector2f innerEyeRadius = { 20.f, 40.f };
};

void initEye (Eye& eye, sf::Vector2f& eyePosition) {
    eye.position = eyePosition;
    int pointCount = 400;
    
    eye.outerEye.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));
    eye.innerEye.setFillColor(sf::Color(0x00, 0x00, 0x00));
    eye.outerEye.setPointCount(pointCount);
    eye.innerEye.setPointCount(pointCount);
    for (int pointNo = 0; pointNo < pointCount; ++pointNo)
    {
        float angle = float(2 * M_PI * pointNo) / float(pointCount);
        
        sf::Vector2f pointOfOuterEye = {
            eye.position.x + eye.outerEyeRadius.x * std::sin(angle),
            eye.position.y + eye.outerEyeRadius.y * std::cos(angle) 
        };
        eye.outerEye.setPoint(pointNo, pointOfOuterEye);

        sf::Vector2f pointOfInnerEye = {
            eye.position.x + eye.innerEyeRadius.x * std::sin(angle),
            eye.position.y + eye.innerEyeRadius.y * std::cos(angle) 
        };
        eye.innerEye.setPoint(pointNo, pointOfInnerEye);
    }
}

sf::Vector2f toEuclidean(float radius, float angle) {
    return {
        radius * cos(angle),
        radius * sin(angle)
    };
}

void onMouseMove(const sf::Event::MouseMoveEvent& event, sf::Vector2f& mousePosition) {
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

// Рисует и выводит один кадр
void redrawFrame(sf::RenderWindow& window, Eye& leftEye, Eye& rightEye)
{
    window.clear();
    window.draw(leftEye.outerEye);
    window.draw(leftEye.innerEye);
    window.draw(rightEye.outerEye);
    window.draw(rightEye.innerEye);
    window.display();
}

void update(const sf::Vector2f mousePosition, Eye& eye)
{
    const float innerRadius = 22.0f; 
    const sf::Vector2f delta = mousePosition - eye.position;
    float angle = atan2(delta.y, delta.x);
    sf::Vector2f newPosition = toEuclidean(innerRadius, angle);
    eye.innerEye.setPosition(newPosition);    
}

// Программа рисует в окне глаза с зрачком внутри
int main()
{
    constexpr unsigned WINDOW_WIDTH = 800;
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }),
        "Eyes follow mouse", sf::Style::Default, settings);

    Eye leftEye;
    Eye rightEye;
    sf::Vector2f leftEyePosition = {300, 300};
    sf::Vector2f rightEyePosition = {465, 300};

    sf::Vector2f mousePosition;

    initEye(leftEye, leftEyePosition);
    initEye(rightEye, rightEyePosition);
    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, leftEye);
        update(mousePosition, rightEye);
        redrawFrame(window, leftEye, rightEye);
    }
}
