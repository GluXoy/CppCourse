#include <SFML/Graphics.hpp>
#include <cmath>
#include <iostream>

struct Pointer
{
    sf::Sprite pointerImg;
    sf::Vector2f position; 
    bool init = false;
    bool isCatFlipped = false;
};

void onMouseMove(const sf::Event::MouseMoveEvent& event, sf::Vector2f& mousePosition) {
    mousePosition = { float(event.x), float(event.y) };
}


void pollEvents(sf::RenderWindow& window, sf::Vector2f& mousePosition, Pointer& pointer) {
  
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
        case sf::Event::MouseButtonReleased:
            if (event.mouseButton.button == sf::Mouse::Left) {
                pointer.position = { float(event.mouseButton.x), float(event.mouseButton.y) };
                pointer.pointerImg.setPosition(pointer.position - sf::Vector2f(pointer.pointerImg.getGlobalBounds().width / 2, pointer.pointerImg.getGlobalBounds().height / 2));
                pointer.init = true;
            }
            break;
        default:
            break;
        }
    }
}

void update(sf::Sprite& catImg, Pointer& pointer, sf::Clock& clock) {
    const float dTime = clock.restart().asSeconds();
    if (pointer.init) {
        constexpr float speed = 50.0f;

        const sf::Vector2f motion = pointer.position - catImg.getPosition(); 

        const float offset = speed * dTime;
        const sf::Vector2f direction =
            {
                float(motion.x / std::abs(std::sqrt(motion.x * motion.x + motion.y * motion.y))),
                float(motion.y / std::abs(std::sqrt(motion.x * motion.x + motion.y * motion.y))) 
            };


        if (motion.x < 0) {
            if (!pointer.isCatFlipped) {
                catImg.setScale(-1, 1);
                pointer.isCatFlipped = true;
            }
        } else {
            catImg.setScale(1, 1);
            pointer.isCatFlipped = false;
        }

        sf::Vector2f newPosition = catImg.getPosition() + direction * offset;

        if (std::abs(motion.x) <= offset && std::abs(motion.y) <= offset) {
            pointer.init = false; 
        }

        catImg.setPosition(newPosition);

    }
}

void redrawFrame(sf::RenderWindow& window, sf::Sprite& catImg, Pointer& pointer) {
    window.clear(sf::Color::White);
    window.draw(catImg);
    if (pointer.init == true) {
        window.draw(pointer.pointerImg);
    }
    window.display();
}



int main() {

    constexpr unsigned WINDOW_WIDTH = 800; 
    constexpr unsigned WINDOW_HEIGHT = 600;

    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), 
        "Moving cat", sf::Style::Default, settings);

    sf::Texture texture;
    if (!texture.loadFromFile("img/cat.png")) {
        return 1;
    }

    sf::Texture texture2;
    if (!texture2.loadFromFile("img/red_pointer.png")) {
        return 1;
    }

    sf::Sprite catImg;
    catImg.setTexture(texture);
    catImg.setPosition(sf::Vector2f(400, 300));
    catImg.setOrigin(catImg.getGlobalBounds().width / 2, catImg.getGlobalBounds().height / 2); 

    Pointer pointer;
    pointer.pointerImg.setTexture(texture2);

    sf::Vector2f mousePosition;

    sf::Clock clock;
      
    while (window.isOpen()) {
        pollEvents(window, mousePosition, pointer);
        update(catImg, pointer, clock);
        std::cout << "cat x=" << catImg.getPosition().x << ", cat y=" << catImg.getPosition().y << std::endl;
        redrawFrame(window, catImg, pointer);
    }
}