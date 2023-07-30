#include <iostream>
#include "Colission.h"
#include "Ball.h"
#include "Block.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


int main() {

    sf::RenderWindow window{sf::VideoMode(800, 600), "Arkanoid"};
    window.setFramerateLimit(60);
    Ball ball({199.f, 200.f}, 30.f);
    using Block = std::vector<Block>;
    Block m_blocks = {{50.f,  50.f,  100.f, 25.f},
                      {200.f, 50.f,  100.f, 25.f},
                      {350.f, 50.f,  100.f, 25.f},
                      {500.f, 50.f,  100.f, 25.f},
                      {650.f, 50.f,  100.f, 25.f},
                      {650.f, 100.f, 100.f, 25.f},
                      {500.f, 100.f, 100.f, 25.f},
                      {350.f, 100.f, 100.f, 25.f},
                      {200.f, 100.f, 100.f, 25.f},
                      {50.f, 100.f, 100.f, 25.f}};

    while (window.isOpen()) {
        window.clear(sf::Color::Black);
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            }

        }
        ball.update();
        window.draw(ball);
        for (auto &m_block: m_blocks) {
            window.draw(m_block);
            if (!Colission::isColliding(m_block.getVertices(), {ball.getPosition(), ball.getRadius()})) {
                m_block.setNoCollisionColor();
            } else {
                m_block.setCollisionColor();
            }
        }


        window.display();


    }

}


