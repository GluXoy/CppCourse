#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct Circle
{
    sf::CircleShape shape;
    sf::Vector2f position;
    float radius = 40.0f;
    float speed;
    sf::Color color;
};

void pollEvents(sf::RenderWindow& window) {
  
    sf::Event event;
    while (window.pollEvent(event)){
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        default:
            break;
        }
    }
}

void redrawFrame(sf::RenderWindow& window, vector<Circle>& circles) {
    window.clear();
    for (size_t i = 0; i < circles.size(); i++) {
        window.draw(circles[i].shape);
    }
    window.display();
}

void initCircle(Circle& circle) {
    circle.shape.setRadius(circle.radius);
    circle.shape.setFillColor(circle.color);
    circle.shape.setPosition(circle.position);
}

void initArrayOfCircles(vector<Circle>& circles) {

    const int MAX_BALLS = 5;

    sf::Color colors[] = {
        sf::Color::Red,
        sf::Color::Blue,
        sf::Color::Yellow, 
        sf::Color(128, 128, 0),
        sf::Color(0, 128, 0)
    };

    sf::Vector2f positions[] = {
        sf::Vector2f(50, 200),
        sf::Vector2f(250, 200),
        sf::Vector2f(400, 200),
        sf::Vector2f(550, 200),
        sf::Vector2f(700, 200)
    };

    float speeds[] = {
        110.0f,
        70.0f,
        80.0f,
        100.0f,
        90.0f
    };

    for (int i = 0; i < MAX_BALLS; i++) {
        Circle circle;
        circle.color = colors[i];
        circle.position = positions[i];
        circle.speed = speeds[i];
        initCircle(circle);
        circles.push_back(circle);
    } 
}

void update(vector<Circle>& circles, sf::Clock& clock, sf::Vector2f windowSize) {

    float dTime = clock.restart().asSeconds();
    for (int i = 0; i < circles.size(); i++) {
        float offset = circles[i].speed * dTime; 

        if ( ((circles[i].position.x + offset <= 0) && (circles[i].speed < 0))
        || ((circles[i].position.x + 2 * circles[i].radius + offset >= windowSize.x) && (circles[i].speed > 0)) ) {
            circles[i].speed = -circles[i].speed;
        } 
        else if ( ((circles[i].position.y + offset <= 0) && (circles[i].speed < 0)) 
        || ((circles[i].position.y + 2 * circles[i].radius + offset >= windowSize.y) && (circles[i].speed > 0)) ) {
            circles[i].speed = -circles[i].speed;
        }

        circles[i].position.x += offset;
        circles[i].position.y += offset;
        circles[i].shape.setPosition(circles[i].position);
    }

}

int main() {

    constexpr unsigned WINDOW_WIDTH = 800; 
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::Vector2f windowSize = {WINDOW_WIDTH, WINDOW_HEIGHT};

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), 
        "Circles", sf::Style::Default, settings);

    vector<Circle> circles;   
    initArrayOfCircles(circles);

    sf::Clock clock;

    while (window.isOpen()) {
        pollEvents(window);
        update(circles, clock, windowSize);
        redrawFrame(window, circles);
    }
}



