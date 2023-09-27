#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


void drawM(sf::RenderWindow& window, float& x, float& y){

    float lineWidth = 5;
    float lineHeight = 100;
    float diagonalLengthM = 60;
    int diagonalRotationM = 30;

    sf::RectangleShape verticalLine;
    verticalLine.setSize({ lineHeight, lineWidth });
    verticalLine.setRotation(90);
    verticalLine.setPosition({ x, y });
    verticalLine.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(verticalLine);

    sf::RectangleShape diagonalLineM;
    diagonalLineM.setSize({ diagonalLengthM, lineWidth });
    diagonalLineM.setRotation(90 - diagonalRotationM);
    diagonalLineM.setPosition({ x, y });
    diagonalLineM.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(diagonalLineM);

    diagonalLineM.setRotation(-(90 - diagonalRotationM));
    x = x + sin(diagonalRotationM * M_PI / 180.0) * diagonalLengthM - lineWidth * 1.2;
    y = y + cos(diagonalRotationM * M_PI / 180.0) * diagonalLengthM;
    diagonalLineM.setPosition({ x, y });
    window.draw(diagonalLineM);

    verticalLine.setRotation(-270);
    x = x + sin(diagonalRotationM * M_PI / 180.0) * diagonalLengthM + lineWidth;
    y = y - cos(diagonalRotationM * M_PI / 180.0) * diagonalLengthM;
    verticalLine.setPosition({ x, y });
    window.draw(verticalLine);

}

void drawN(sf::RenderWindow& window, float& x, float& y){
    
    float lineWidth = 5;
    float lineHeight = 100;
    float diagonalLengthN = 112;
    int diagonalRotationN = 30;

    sf::RectangleShape verticalLine;
    verticalLine.setSize({ lineHeight, lineWidth });
    verticalLine.setRotation(90);
    verticalLine.setPosition({ x, y });
    verticalLine.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(verticalLine);

    sf::RectangleShape diagonalLineN;
    diagonalLineN.setSize({ diagonalLengthN, lineWidth });
    diagonalLineN.setRotation(90 - diagonalRotationN);
    diagonalLineN.setPosition({ x, y });
    diagonalLineN.setFillColor(sf::Color(0xFF, 0x0, 0x0));
    window.draw(diagonalLineN);

    verticalLine.setRotation(-90);
    x = x + sin(diagonalRotationN * M_PI / 180.0) * diagonalLengthN - lineWidth;
    y = y + lineHeight;
    verticalLine.setPosition({ x, y });
    window.draw(verticalLine);

}

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 700, 500 }), "Initials");
    
    float x = 250;
    float y = 175;

    window.clear();
    drawM(window, x, y);
    x += 20;
    drawM(window, x, y);
    x += 20;
    drawN(window, x, y);

    window.display();

    sf::sleep(sf::seconds(10));

}