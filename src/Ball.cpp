//
// Created by ligas on 06.06.2023.
//

#include "Ball.h"


    void Ball::draw(sf::RenderTarget &target, sf::RenderStates state) const {
        target.draw(shape,state);
    }

    void Ball ::update() {

    velocity.x = 0;
    velocity.y = 0;
    if (right() < 800 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) ){
        velocity.x = ballVelocity;
    }
    if (left() > 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) ){
        velocity.x = -ballVelocity;
    }
    if (top() > 0 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)){
        velocity.y = -ballVelocity;
    }
    if (bottom() < 600 && sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)){
        velocity.y = ballVelocity;
    }

    shape.move(velocity);

}
float Ball :: left(){
    return this -> shape.getPosition().x - shape.getRadius();
}

float Ball :: right(){
    return this -> shape.getPosition().x + shape.getRadius();
}

float Ball :: top(){
    return this -> shape.getPosition().y - shape.getRadius();
}

float Ball :: bottom(){
    return this -> shape.getPosition().y + shape.getRadius();
}


sf::Vector2f Ball ::getPosition() {
    return shape.getPosition();
}




