//
// Created by ligas on 06.06.2023.
//

#include "Ball.h"


    void Ball::draw(sf::RenderTarget &target, sf::RenderStates state) const {
        target.draw(shape,state);
    }

    void Ball ::update() {
    shape.move(velocity);
    if (left() < 0){
        velocity.x = ballVelocity;
    }
    else if (right() > 800){
        velocity.x = -ballVelocity;
    }
    else if (top() < 0){
        velocity.y = ballVelocity;
    }
    else if (bottom() > 600){
        velocity.y = -ballVelocity;
    }

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

void Ball :: moveDown(){
    this -> velocity.y = -ballVelocity;
}

void Ball :: moveUp() {
    this -> velocity.y = ballVelocity;
}

void Ball ::moveRight() {
    this -> velocity.x = ballVelocity;
}

void Ball ::moveLeft() {
    this -> velocity.x = -ballVelocity;
}

sf::Vector2f Ball ::getPosition() {
    return shape.getPosition();
}




