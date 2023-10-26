#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <iostream>

constexpr unsigned WINDOW_WIDTH = 800;
constexpr unsigned WINDOW_HEIGHT = 600;

int main() {

    float speedX = 100.f;
    constexpr float BALL_SIZE = 40;

    sf::RenderWindow window(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), "Wave Moving Ball");
    sf::Clock clock;
    sf::Clock clock2;
    
    sf::CircleShape ball(BALL_SIZE);
    const sf::Vector2f startPosition = { 10, 350 };
    ball.setPosition(startPosition);
    sf::Vector2f currentPosition = ball.getPosition();
    ball.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        constexpr float amplitudeY = 80.f;
        constexpr float periodY = 2;

        const float dTime = clock2.restart().asSeconds();
        const float time = clock.getElapsedTime().asSeconds();
        const float wavePhase = time * float(2 * M_PI);
        currentPosition.x += speedX * dTime;
        currentPosition.y = startPosition.y + amplitudeY * std::sin(wavePhase / periodY);

        if (((currentPosition.x + 2 * BALL_SIZE >= WINDOW_WIDTH) && (speedX > 0)) || ((currentPosition.x <= 0) && (speedX < 0))) {
            speedX = -speedX;
        } 
 
        ball.setPosition(currentPosition);
        
        window.clear();
        window.draw(ball);
        window.display();
    }
}