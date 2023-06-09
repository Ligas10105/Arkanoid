#include <iostream>
#include "Colission.h"
#include "Ball.h"
#include "Block.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>


int main() {

   sf::RenderWindow window{sf::VideoMode(800,600), "Arkanoid"};
   window.setFramerateLimit(60);
   Ball ball({20.f,30.f},30.f, {});
   Block block(100.f,100.f,50.f,50.f);

   while(window.isOpen()){
       window.clear(sf::Color::Black);
       sf::Event event{};
       while (window.pollEvent(event)) {
           if (event.type == sf::Event::Closed){
               window.close();
               break;
           }

       }
       ball.update();
       if (!Colission::isColliding(ball, block)) {
           block.setNoCollisionColor();
       } else {
           block.setCollisionColor();
       }


       window.draw(block);
       window.draw(ball);
       window.display();
   }

}
